#include "RPG_Subfunctions.h"
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
    if (grab == 2) {
        printf("The Fire Wolf\n");
        printf("Str:7 Def:2\n");
        printf("Max Hp:80 Max Mp:50\n");
        printf("The Fire Wolf: A dangerous inhabitant\n");
        printf("of The Cave. The hotter it burns the\n");
        printf("stronger it is! Using chill may be\n");
        printf("helpful.\n");
    }
}

const char* spells(
    /**
     * @brief The spell being used
     */
    int spell,
    /**
     * @brief Whether or not you are calling the name or the effect
     */
    int description,
    /**
     * @brief The Structure to contain the player character
     */
    Player* const Hero,
    /**
     * @brief The Structure to contain the enemy
     */
    Opponent* const Enemy
) {
    // Checks list of spells for names and effects

    // Spell Name Check
    if (spell == 1) {
        if (description == 0) {
            return "Check";
        } else {
            // Drink 5 mana
            Hero->stats.mp = Hero->stats.mp - 5;
            check(Enemy->stats.enemy_type);
        }
    }

    // Spell Name Firebolt
    else if (spell == 2) {
        if (description == 0) {
            return "Firebolt";
        } else {
            // Deal 15 damage
            Hero->stats.temp_atk = 15;
            // Drink 10 mana
            Hero->stats.mp = Hero->stats.mp - 10;

            // 33% chance to burn for 3 turns
            if (rand() % 3 > 1) {
                Enemy->debuff.burn = Enemy->debuff.burn + 3;
            }
        }
    }

    // Spell Name Stone Skin
    else if (spell == 3) {
        if (description == 0) {
            return "Stone Skin";
        } else {
            // Get Stone Skin for 4 turns
            Hero->buff.stone_skin = Hero->buff.stone_skin + 4;
            // Drink 20 mana
            Hero->stats.mp = Hero->stats.mp - 20;
        }
    }

    // Spell Name Poison Shot
    else if (spell == 4) {
        if (description == 0) {
            return "Poison Shot";
        } else {
            // Deal 5 damage
            Hero->stats.temp_atk = 5;
            // Drink 10 mana
            Hero->stats.mp = Hero->stats.mp - 10;

            // Applies 3 poison
            Enemy->debuff.poison = Enemy->debuff.poison + 3;
        }
    } else if (spell == 5) {
        if (description == 0) {
            return "Ice Spray";
        }
        // Deal 5 damage
        Hero->stats.temp_atk = 5;
        // Drink 10 mana
        Hero->stats.mp = Hero->stats.mp - 15;

        // Apply 4 Chill
        Enemy->debuff.chill += 4;
    }
}
