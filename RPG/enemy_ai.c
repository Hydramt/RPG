#include "RPG_Assets.h"
#include "RPG_Subfunctions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int monster_ai(
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
    int Hero[6][10],
    /**
     * @brief The Monster as a 2d array
     *
     * @param 0 Stats 0-hp 1-maxhp 2-mp 3-maxmp 4-atk 5-def 6-tempatk 7-tempdef
     * 8-Montype
     * @param 1 Buff Storage 0-Stone_Skin 1-Frenzy
     * @param 2 Debuff Storage 0-Burn 1-Poison
     * @param 3 Gimmicks 0-Burn_Heal 1-Poison_Heal
     */
    int Monster[4][10]
) {

    // Mad Bunny AI
    if (Monster[0][8] == 1) {
        // The Bunny makes a random choice between 1 abd 4
        int decision = (rand() % 4) + 1;
        // If Bunny is at half health and has 20 mana, it burns it to enter a
        // Frenzy
        if ((Monster[0][0] <= (Monster[0][1] / 2)) && Monster[0][2] >= 20) {
            printf("Mad Bunny entered a Frenzy!");
            Monster[1][1] = 5;
            Monster[0][2] = 0;
            Monster[0][6] = 0;
        }
        // Otherwise it checks if it is in a rage, and if it isn't
        // And it rolled a 4 it lollygags instead of anything else
        else if (decision == 4 && Monster[1][1] <= 0) {
            printf("Mad Bunny lollygags");
            Monster[0][6] = 0;
        }
        // Then if it is in a rage it headbutts hard
        else if (Monster[1][1] > 0) {
            printf("Mad Bunny headbutts hard");
        }
        // If it is not in a rage it just headbutts regularly
        else {
            printf("Mad Bunny headbutts");
        }
    }

    // Monster calculations
    // If Monster didn't do any damage
    if (Monster[0][6] <= 0) {
        printf("\n");
    }
    // If Monster did less damage than the Hero's defense then deal one damage
    else if (Monster[0][6] < Hero[0][8]) {
        printf(" for 1 damage\n");
        Hero[0][0] = Hero[0][0] - 1;
    }
    // Otherwise calculate and print damage normally
    // (Monster attack - Hero defense)
    else {
        printf(" for %d damage\n", (Monster[0][6] - Hero[0][7]));
        Hero[0][0] = Hero[0][0] - Monster[0][6] + Hero[0][7];
    }
    // Check if it is a bunny if so make bunny pictures
    if (Monster[0][8] == 1) {
        // If bunny is in a rage print rage bunny
        if (Monster[1][1] > 0) {
            assets(2);
        }
        // Otherwise it prints regular bunny
        else {
            assets(1);
        }
    }
}
