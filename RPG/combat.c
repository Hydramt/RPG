#include "combat.h"
#include "RPG_Assets.h"
#include "RPG_Subfunctions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int combat(
    /**
     * @brief The Structure to contain the player character
     */
    World* const Game
) {

    /**
     * @brief The main variable that will allow the player to choose options
     */
    int player_choice,
        /**
         * @brief Check how many options are available to the player
         */
        dialog_check,
        /**
         * @brief For counting loops and iterations
         */
        count = 0,
        /**
         * @brief For counting how many spells the player has
         */
        magic_check = 0,
        /**
         * @brief For counting how many items the player has
         */
        item_check = 0,
        /**
         * @brief For checking if the hero has had a turn yet
         */
        battle_check = 0;

    // Determine number of items
    while (item_check == 0 && count != 10) {
        if (Game->Hero.item.item_id[count] == 0) {
            item_check = count;
        } else {
            count++;
        }
    }
    count = 0;

    // check the hero and the Enemy are alive
    while (Game->Hero.stats.hp > 0 && Game->Enemy.stats.hp > 0) {

        // Reset spell count for each combat turn
        magic_check = 0;

        // Determine number of spells
        while (magic_check == 0 && count != 10) {
            if (Game->Hero.spell.spell_id[count] == 0) {
                magic_check = count;
            } else {
                count++;
            }
        }
        magic_check = count;
        count = 0;

        /**
         * @brief Allows players to stay in menus if they mistype
         */
        int input_sticker = 1;

        printf("Choose an action\n");
        printf("1. Fight\n");
        printf("2. Magic\n");
        printf("3. Item\n");
        printf("4. Run\n");

        // Check if the enemy is alive
        if (Game->Enemy.stats.hp != 0) {
            // If it is the player makes a choice
            printf("Enter your choice: ");
            scanf("%d", &player_choice);
        }

        // If the player chose 1
        if (player_choice == 1) {
            // The player attacks and sets the enemy to retaliate
            Game->Hero.stats.temp_atk = Game->Hero.stats.atk;
            Game->Hero.stats.temp_def = Game->Hero.stats.def;
            battle_check = 1;
        }

        // If the player chose 2
        else if (player_choice == 2) {

            // Make Options for each Magic attack
            while (input_sticker == 1) {
                for (dialog_check = magic_check; dialog_check > 0;
                     dialog_check--) {
                    count++;
                    printf("%d. %s\n", count, spells(count - 1, 0, Game));
                }
                count++;
                // Add back option
                printf("%d. Back\n", count);

                // Allow the hero to make a choice
                printf("Enter your choice: ");
                scanf("%d", &player_choice);

                // Check if they chose back
                // If so allow them to leave the loop back to the main
                // battle menu
                if (player_choice == count) {
                    input_sticker = 0;
                }

                // Otherwise check if they used a spell
                // If they did cast it and allow the enemy to retaliate
                // Otherwise reset
                else if (player_choice > 0 && player_choice < count) {
                    printf(
                        "The Hero cast %s\n", spells(player_choice - 1, 0, Game)
                    );

                    // Put the hero's temp def to his actual defense
                    // Incase the hero uses a defense boosting spell
                    Game->Hero.stats.temp_def = Game->Hero.stats.def;

                    // Allow the enemy to retaliate
                    battle_check = 1;
                    // Cast the spell
                    spells(player_choice - 1, 1, Game);
                    // Allow the player to leave the menu
                    input_sticker = 0;
                }

                // If the player inputted a incorrect input return Invalid Input
                else {
                    printf("Invalid Input\n");
                }

                // Reset count
                count = 0;
            }
            input_sticker = 1;
        }

        else if (player_choice == 3) {

            // Make Options for each available item
            while (input_sticker == 1) {
                printf("Choose an item\n");
                for (dialog_check = item_check; dialog_check > 0;
                     dialog_check--) {
                    count++;
                    printf(
                        "%d. %s x %d\n",
                        count,
                        items(Game->Hero.item.item_id[count - 1], 0, Game),
                        Game->Hero.item.item_amount[count - 1]
                    );
                }

                // Check if out of items
                if (count == 0) {
                    printf("Test\n");
                    printf("No items left\n");
                    input_sticker = 0;
                    player_choice = 0;
                }
                // Otherwise
                else {
                    // Print Back before offering a choice
                    count++;
                    printf("%d. Back\n", count);
                    printf("Enter your choice: ");
                    scanf("%d", &player_choice);
                }

                // Check if they chose back
                // If so allow them to leave the loop back to the main
                // battle menu
                if (player_choice == count) {
                    input_sticker = 0;
                }
                // Otherwise check if it was a valid option
                // If it was print the item then use it up
                else if (player_choice > 0 && player_choice < count) {
                    count = 0;
                    printf(
                        "The Hero used a %s\n",
                        items(
                            Game->Hero.item.item_id[player_choice - 1], 0, Game
                        )
                    );

                    // Put the hero's temp def to his actual defense
                    // Incase the hero uses a defense boosting item
                    Game->Hero.stats.temp_def = Game->Hero.stats.def;
                    items(Game->Hero.item.item_id[player_choice - 1], 1, Game);

                    // If the choice is not in the last slot
                    // And the amount of items in it is 1
                    if ((player_choice != item_check) &&
                        (Game->Hero.item.item_amount[player_choice - 1] == 1)) {
                        // Move the items down one
                        for (int x = player_choice - 1; x < item_check; x++) {
                            Game->Hero.item.item_id[x] =
                                Game->Hero.item.item_id[x + 1];
                            Game->Hero.item.item_stackable[x] =
                                Game->Hero.item.item_stackable[x + 1];
                            Game->Hero.item.item_amount[x] =
                                Game->Hero.item.item_amount[x + 1];
                            count++;
                        }
                        // Erase the last item
                        Game->Hero.item.item_id[count] = 0;
                        Game->Hero.item.item_stackable[count] = 0;
                        Game->Hero.item.item_amount[count] = 0;
                        item_check--;
                    }

                    // Else if the item has one left and is in the last slot
                    else if (
                        Game->Hero.item.item_amount[player_choice - 1] == 1
                    ) {
                        // Erase it
                        Game->Hero.item.item_id[player_choice - 1] = 0;
                        Game->Hero.item.item_stackable[player_choice - 1] = 0;
                        Game->Hero.item.item_amount[player_choice - 1] = 0;
                        item_check--;
                    }

                    // Otherwise use one
                    else {
                        Game->Hero.item.item_amount[player_choice - 1]--;
                    }
                    // Allows player to leave
                    input_sticker = 0;
                    // Allows the enemy to retaliate
                    battle_check = 1;
                }

                // Reset count
                count = 0;
            }
            input_sticker = 1;
        }

        // If the player chose 4
        else if (player_choice == 4) {
            // They run away with cowardice
            return 0;
        }

        // If player enters an invalid choice
        else {
            printf("\nInvalid Choice! Please enter a number 1-4.\n\n");
        }

        // Check if the Hero attacked
        if (battle_check == 1) {
            // Set the enemy temp attack and temp defense
            // Equal to their actual atk and def
            Game->Enemy.stats.temp_atk = Game->Enemy.stats.atk;
            Game->Enemy.stats.temp_def = Game->Enemy.stats.def;

            // Apply buffs and debuffs
            buffs_debuffs(Game);

            // Apply Hero damage and effects
            damage_calculator(Game);

            // If they did and the Enemy is alive The Enemy attacks
            if (Game->Enemy.stats.hp > 0) {
                enemy_ai(Game);
            }
            // If the Enemy is dead play death message
            else {
                death(Game->Enemy.stats.enemy_type);
            }

            battle_check = 0;
            // Print known stats
            printf("Enemy Hp:%d\n", Game->Enemy.stats.hp);
            printf("Enemy Mp:%d\n", Game->Enemy.stats.mp);
            printf("Hero Hp:%d\n", Game->Hero.stats.hp);
            printf("Hero Mp:%d\n", Game->Hero.stats.mp);

            // Reset temporary stats
            Game->Hero.stats.temp_atk = 0;
            Game->Enemy.stats.temp_atk = 0;
            Game->Hero.stats.temp_def = 0;
            Game->Enemy.stats.temp_def = 0;
        }
    }
    if (Game->Hero.stats.hp > 0) {
        level_up(Game);
    }
    return 1;
}
