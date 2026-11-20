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
    World* const Game
) {
    // Hero calculations
    // If Hero didn't do any damage, do nothing

    // If the hero did negative damage heal
    if (Game->Hero.stats.temp_atk < 0) {
        Game->Hero.stats.hp = Game->Hero.stats.hp - Game->Hero.stats.temp_atk;
        if (Game->Hero.stats.hp > Game->Hero.stats.max_hp) {
            Game->Hero.stats.hp = Game->Hero.stats.max_hp;
            printf("The Hero restored their hp to Max\n");
        } else {
            printf(
                "Hero healed themselves for %dHp\n", -Game->Hero.stats.temp_atk
            );
        }
    }
    // Else if Hero's attack is exactly 0
    else if (Game->Hero.stats.temp_atk == 0) {
        // Empty case for spells :D
    }
    // If Hero did less damage than the enemies defense then deal one damage
    else if (Game->Enemy.stats.temp_def > Game->Hero.stats.temp_atk) {
        printf("Hero dealt 1 damage\n");
        Game->Enemy.stats.hp = Game->Enemy.stats.hp - 1;
    }
    // Otherwise calculate and print damage normally
    // (Hero temp attack - Enemy temp defense)
    else {
        printf(
            "Hero dealt %d damage\n",
            (Game->Hero.stats.temp_atk - Game->Enemy.stats.temp_def)
        );
        Game->Enemy.stats.hp = Game->Enemy.stats.hp -
                               Game->Hero.stats.temp_atk +
                               Game->Enemy.stats.temp_def;
    }

    return 0;
}
