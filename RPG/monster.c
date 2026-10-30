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
    // Set Enemy's Buffs/Debuffs starting at 0
    Enemy->buff.stone_skin = 0;
    Enemy->buff.iron_skin = 0;
    Enemy->buff.frenzy = 0;
    Enemy->buff.cleanse = 0;
    Enemy->debuff.burn = 0;
    Enemy->debuff.poison = 0;
    Enemy->debuff.chill = 0;
    Enemy->debuff.slime = 0;
    // Set Gimmicks to 0
    Enemy->gimmick.burn_absorb = 0;
    Enemy->gimmick.poison_heal = 0;
    Enemy->gimmick.multiply = 0;
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
    } else if (grab == 3) {
        // Set Enemy Stats
        Enemy->stats.hp = 20;
        Enemy->stats.max_hp = 20;
        Enemy->stats.mp = 0;
        Enemy->stats.max_mp = 0;
        Enemy->stats.atk = 4;
        Enemy->stats.def = 4;
        Enemy->stats.temp_atk = 0;
        Enemy->stats.temp_def = 0;
        // Set Enemy Type (Slime)
        Enemy->stats.enemy_type = 3;
        // Set Slime Gimmick (Multiply)
        Enemy->gimmick.multiply = 1;
    } else if (grab == 4) {
        // Set Enemy Stats
        Enemy->stats.hp = 40;
        Enemy->stats.max_hp = 40;
        Enemy->stats.mp = 0;
        Enemy->stats.max_mp = 0;
        Enemy->stats.atk = 4;
        Enemy->stats.def = 4;
        Enemy->stats.temp_atk = 0;
        Enemy->stats.temp_def = 0;
        // Set Enemy Type (2 Slimes)
        Enemy->stats.enemy_type = 3;
        // Set Slime Gimmick (Multiply)
        Enemy->gimmick.multiply = 2;
    } else if (grab == 5) {
        // Set Enemy Stats
        Enemy->stats.hp = 60;
        Enemy->stats.max_hp = 60;
        Enemy->stats.mp = 100;
        Enemy->stats.max_mp = 100;
        Enemy->stats.atk = 6;
        Enemy->stats.def = 3;
        Enemy->stats.temp_atk = 0;
        Enemy->stats.temp_def = 0;
        // Set Enemy Type Icy Stag
        Enemy->stats.enemy_type = 4;
    } else if (grab == 6) {
        // Set Enemy Stats
        Enemy->stats.hp = 60;
        Enemy->stats.max_hp = 60;
        Enemy->stats.mp = 0;
        Enemy->stats.max_mp = 0;
        Enemy->stats.atk = 4;
        Enemy->stats.def = 4;
        Enemy->stats.temp_atk = 0;
        Enemy->stats.temp_def = 0;
        // Set Enemy Type (3 Slimes)
        Enemy->stats.enemy_type = 3;
        // Set Slime Gimmick (Multiply)
        Enemy->gimmick.multiply = 3;
    }
}
