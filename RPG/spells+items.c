/**
 * @file spells+items.c
 * @author Gavin O.
 * @brief Contains the spell and item info for the player
 * @version 0.1
 * @date 2026-10-09
 *
 * @copyright Copyright (c) 2026
 *
 */
#include "RPG_Battle_Subfunctions.h"
#include "RPG_Spells+Items.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int check(int grab) {
    if (grab == 1) {
        printf("The Mad Bunny\n");
        printf("Str:3 Def:0\n");
        printf("Max Hp:40 Max Mp:20\n");
        printf("The Mad Bunny: A beginner enemy.\n");
        printf("Beware, at half health it enters\n");
        printf("a frenzy.\n");
    }
}

const char*
spells(int spell, int description, int Hero[6][10], int Monster[4][10]) {
    // Checks list of spells for names and effects

    // Spell Name Check
    if (spell == 1) {
        if (description == 0) {
            return "Check";
        } else {
            // Drink 5 mana
            Hero[0][2] = Hero[0][2] - 5;
            check(Monster[0][8]);
            damage_calculator(Hero, Monster);
        }
    }

    // Spell Name Firebolt
    else if (spell == 2) {
        if (description == 0) {
            return "Firebolt";
        } else {
            // Deal 10 damage
            Hero[0][6] = 10;
            // Drink 10 mana
            Hero[0][2] = Hero[0][2] - 10;

            // 33% chance to burn for 3 turns
            if (rand() % 3 > 1) {
                Monster[2][0] = Monster[2][0] + 3;
            }

            // Battle
            damage_calculator(Hero, Monster);
        }
    }

    // Spell Name Stone Skin
    else if (spell == 3) {
        if (description == 0) {
            return "Stone Skin";
        } else {
            // Get Stone Skin for 4 turns
            Hero[1][0] = Hero[1][0] + 4;
            // Drink 20 mana
            Hero[0][2] = Hero[0][2] - 20;

            // Battle
            damage_calculator(Hero, Monster);
        }
    }

    // Spell Name Poison Shot
    else if (spell == 4) {
        if (description == 0) {
            return "Poison Shot";
        } else {
            // Deal 5 damage
            Hero[0][6] = 5;
            // Drink 10 mana
            Hero[0][2] = Hero[0][2] - 10;

            // Applies 3 poison
            Monster[2][1] = Monster[2][1] + 3;

            // Battle
            damage_calculator(Hero, Monster);
        }
    }
}

const char*
items(int item, int description, int Hero[6][10], int Monster[4][10]) {
    // Checks list of spells for names and effects

    // Item Name Hp Potion
    if (item == 1) {
        if (description == 0) {
            return "Hp Potion";
        } else {
            Hero[0][6] = -20;
            damage_calculator(Hero, Monster);
        }

    }

    // Item Name Mp Potion
    else if (item == 2) {
        if (description == 0) {
            return "Mp Potion";
        } else {
            Hero[0][2] = Hero[0][2] + 20;
            if (Hero[0][2] > Hero[0][3]) {
                Hero[0][2] = Hero[0][3];
                printf("The Hero restored their Mp to Max\n");
            } else {
                printf("The Hero restored 20Mp\n");
            }
            damage_calculator(Hero, Monster);
        }
    }

    // Item Name Ice Potion
    else if (item == 3) {
        if (description == 0) {
            return "Ice Potion";
        } else {
            Hero[0][6] = 15;
            damage_calculator(Hero, Monster);
        }
    }
}
