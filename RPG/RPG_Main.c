#include "RPG_Assets.h"
#include "RPG_Subfunctions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int combat(
    /**
     * @brief The Hero as a 2d array
     *
     * @param 0 Stats 0-hp 1-maxhp 2-mp 3-maxmp 4-atk 5-def 6-tempatk 7-tempdef
     * 8-lvl 9-exp
     * @param 1 Buffs 0-Stone_Skin 1-Frenzy
     * @param 2 Debuffs 0-Burn 1-Poison
     * @param 3 Spells
     * @param 4 Items
     */
    int Hero[6][10],
    /**
     * @brief The Monster as a 2d array
     *
     * @param 0 Stats 0-hp 1-maxhp 2-mp 3-maxmp 4-atk 5-def 6-tempatk 7-tempdef
     * 8-Montype
     * @param 1 Buff Storage 0-Stone_Skin 1-Frenzy
     * @param 2 Debuff Storage 0-Burn 1-Poison
     * @param 3 Gimmicks 0-Burn_Heal 1-Poison_Heal
     */
    int Monster[4][10],
    /**
     * @brief Tells if you run away
     */
    int cowardice
) {

    /**
     * @brief The main function that will allow the player to choose options
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

    // Determine number of spells before combat starts
    while (magic_check == 0) {
        if (Hero[3][count] == 0) {
            magic_check = count;
        } else {
            count++;
        }
    }
    count = 0;

    // Determine number of items before combat starts
    while (item_check == 0) {
        if (Hero[4][count] == 0) {
            item_check = count;
        } else {
            count++;
        }
    }
    count = 0;

    // check the hero and the monster are alive
    while (Hero[0][0] > 0 && Monster[0][0] > 0) {

        /**
         * @brief Allows players to stay in menus if they mistype
         */
        int input_sticker = 1;

        printf("Choose an action\n");
        printf("1. Fight\n");
        printf("2. Magic\n");
        printf("3. Item\n");
        printf("4. Run\n");

        if (Monster[0][8] != 0) {
            scanf("%d", &player_choice);
        }

        if (player_choice == 1) {
            Hero[0][6] = Hero[0][4];
            battle_check = 1;
        } else if (player_choice == 2) {

            // Make Options for each Magic attack
            while (input_sticker == 1) {
                for (dialog_check = magic_check; dialog_check > 0;
                     dialog_check--) {
                    count++;
                    printf(
                        "%d. %s\n",
                        count,
                        spells(Hero[3][count - 1], 0, Hero, Monster)
                    );
                }
                count++;
                printf("%d. Back\n", count);
                scanf("%d", &player_choice);

                // Check if they chose back
                // If so allow them to leave the loop back to the main
                // battle menu
                if (player_choice == count) {
                    input_sticker = 0;
                }
                // Other wise check if they used a spell
                // If they did cast it and engage the battle calculator
                // Otherwise reset
                else if (player_choice > 0 && player_choice < count) {
                    printf(
                        "The Hero cast %s\n",
                        spells(Hero[3][player_choice - 1], 0, Hero, Monster)
                    );
                    spells(Hero[3][player_choice - 1], 1, Hero, Monster);
                    battle_check = 1;
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
            // Call the Monster AI to retaliate
        } else if (player_choice == 3) {

            // Make Options for each available item
            while (input_sticker == 1) {
                printf("Choose an item\n");
                for (dialog_check = item_check; dialog_check > 0;
                     dialog_check--) {
                    count++;
                    printf(
                        "%d. %s\n",
                        count,
                        items(Hero[4][count - 1], 0, Hero, Monster)
                    );
                }

                // Check if out of items
                if (count == 0) {
                    printf("No items left\n");
                    input_sticker = 0;
                    player_choice = 0;
                }
                // Otherwise
                else {
                    // Print Back before offering a choice
                    count++;
                    printf("%d. Back\n", count);
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
                        items(Hero[4][player_choice - 1], 0, Hero, Monster)
                    );
                    items(Hero[4][player_choice - 1], 1, Hero, Monster);

                    // Make all the Items above the used one slide down a
                    // slot
                    if (player_choice != item_check) {
                        for (int x = player_choice - 1; x < item_check; x++) {
                            Hero[4][x] = Hero[4][x + 1];
                            count++;
                        }
                        Hero[4][count] = 0;
                    } else {
                        Hero[4][player_choice - 1] = 0;
                    }
                    // Then set the last one to 0 (Empty)
                    item_check--;
                    // Allows player to leave
                    input_sticker = 0;
                    // Allows the enemy to retaliate
                    battle_check = 1;
                }

                // Reset count
                count = 0;
            }
            input_sticker = 1;
        } else if (player_choice == 4) {
            // no random chance during testing
            cowardice = 1;
            Monster[0][0] = 0;
        }

        // Check if the Hero attacked
        if (battle_check == 1) {
            Monster[0][6] = Monster[0][4];
            Monster[0][7] = Monster[0][5];
            Hero[0][7] = Hero[0][5];
            // Apply buffs and debuffs
            buffs_debuffs(Hero, Monster);
            damage_calculator(Hero, Monster);
            // If they did and the monster is alive The Monster attacks
            if (Monster[0][0] > 0) {
                monster_ai(Hero, Monster);
            }
            // If the monster is dead play death message
            else {
                death(Monster[0][8]);
                battle_check = 0;
            }

            // If the monster is dead play death message
            if (Monster[0][0] <= 0 && battle_check == 1) {
                death(Monster[0][8]);
            }
            battle_check = 0;
            // Print known stats
            printf("Monster Hp:%d\n", Monster[0][0]);
            printf("Monster Mp:%d\n", Monster[0][2]);
            printf("Hero Hp:%d\n", Hero[0][0]);
            printf("Hero Mp:%d\n", Hero[0][2]);
            Hero[0][6] = 0;
            Monster[0][6] = 0;
            Hero[0][7] = 0;
            Monster[0][7] = 0;
        }
    }
}

int main(void) {

    // Set player stats
    /**
     * @brief The Hero as a 2d array
     *
     * @param 0 Stats 0-hp 1-maxhp 2-mp 3-maxmp 4-atk 5-def 6-tempatk 7-tempdef
     * 8-lvl 9-exp
     * @param 1 Buffs 0-Stone_Skin 1-Frenzy
     * @param 2 Debuffs 0-Burn 1-Poison
     * @param 3 Spells
     * @param 4 Items
     */
    int Hero[6][10] = {
        {100, 100, 100, 100, 5, 1, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
        // Starting Spells(Check, Firebolt, Stone_Skin, Poison_Shot)
        // Starting Items(Hp_Potion, Hp_Potion, Mana Potion, Ice_Bomb)
        {1, 2, 3, 4, 0, 0},
        {1, 1, 2, 3, 0, 0}
    };

    // Set Monster stats
    /**
     * @brief The Monster as a 2d array
     *
     * @param 0 Stats 0-hp 1-maxhp 2-mp 3-maxmp 4-atk 5-def 6-tempatk 7-tempdef
     * 8-Montype
     * @param 1 Buff Storage 0-Stone_Skin 1-Frenzy
     * @param 2 Debuff Storage 0-Burn 1-Poison
     * @param 3 Gimmicks 0-Burn_Heal 1-Poison_Heal
     */
    int Monster[4][10] = {
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}
    };

    // Set win condition
    int win = 0;
    while (win == 0) {
        // Set random
        srand(time(NULL));

        // the main function that will allow the player to choose options
        int player_choice;

        // function that tells if you ran away
        int cowardice = 0;

        printf("Choose your difficulty\n");
        printf("1. Easy\n");
        printf("2. Medium\n");
        printf("3. Hard\n");
        scanf("%d", &player_choice);

        if (player_choice == 1) {
            // Set Monster Hp and Max Hp
            Monster[0][0] = 40;
            Monster[0][1] = 40;
            // Set Monster Mp and Max Mp
            Monster[0][2] = 40;
            Monster[0][3] = 40;
            // Set Monster atk
            Monster[0][4] = 3;
            // Set Monster def
            Monster[0][5] = 0;
            // Set Monster type (Mad Bunny)
            Monster[0][8] = 1;
        } else if (player_choice == 2) {
            // Set Monster Hp and Max Hp
            Monster[0][0] = 80;
            Monster[0][1] = 80;
            // Set Monster Mp and Max Mp
            Monster[0][2] = 50;
            Monster[0][3] = 50;
            // Set Monster atk
            Monster[0][4] = 7;
            // Set Monster def
            Monster[0][5] = 2;
            // Set Monster type (Fire Wolf)
            Monster[0][8] = 2;
            Monster[4][0] = 1;
        } else if (player_choice == 3) {
            printf("Not implemented yet\n");
        } else {
            printf("Incorrect input\n");
            printf("Please try again\n");
        }

        // Monster intro message
        if (Monster[0][8] == 1) {
            printf("The Mad Bunny attacks!\n");
            assets(1);
        }

        // The combat loop
        combat(Hero, Monster, cowardice);

        // if you killed the Monster and didn't run away you win!
        if (Monster[0][0] <= 0 && cowardice > 0) {
            win = 1;
        }
    }
}
