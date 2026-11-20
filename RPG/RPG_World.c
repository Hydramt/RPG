/**
 * @file RPG_World.c
 * @author Aniel Serrano
 * @brief Handles the RPG open world
 * @version 0.1
 * @date 2026-10-21
 */

#include "RPG_World.h"
#include "RPG_Assets.h"
#include "RPG_Subfunctions.h"
#include "quest.h"
#include <stdio.h>

// Stores the player's quests and their progress
Quest QuestLog[Max_Quest] = {0};

/**
 * @brief Show the world menu.
 */
void showWorldMenu(void) {
    printf("\n=== WORLD MENU ===\n");
    printf("1. Village\n");
    printf("2. Forest\n");
    printf("3. Cave\n");
    printf("0. Exit Game\n");
    printf("Choose a location: ");
}

/**
 * @brief Gets the player's location choice.
 * @return The number the players enters
 */
int getWorldChoice(void) {
    int choice;

    scanf("%d", &choice);

    return choice;
}

/**
 * @brief Shows the village options.
 */
void showVillageMenu(void) {
    printf("\n=== VILLAGE MENU ===\n");
    printf("1. Rest\n");
    printf("2. Shop\n");
    printf("3. Quest Board\n");
    printf("0. Leave Village\n");
    printf("Choose an option: ");
}

/**
 * @brief Shows the shop menu.
 */
void showShopMenu(void) {
    printf("\n=== VILLAGE SHOP ===\n");
    printf("1. Buy HP Potion - 10 Gold\n");
    printf("2. Buy MP Potion - 10 Gold\n");
    printf("3. Buy Ice Flask - 20 Gold\n");
    printf("4. Buy Cleansing Potion - 50 Gold\n");
    printf("5. Buy Spell Scroll: Check - 200 Gold\n");
    printf("6. Buy Spell Scroll: FireBolt - 200 Gold\n");
    printf("7. Buy Spell Scroll: Stone Skin - 200 Gold\n");
    printf("8. Buy Spell Scroll: Poison Shot - 200 Gold\n");
    printf("9. Buy Spell Scroll: Icy Spray - 200 Gold\n");
    printf("10. Buy Spell Scroll: Inner Fire - 200 Gold\n");
    printf("11. Buy Spell Scroll: Slime Shot - 200 Gold\n");
    printf("12. Buy Spell Scroll: Magic Missile - 200 Gold\n");
    printf("13. Buy Spell Scroll: Heal - 200 Gold\n");
    printf("0. Leave Shop\n");
    printf("Choose an option: ");
}

/**
 * @brief Lets the player buy items.
 */
void buyShopItem(World* const Game, int itemID, int price) {

    // Check if the player has enough gold
    if (Game->Hero.stats.gold < price) {
        printf("You do not have enough gold!\n");
        return;
    }

    // Check if the player already owns the item
    for (int i = 0; i < 10; i++) {
        if (Game->Hero.item.item_id[i] == itemID &&
            Game->Hero.item.item_stackable[i] == 1) {

            Game->Hero.item.item_amount[i]++;

            Game->Hero.stats.gold = Game->Hero.stats.gold - price;

            printf("Purchase successful!\n");
            printf("Gold remaining: %d\n", Game->Hero.stats.gold);
            return;
        }
    }

    // Find an empty inventory slot
    for (int i = 0; i < 10; i++) {
        if (Game->Hero.item.item_id[i] == 0) {
            Game->Hero.item.item_id[i] = itemID;
            Game->Hero.item.item_id[i + 1] = 0;
            Game->Hero.item.item_amount[i] = 1;
            Game->Hero.item.item_stackable[i] = 1;

            Game->Hero.stats.gold = Game->Hero.stats.gold - price;

            printf("Purchase successful!\n");
            printf("Gold remaining: %d\n", Game->Hero.stats.gold);
            return;
        }
    }

    printf("Your inventory is full!\n");
}

/**
 * @brief Lets the player use the village shop.
 */
void visitShop(World* const Game) {
    int shopChoice = -1;

    // Keep the shop open until the player leaves
    while (shopChoice != 0) {
        showShopMenu();

        printf("Current Gold: %d\n", Game->Hero.stats.gold);
        scanf("%d", &shopChoice);

        if (shopChoice == 1) {
            buyShopItem(Game, 1, 10);
        } else if (shopChoice == 2) {
            buyShopItem(Game, 2, 10);
        } else if (shopChoice == 3) {
            buyShopItem(Game, 3, 20);
        } else if (shopChoice == 4) {
            buyShopItem(Game, 4, 50);
        } else if (shopChoice == 5) {
            buyShopItem(Game, 5, 200);
        } else if (shopChoice == 6) {
            buyShopItem(Game, 6, 200);
        } else if (shopChoice == 7) {
            buyShopItem(Game, 7, 200);
        } else if (shopChoice == 8) {
            buyShopItem(Game, 8, 50);
        } else if (shopChoice == 9) {
            buyShopItem(Game, 9, 200);
        } else if (shopChoice == 10) {
            buyShopItem(Game, 10, 200);
        } else if (shopChoice == 11) {
            buyShopItem(Game, 11, 200);
        } else if (shopChoice == 12) {
            buyShopItem(Game, 12, 200);
        } else if (shopChoice == 13) {
            buyShopItem(Game, 13, 200);
        } else if (shopChoice == 0) {
            printf("You left the Shop.\n");
        } else {
            printf("Invalid shop option.\n");
        }
    }
}

/**
 * @brief Lets the player check the quest board.
 */
void visitQuestBoard(void) {
    int questChoice;

    printf("\n=== QUEST BOARD ===\n");
    printf("1. Accept Slay Fire Wolf Quest\n");
    printf("0. Back\n");
    printf("Choose an option: ");

    scanf("%d", &questChoice);

    // Accept the fire wolf quest
    if (questChoice == 1) {
        acceptQuest(1, QuestLog);

    } else if (questChoice == 0) {
        printf("You left the Quest Board.\n");
    } else {
        printf("Invalid quest option.\n");
    }
}

/**
 * @brief Lets the player visit the village
 */
void visitVillage(World* const Game) {
    int villageChoice = -1;

    printf("Welcome to the Village!\n");

    // Keep showing the village menu until the player leaves
    while (villageChoice != 0) {
        showVillageMenu();

        scanf("%d", &villageChoice);

        if (villageChoice == 1) {
            // Restore the player's HP and MP
            Game->Hero.stats.hp = Game->Hero.stats.max_hp;
            Game->Hero.stats.mp = Game->Hero.stats.max_mp;

            printf("You rested at the Village!\n");
            printf("Your HP and MP have been fully restored!\n");
        } else if (villageChoice == 2) {
            visitShop(Game);
        } else if (villageChoice == 3) {
            visitQuestBoard();
        } else if (villageChoice == 0) {
            printf("You left the village.\n");
        } else {
            printf("Invalid village option.\n");
        }
    }
}

/**
 * @brief Lets the player fight Slimes before the Fire Wolf boss
 */
void visitCave(World* Game) {
    printf("\nYou have entered the Cave!\n");

    // First battle: First Slime
    printf("A Slime appears!\n");

    // Shows First Slime artwork
    assets(6);

    monster(Game, 3);
    int result = combat(Game);

    // Stop if the player runs away or loses
    if (result == 0 || Game->Hero.stats.hp <= 0 || Game->Enemy.stats.hp > 0) {
        return;
    }

    // Second battle: Second Slimes
    printf("\nYou've encounter 2 slimes and it's blocking your path!\n");

    // Shows Second Slimes artwork
    assets(7);

    monster(Game, 4);
    result = combat(Game);

    if (result == 0 || Game->Hero.stats.hp <= 0 || Game->Enemy.stats.hp > 0) {
        return;
    }

    // Final battle: Fire Wolf boss
    printf("\nThe Fire Wolf boss appears!\n");

    // Shows Fire Wolf artwork
    assets(4);

    monster(Game, 2);
    result = combat(Game);

    if (result != 0 && Game->Hero.stats.hp > 0 && Game->Enemy.stats.hp <= 0) {
        printf("\nYou defeated the Fire Wolf! Cave is cleared!\n");

        // Complete the quest if the player accepted it
        if (QuestLog[0].state == Quest_Active) {
            completeQuest(1, &Game->Hero.stats.gold, QuestLog);
        }
    }
}

/**
 * @brief Starts a Mad Bunny battle in the forest
 */
void visitForest(World* Game) {
    printf("\nYou have entered the Forest!\n");
    printf("You've encountered a Mad Bunny!\n");

    // Shows the Mad Bunny artwork
    assets(1);

    // Set the enemy and start combat
    monster(Game, 1);
    combat(Game);
}

/**
 * @brief Lets the player explore the open world.
 */
void playerWorld(World* Game) {

    int choice = -1;

    // Load the quests when the game starts
    initQuest(QuestLog);

    // Keep showing the world menu until the player exits
    while (choice != 0) {
        showWorldMenu();

        choice = getWorldChoice();

        if (choice == 1) {
            // Pass the player's stats and items to the village
            visitVillage(Game);
        } else if (choice == 2) {
            visitForest(Game);
            // Check if the player lost the Forest battle
            if (Game->Hero.stats.hp <= 0) {
                printf("\nYou have been defeated!\n");
                printf("You wake up at the Village Inn.\n");

                // Restore HP and MP
                Game->Hero.stats.hp = Game->Hero.stats.max_hp;
                Game->Hero.stats.mp = Game->Hero.stats.max_mp;

                printf("Your HP and MP have been restored!\n");
            }

        } else if (choice == 3) {
            visitCave(Game);
            // Check if the player lost the Cave battle
            if (Game->Hero.stats.hp <= 0) {
                printf("\nYou have been defeated!\n");
                printf("You wake up at the Village Inn.\n");

                // Restore HP and MP
                Game->Hero.stats.hp = Game->Hero.stats.max_hp;
                Game->Hero.stats.mp = Game->Hero.stats.max_mp;

                printf("Your HP and MP have been restored!\n");
            }
        }
    }
}
