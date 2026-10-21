/**
 * @file monster.c
 * @author Gavin O.
 * @brief Sets Monster's Stats
 * @version 0.1
 * @date 2026-10-21
 *
 * @copyright Copyright (c) 2026
 *
 */

#include "RPG_Subfunctions.h"
#include <stdio.h>

void monster(
    /**
     * @brief The Structure to contain the enemy
     */
    Opponent* const Enemy,
    /**
     * @brief Which enemy it sets to
     */
    int grab
) {
    if (grab == 1) {
        // Set Enemy Stats
        Enemy->stats.hp = 40;
        Enemy->stats.max_hp = 40;
        Enemy->stats.mp = 20;
        Enemy->stats.max_mp = 20;
        Enemy->stats.atk = 3;
        Enemy->stats.def = 0;
        Enemy->stats.temp_atk = 0;
        Enemy->stats.temp_def = 0;
        // Set Enemy Type (Mad Bunny)
        Enemy->stats.enemy_type = 1;
    } else if (grab == 2) {
        // Set Enemy Stats
        Enemy->stats.hp = 80;
        Enemy->stats.max_hp = 80;
        Enemy->stats.mp = 50;
        Enemy->stats.max_mp = 50;
        Enemy->stats.atk = 7;
        Enemy->stats.def = 2;
        Enemy->stats.temp_atk = 0;
        Enemy->stats.temp_def = 0;
        // Set Enemy Type (Fire Wolf)
        Enemy->stats.enemy_type = 2;
        // Set Fire Wolf Gimmick (Burn Absorb)
        Enemy->gimmick.burn_absorb = 1;
    }
}
