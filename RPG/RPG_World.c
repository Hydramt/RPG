/**
 * @file RPG_World.c
 * @author Aniel Serrano
 * @brief Handles the RPG open world
 * @version 0.1
 * @date 2026-10-21
 */

#include "RPG_World.h"
#include "RPG_Subfunctions.h"
#include <stdio.h>
#include "RPG_Assets.h"
#include "quest.h"

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
    printf("5. Buy Spell Scroll\n");
    printf("0. Leave Shop\n");
    printf("Choose an option: ");
}

/**
 * @brief Lets the player buy items.
 */
void buyShopItem(Player* const Hero, int itemID, int price) {

    // Check if the player has enough gold
    if (Hero->stats.gold < price) {
        printf("You do not have enough gold!\n");
        return;
    }

    // Check if the player already owns the item
    for (int i = 0; i < 10; i++) {
        if (Hero->item.item_id[i] == itemID &&
            Hero->item.item_stackable[i] == 1) {

            Hero->item.item_amount[i]++;

            Hero->stats.gold = Hero->stats.gold - price;

            printf("Purchase successful!\n");
            printf("Gold remaining: %d\n", Hero->stats.gold);
            return;
        }
    }

    // Find an empty inventory slot
    for (int i = 0; i < 10; i++) {
        if (Hero->item.item_id[i] == 0) {
            Hero->item.item_id[i] = itemID;
            Hero->item.item_amount[i] = 1;
            Hero->item.item_stackable[i] = 1;

            Hero->stats.gold = Hero->stats.gold - price;

            printf("Purchase successful!\n");
            printf("Gold remaining: %d\n", Hero->stats.gold);
            return;
        }
    }

    printf("Your inventory is full!\n");
}

/**
 * @brief Lets the player use the village shop.
 */
void visitShop(Player* const Hero) {
    int shopChoice = -1;

    // Keep the shop open until the player leaves
    while (shopChoice != 0) {
        showShopMenu();

        printf("Current Gold: %d\n", Hero->stats.gold);
        scanf("%d", &shopChoice);

        if (shopChoice == 1) {
            buyShopItem(Hero, 1, 10);
        } else if (shopChoice == 2) {
            buyShopItem(Hero, 2, 10);
        } else if (shopChoice == 3) {
            buyShopItem(Hero, 3, 20);
        } else if (shopChoice == 4) {
            buyShopItem(Hero, 4, 50);
        } else if (shopChoice == 5) {
            buyShopItem(Hero, 5, 200);
        } else if (shopChoice == 5) {
            buyShopItem(Hero, 6, 200);
        } else if (shopChoice == 5) {
            buyShopItem(Hero, 7, 200);
        } else if (shopChoice == 5) {
            buyShopItem(Hero, 8, 50);
        } else if (shopChoice == 5) {
            buyShopItem(Hero, 9, 200);
        } else if (shopChoice == 5) {
            buyShopItem(Hero, 10, 200);
        } else if (shopChoice == 5) {
            buyShopItem(Hero, 11, 200);
        } else if (shopChoice == 5) {
            buyShopItem(Hero, 12, 200);
        } else if (shopChoice == 5) {
            buyShopItem(Hero, 13, 200);
        } else if (shopChoice == 5) {
            buyShopItem(Hero, 14, 200);
        } else if (shopChoice == 5) {
            buyShopItem(Hero, 15, 200);
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
void visitVillage(Player* const Hero) {
    int villageChoice = -1;

    printf("Welcome to the Village!\n");

    // Keep showing the village menu until the player leaves
    while (villageChoice != 0) {
        showVillageMenu();

        scanf("%d", &villageChoice);

        if (villageChoice == 1) {
            // Restore the player's HP and MP
            Hero->stats.hp = Hero->stats.max_hp;
            Hero->stats.mp = Hero->stats.max_mp;

            printf("You rested at the Village!\n");
            printf("Your HP and MP have been fully restored!\n");
        } else if (villageChoice == 2) {
            visitShop(Hero);
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
void visitCave(Player* Hero, Opponent* Enemy) {
    printf("\nYou have entered the Cave!\n");

    // First battle: First Slime
    printf("A Slime appears!\n");
    
    // Shows First Slime artwork
    assets(6);
    
    monster(Enemy, 3);
    int result = combat(Hero, Enemy, 0);

    // Stop if the player runs away or loses
    if (result == 0 || Hero->stats.hp <= 0 || Enemy->stats.hp > 0) {
        return;
    }

    // Second battle: Second Slimes
    printf("\nYou've encounter 2 slimes and it's blocking your path!\n");
    
    // Shows Second Slimes artwork 
    assets(7);
   
    monster(Enemy, 4);
    result = combat(Hero, Enemy, 0);

    if (result == 0 || Hero->stats.hp <= 0 || Enemy->stats.hp > 0) {
        return;
    }

    // Final battle: Fire Wolf boss
    printf("\nThe Fire Wolf boss appears!\n");
    
    // Shows Fire Wolf artwork
    assets(4);
   
    monster(Enemy, 2);
    result = combat(Hero, Enemy, 0);

    if (result != 0 && Hero->stats.hp > 0 && Enemy->stats.hp <= 0) {
        printf("\nYou defeated the Fire Wolf! Cave is cleared!\n");

        // Complete the quest if the player accepted it
        if (QuestLog[0].state == Quest_Active) {
            completeQuest(1, &Hero->stats.gold, QuestLog);
        }
    }
}


/**
 * @brief Starts a Mad Bunny battle in the forest
 */
void visitForest(Player* Hero, Opponent* Enemy) {
    printf("\nYou have entered the Forest!\n");
    printf("You've encountered a Mad Bunny!\n");

    // Shows the Mad Bunny artwork
    assets(1);

    // Set the enemy and start combat
    monster(Enemy, 1);
    combat(Hero, Enemy, 0);
}

/**
 * @brief Lets the player explore the open world.
 */
void playerWorld(Player* Hero, Opponent* Enemy) {

    int choice = -1;

    // Load the quests when the game starts
    initQuest(QuestLog);

    // Keep showing the world menu until the player exits
    while (choice != 0) {
        showWorldMenu();

        choice = getWorldChoice();

        if (choice == 1) {
            // Pass the player's stats and items to the village
            visitVillage(Hero);
        } 
        else if (choice == 2) {
            visitForest(Hero, Enemy);
            // Check if the player lost the Forest battle
            if (Hero->stats.hp <= 0) {
                printf("\nYou have been defeated!\n");
                printf("You wake up at the Village Inn.\n");

                // Restore HP and MP
                Hero->stats.hp = Hero->stats.max_hp;
                Hero->stats.mp = Hero->stats.max_mp;

                printf("Your HP and MP have been restored!\n");
            }

        } else if (choice == 3) {
            visitCave(Hero, Enemy);
            // Check if the player lost the Cave battle
            if (Hero->stats.hp <= 0) {
                printf("\nYou have been defeated!\n");
                printf("You wake up at the Village Inn.\n");

                // Restore HP and MP
                Hero->stats.hp = Hero->stats.max_hp;
                Hero->stats.mp = Hero->stats.max_mp;

                printf("Your HP and MP have been restored!\n");
            }
    }
}
}