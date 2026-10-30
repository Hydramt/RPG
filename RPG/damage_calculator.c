#include "RPG_Assets.h"
#include "RPG_Subfunctions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int damage_calculator(
    /**
     * @brief The Structure to contain the player character
     */
    Player* const Hero,
    /**
     * @brief The Structure to contain the enemy
     */
    Opponent* const Enemy
) {
    // Hero calculations
    // If Hero didn't do any damage, do nothing

    // If the hero did negative damage heal
    if (Hero->stats.temp_atk < 0) {
        Hero->stats.hp = Hero->stats.hp - Hero->stats.temp_atk;
        if (Hero->stats.hp > Hero->stats.max_hp) {
            Hero->stats.hp = Hero->stats.max_hp;
            printf("The Hero restored their hp to Max\n");
        } else {
            printf("Hero healed themselves for %dHp\n", -Hero->stats.temp_atk);
        }
    }
    // Else if Hero's attack is exactly 0
    else if (Hero->stats.temp_atk == 0) {
        // Empty case for spells :D
    }
    // If Hero did less damage than the enemies defense then deal one damage
    else if (Enemy->stats.temp_def > Hero->stats.temp_atk) {
        printf("Hero dealt 1 damage\n");
        Enemy->stats.hp = Enemy->stats.hp - 1;
    }
    // Otherwise calculate and print damage normally
    // (Hero temp attack - Enemy temp defense)
    else {
        printf(
            "Hero dealt %d damage\n",
            (Hero->stats.temp_atk - Enemy->stats.temp_def)
        );
        Enemy->stats.hp =
            Enemy->stats.hp - Hero->stats.temp_atk + Enemy->stats.temp_def;
    }

    return 0;
}
