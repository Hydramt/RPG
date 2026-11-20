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
    World* const Game,
    /**
     * @brief Which enemy it sets to
     */
    int grab
) {
    // Set Enemy's Buffs/Debuffs starting at 0
    Game->Enemy.buff.stone_skin = 0;
    Game->Enemy.buff.iron_skin = 0;
    Game->Enemy.buff.frenzy = 0;
    Game->Enemy.buff.cleanse = 0;
    Game->Enemy.debuff.burn = 0;
    Game->Enemy.debuff.poison = 0;
    Game->Enemy.debuff.chill = 0;
    Game->Enemy.debuff.slime = 0;
    // Set Gimmicks to 0
    Game->Enemy.gimmick.burn_absorb = 0;
    Game->Enemy.gimmick.poison_heal = 0;
    Game->Enemy.gimmick.multiply = 0;
    if (grab == 1) {
        // Set Enemy Stats
        Game->Enemy.stats.hp = 40;
        Game->Enemy.stats.max_hp = 40;
        Game->Enemy.stats.mp = 20;
        Game->Enemy.stats.max_mp = 20;
        Game->Enemy.stats.atk = 3;
        Game->Enemy.stats.def = 0;
        Game->Enemy.stats.temp_atk = 0;
        Game->Enemy.stats.temp_def = 0;
        // Set Enemy Type (Mad Bunny)
        Game->Enemy.stats.enemy_type = 1;
    } else if (grab == 2) {
        // Set Enemy Stats
        Game->Enemy.stats.hp = 80;
        Game->Enemy.stats.max_hp = 80;
        Game->Enemy.stats.mp = 50;
        Game->Enemy.stats.max_mp = 50;
        Game->Enemy.stats.atk = 7;
        Game->Enemy.stats.def = 2;
        Game->Enemy.stats.temp_atk = 0;
        Game->Enemy.stats.temp_def = 0;
        // Set Enemy Type (Fire Wolf)
        Game->Enemy.stats.enemy_type = 2;
        // Set Fire Wolf Gimmick (Burn Absorb)
        Game->Enemy.gimmick.burn_absorb = 1;
    } else if (grab == 3) {
        // Set Enemy Stats
        Game->Enemy.stats.hp = 20;
        Game->Enemy.stats.max_hp = 20;
        Game->Enemy.stats.mp = 0;
        Game->Enemy.stats.max_mp = 0;
        Game->Enemy.stats.atk = 4;
        Game->Enemy.stats.def = 4;
        Game->Enemy.stats.temp_atk = 0;
        Game->Enemy.stats.temp_def = 0;
        // Set Enemy Type (Slime)
        Game->Enemy.stats.enemy_type = 3;
        // Set Slime Gimmick (Multiply)
        Game->Enemy.gimmick.multiply = 1;
    } else if (grab == 4) {
        // Set Enemy Stats
        Game->Enemy.stats.hp = 40;
        Game->Enemy.stats.max_hp = 40;
        Game->Enemy.stats.mp = 0;
        Game->Enemy.stats.max_mp = 0;
        Game->Enemy.stats.atk = 4;
        Game->Enemy.stats.def = 4;
        Game->Enemy.stats.temp_atk = 0;
        Game->Enemy.stats.temp_def = 0;
        // Set Enemy Type (2 Slimes)
        Game->Enemy.stats.enemy_type = 3;
        // Set Slime Gimmick (Multiply)
        Game->Enemy.gimmick.multiply = 2;
    } else if (grab == 5) {
        // Set Enemy Stats
        Game->Enemy.stats.hp = 60;
        Game->Enemy.stats.max_hp = 60;
        Game->Enemy.stats.mp = 100;
        Game->Enemy.stats.max_mp = 100;
        Game->Enemy.stats.atk = 6;
        Game->Enemy.stats.def = 3;
        Game->Enemy.stats.temp_atk = 0;
        Game->Enemy.stats.temp_def = 0;
        // Set Enemy Type Icy Stag
        Game->Enemy.stats.enemy_type = 4;
    } else if (grab == 6) {
        // Set Enemy Stats
        Game->Enemy.stats.hp = 60;
        Game->Enemy.stats.max_hp = 60;
        Game->Enemy.stats.mp = 0;
        Game->Enemy.stats.max_mp = 0;
        Game->Enemy.stats.atk = 4;
        Game->Enemy.stats.def = 4;
        Game->Enemy.stats.temp_atk = 0;
        Game->Enemy.stats.temp_def = 0;
        // Set Enemy Type (3 Slimes)
        Game->Enemy.stats.enemy_type = 3;
        // Set Slime Gimmick (Multiply)
        Game->Enemy.gimmick.multiply = 3;
    }
}
