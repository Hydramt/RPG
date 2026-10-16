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
}

const char* spells(
    int spell, int description,
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
    Player* const Hero, Opponent* const Enemy
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
            // Deal 10 damage
            Hero->stats.temp_atk = 10;
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
    }
}
