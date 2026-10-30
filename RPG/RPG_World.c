/**
 * @file RPG_World.c
 * @author Aniel Serrano
 * @brief Handles the RPG open world
 * @version 0.1
 * @date 2026-10-21
 */

#include "RPG_World.h"
#include <stdio.h>

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
void buyShopItem(
    int* gold, int itemIDs[], int itemAmounts[], int itemStackable[],
    int itemID, int price
) {

    // Check if the player has enough gold
    if (*gold < price) {
        printf("You do not have enough gold!\n");
        return;
    }

    // Check if the player already owns the item
    for (int i = 0; i < 10; i++) {
        if (itemIDs[i] == itemID && itemStackable[i] == 1) {

            itemAmounts[i]++;

            *gold = *gold - price;

            printf("Purchase successful!\n");
            printf("Gold remaining: %d\n", *gold);
            return;
        }
    }

    // Find an empty inventory slot
    for (int i = 0; i < 10; i++) {
        if (itemIDs[i] == 0) {
            itemIDs[i] = itemID;
            itemAmounts[i] = 1;
            itemStackable[i] = 1;

            *gold = *gold - price;

            printf("Purchase successful!\n");
            printf("Gold remaining: %d\n", *gold);
            return;
        }
    }

    printf("Your inventory is full!\n");
}

/**
 * @brief Lets the player use the village shop.
 */
void visitShop(
    int* gold, int itemIDs[], int itemAmounts[], int itemStackable[]
) {
    int shopChoice = -1;

    // Keep the shop open until the player leaves
    while (shopChoice != 0) {
        showShopMenu();

        printf("Current Gold: %d\n", *gold);
        scanf("%d", &shopChoice);

        if (shopChoice == 1) {
            buyShopItem(gold, itemIDs, itemAmounts, itemStackable, 1, 10);
        } else if (shopChoice == 2) {
            buyShopItem(gold, itemIDs, itemAmounts, itemStackable, 2, 10);
        } else if (shopChoice == 3) {
            buyShopItem(gold, itemIDs, itemAmounts, itemStackable, 3, 20);
        } else if (shopChoice == 4) {
            buyShopItem(gold, itemIDs, itemAmounts, itemStackable, 4, 50);
        } else if (shopChoice == 5) {
            printf("Spell Scrolls are coming soon!\n");
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
    // Quests will be added later
    printf("\n=== QUEST BOARD ===\n");
    printf("The Quest Board is being prepared.\n");
}

/**
 * @brief Lets the player visit the village
 */
void visitVillage(
    int* hp, int maxHp, int* mp, int maxMp, int* gold, int itemIDs[],
    int itemAmounts[], int itemStackable[]
) {
    int villageChoice = -1;

    printf("Welcome to the Village!\n");

    // Keep showing the village menu until the player leaves
    while (villageChoice != 0) {
        showVillageMenu();

        scanf("%d", &villageChoice);

        if (villageChoice == 1) {
            // Restore the player's HP and MP
            *hp = maxHp;
            *mp = maxMp;

            printf("You rested at the Village!\n");
            printf("Your HP and MP have been fully restored!\n");
        } else if (villageChoice == 2) {
            visitShop(gold, itemIDs, itemAmounts, itemStackable);
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
 * @brief Starts a Fire Wolf battle in the cave
 */
void visitCave(Player* Hero, Opponent* Enemy) {
    printf("\nYou have entered the Cave!\n");
    printf("You've encountered a Fire Wolf!\n");

    // Set the enemy and start combat
    monster(Enemy, 2);
    combat(Hero, Enemy, 0);
}

/**
 * @brief Starts a Mad Bunny battle in the forest
 */
void visitForest(Player* Hero, Opponent* Enemy) {
    printf("\nYou have entered the Forest!\n");
    printf("You've encountered a Mad Bunny!\n");

    // Set the enemy and start combat
    monster(Enemy, 1);
    combat(Hero, Enemy, 0);
}

/**
 * @brief Lets the player explore the open world.
 */
void playerWorld(Player* Hero, Opponent* Enemy) {

    int choice = -1;

    // Keep showing the world menu until the player exits
    while (choice != 0) {
        showWorldMenu();

        choice = getWorldChoice();

        if (choice == 1) {
            // Pass the player's stats and items to the village
            visitVillage(
                &Hero->stats.hp,
                Hero->stats.max_hp,
                &Hero->stats.mp,
                Hero->stats.max_mp,
                &Hero->stats.gold,
                Hero->item.item_id,
                Hero->item.item_amount,
                Hero->item.item_stackable
            );
        } else if (choice == 2) {
            visitForest(Hero, Enemy);
        } else if (choice == 3) {
            visitCave(Hero, Enemy);
        } else if (choice == 0) {
            printf("Thanks for playing!\n");
        } else {
            printf("Invalid choice. Try again.\n");
        }
    }
}
