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
    World* const Game
) {
    /**
     * @brief How much exp the monster gives
     */
    int reward = 0;

    switch (Game->Enemy.stats.enemy_type) {
        // Mad Bunny
        case 1:
            return 10;
            break;
        // Fire Wolf (Boss)
        case 2:
            return 50;
            break;
        // Slime (8 exp for each Slime)
        case 3:
            return 8 * (Game->Enemy.stats.max_hp / 20);
            break;
        // Icy Stag
        case 4:
            return 30;
            break;
    }

    return reward;
}

int level_up(
    /**
     * @brief The Structure to contain the player character
     */
    World* const Game
) {
    /**
     * @brief For checking if the Hero leveled up
     */
    int leveled = 0;

    // If the Hero is already max level don't give exp
    if (Game->Hero.stats.lvl >= 25) {
        printf("The hero is already max level\n");
        return 0;
    }

    // Give the Hero exp for the monster
    Game->Hero.stats.exp = Game->Hero.stats.exp + exp_reward(Game);
    printf("The Hero gained %d Exp\n", exp_reward(Game));

    // While the Hero has enough exp and isn't max level
    while (Game->Hero.stats.exp >= exp_needed(Game->Hero.stats.lvl) &&
           Game->Hero.stats.lvl < 25) {
        // Use up the exp and go up a level
        Game->Hero.stats.exp =
            Game->Hero.stats.exp - exp_needed(Game->Hero.stats.lvl);
        Game->Hero.stats.lvl++;
        leveled = 1;

        // Increase stats (+10 max hp, +5 max mp, +1 atk)
        Game->Hero.stats.max_hp = Game->Hero.stats.max_hp + 10;
        Game->Hero.stats.max_mp = Game->Hero.stats.max_mp + 5;
        Game->Hero.stats.atk = Game->Hero.stats.atk + 1;

        // Every 2 levels increase def by 1
        if (Game->Hero.stats.lvl % 2 == 0) {
            Game->Hero.stats.def++;
        }

        printf("Level up! The Hero is now Lvl %d\n", Game->Hero.stats.lvl);
    }

    // If the Hero leveled up restore their hp and mp
    if (leveled == 1) {
        Game->Hero.stats.hp = Game->Hero.stats.max_hp;
        Game->Hero.stats.mp = Game->Hero.stats.max_mp;
        printf("The Hero's Hp and Mp were fully restored!\n");
    }

    // If the Hero hit max level throw away leftover exp
    if (Game->Hero.stats.lvl >= 25) {
        Game->Hero.stats.exp = 0;
        printf("The Hero reached max level!\n");
    }
    // Otherwise print how much exp is left
    else {
        printf(
            "Exp: %d/%d\n",
            Game->Hero.stats.exp,
            exp_needed(Game->Hero.stats.lvl)
        );
    }

    return leveled;
}
