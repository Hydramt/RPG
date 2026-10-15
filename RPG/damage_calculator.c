#include "RPG_Assets.h"
#include "RPG_Subfunctions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int damage_calculator(
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
    // Hero calculations
    // If Hero didn't do any damage, do nothing

    // If the hero did negative damage heal
    if (Hero[0][6] < 0) {
        Hero[0][0] = Hero[0][0] - Hero[0][6];
        if (Hero[0][0] > Hero[0][1]) {
            Hero[0][0] = Hero[0][1];
            printf("The Hero restored their hp to Max\n");
        } else {
            printf("Hero healed themselves for %dHp\n", -Hero[0][6]);
        }
    }
    // If Hero did less damage than the enemies defense then deal one damage
    else if (Monster[0][7] > Hero[0][6]) {
        printf("Hero dealt 1 damage\n");
        Monster[0][0] = Monster[0][0] - 1;
    }
    // Otherwise calculate and print damage normally (Hero attack- Monster
    // defense)
    else {
        printf("Hero dealt %d damage\n", (Hero[0][6] - Monster[0][7]));
        Monster[0][0] = Monster[0][0] - Hero[0][6] + Monster[0][7];
    }

    return 0;
}
