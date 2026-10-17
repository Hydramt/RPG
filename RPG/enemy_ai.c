#include "RPG_Assets.h"
#include "RPG_Subfunctions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int enemy_ai(
    /**
     * @brief The Structure to contain the player character
     */
    Player* const Hero,
    /**
     * @brief The Structure to contain the enemy
     */
    Opponent* const Enemy
) {

    // Mad Bunny AI
    if (Enemy->stats.enemy_type == 1) {
        // The Bunny makes a random choice between 1 abd 4
        int decision = (rand() % 4) + 1;
        // If Bunny is at half health and has 20 mana
        // It burns 20 mp to enter a Frenzy
        if ((Enemy->stats.hp <= (Enemy->stats.max_hp / 2)) &&
            Enemy->stats.mp >= 20) {
            printf("Mad Bunny entered a Frenzy!");
            Enemy->buff.frenzy = 5;
            Enemy->stats.mp = 0;
            Enemy->stats.temp_atk = 0;
        }
        // Otherwise it checks if it is in a rage, and if it isn't
        // And it rolled a 4 it lollygags instead of anything else
        else if (decision == 4 && Enemy->buff.frenzy <= 0) {
            printf("Mad Bunny lollygags");
            Enemy->stats.temp_atk = 0;
        }
        // Then if it is in a rage it headbutts hard
        else if (Enemy->buff.frenzy > 0) {
            printf("Mad Bunny headbutts hard");
        }
        // If it is not in a rage it just headbutts regularly
        else {
            printf("Mad Bunny headbutts");
        }
    }

    // Enemy calculations
    // If Enemy didn't do any damage
    if (Enemy->stats.temp_atk <= 0) {
        printf("\n");
    }
    // If Enemy did less damage than the Hero's defense then deal one damage
    else if (Enemy->stats.temp_atk < Hero->stats.temp_def) {
        printf(" for 1 damage\n");
        Hero->stats.hp = Hero->stats.hp - 1;
    }
    // Otherwise calculate and print damage normally
    // (Enemy attack - Hero defense)
    else {
        printf(
            " for %d damage\n", (Enemy->stats.temp_atk - Hero->stats.temp_def)
        );
        Hero->stats.hp =
            Hero->stats.hp - Enemy->stats.temp_atk + Hero->stats.temp_def;
    }
    // Check if it is a bunny if so make bunny pictures
    if (Enemy->stats.enemy_type == 1) {
        // If bunny is in a rage print rage bunny
        if (Enemy->buff.frenzy > 0) {
            assets(2);
        }
        // Otherwise it prints regular bunny
        else {
            assets(1);
        }
    }
}
