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
#include "RPG_Subfunctions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

const char* items(
    int item, int description,
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

    // Item Name Hp Potion
    if (item == 1) {
        if (description == 0) {
            return "Hp Potion";
        } else {
            Hero->stats.temp_atk = -20;
        }

    }

    // Item Name Mp Potion
    else if (item == 2) {
        if (description == 0) {
            return "Mp Potion";
        } else {
            Hero->stats.mp = Hero->stats.mp + 20;
            if (Hero->stats.mp > Hero->stats.max_mp) {
                Hero->stats.mp = Hero->stats.max_mp;
                printf("The Hero restored their Mp to Max\n");
            } else {
                printf("The Hero restored 20Mp\n");
            }
        }
    }

    // Item Name Ice Potion
    else if (item == 3) {
        if (description == 0) {
            return "Ice Potion";
        } else {
            Hero->stats.temp_atk = 15;
        }
    }
}
