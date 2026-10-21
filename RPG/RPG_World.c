#include <stdio.h>
#include "RPG_World.h"

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
    printf("0. Leave Village\n");
    printf("Choose an option: "); 
}

/**
 * @brief Lets the player visit the village
 */
void visitVillage(void) {
    int villageChoice = -1;

    printf("Welcome to the Village!\n");

    while (villageChoice != 0) {
        showVillageMenu();

        scanf("%d", &villageChoice);
        
        if (villageChoice == 1) {
            printf("You're resting.\n");
        }
        else if (villageChoice == 2) {
            printf("Welcome to the Village Shop!\n");
            printf("Healing potions are sold here.\n");
        }
        else if (villageChoice == 0) {
            printf("You left the village.\n");
        }
        else {
            printf("Invalid village option.\n");
        }

    }
}

/**
 * @brief Lets the player explore the cave.
 */
void visitCave(void) {
    printf("\nYou have entered the Cave!\n");
    printf("You've encountered a Fire Wolf!\n");
}

/**
 * @brief Lets player explore the forest
 */
void visitForest(void) {
    printf("\nYou have entered the Forest!\n");
    printf("You've encountered a Mad Bunny!\n");
}