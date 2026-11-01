/**
 * @file leveling.c
 * @author Malik A.
 * @brief Gives the Hero exp and levels them up
 * @version 0.1
 * @date 2026-10-27
 *
 * @copyright Copyright (c) 2026
 *
 */

#include "RPG_Subfunctions.h"
#include "leveling.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int exp_needed(
    /**
     * @brief The Hero's current level
     */
    int lvl
) {
    // each level needs 10 more exp than the last
    // Lvl 1 to 2 needs 10, Lvl 2 to 3 needs 20, etc.
    return lvl * 10;
}

int exp_reward(
    /**
     * @brief The Structure to contain the enemy
     */
    Opponent* const Enemy
) {
    /**
     * @brief How much exp the monster gives
     */
    int reward = 0;

    switch (Enemy->stats.enemy_type) {
        // Mad Bunny
        case 1:
            reward = 10;
            break;
        // Fire Wolf (Boss)
        case 2:
            reward = 50;
            break;
        // Slime (8 exp for each Slime)
        case 3:
            reward = 8 * (Enemy->stats.max_hp / 20);
            break;
        // Icy Stag
        case 4:
            reward = 30;
            break;
    }

    return reward;
}

int level_up(
    /**
     * @brief The Structure to contain the player character
     */
    Player* const Hero,
    /**
     * @brief The Structure to contain the enemy
     */
    Opponent* const Enemy
) {
    /**
     * @brief For checking if the Hero leveled up
     */
    int leveled = 0;

    // If the Hero is already max level don't give exp
    if (Hero->stats.lvl >= 25) {
        printf("The hero is already max level\n");
        return 0;
    }

    // Give the Hero exp for the monster
    Hero->stats.exp = Hero->stats.exp + exp_reward(Enemy);
    printf("The Hero gained %dExp\n", exp_reward(Enemy));

    // While the Hero has enough exp and isn't max level
    while (Hero->stats.exp >= exp_needed(Hero->stats.lvl) &&
           Hero->stats.lvl < 25) {
        // Use up the exp and go up a level
        Hero->stats.exp = Hero->stats.exp - exp_needed(Hero->stats.lvl);
        Hero->stats.lvl++;
        leveled = 1;

        // Increase stats (+10 max hp, +5 max mp, +1 atk)
        Hero->stats.max_hp = Hero->stats.max_hp + 10;
        Hero->stats.max_mp = Hero->stats.max_mp + 5;
        Hero->stats.atk = Hero->stats.atk + 1;

        // Every 2 levels increase def by 1
        if (Hero->stats.lvl % 2 == 0) {
            Hero->stats.def++;
        }

        printf("Level up! The Hero is now Lvl %d\n", Hero->stats.lvl);
    }

    // If the Hero leveled up restore their hp and mp
    if (leveled == 1) {
        Hero->stats.hp = Hero->stats.max_hp;
        Hero->stats.mp = Hero->stats.max_mp;
        printf("The Hero's Hp and Mp were fully restored!\n");
    }

    // If the Hero hit max level throw away leftover exp
    if (Hero->stats.lvl >= 25) {
        Hero->stats.exp = 0;
        printf("The Hero reached max level!\n");
    }
    // Otherwise print how much exp is left
    else {
        printf(
            "Exp: %d/%d\n", Hero->stats.exp, exp_needed(Hero->stats.lvl)
        );
    }

    return leveled;
}
