#include "RPG_Assets.h"
#include "RPG_Subfunctions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int buffs_debuffs(
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

    // Hero buffs
    // if Hero has Stone Skin, apply Stone Skin (+3def)
    if (Hero[1][0] > 0) {
        printf("The Hero's skin was tough!\n");
        Hero[0][7] = Hero[0][7] + 3;
    }
    // if Hero has Frenzy, apply Frenzy (x2dmg)
    if (Hero[1][1] > 0) {
        printf("The Hero is in a Frenzy!\n");
        Hero[0][6] = Hero[0][6] * 2;
    }

    // Hero debuffs
    // if Hero has burn, apply burn (-5hp x0.75dmg)
    if (Hero[2][0] > 0) {
        printf("The Hero was burned!\n");
        Hero[0][6] = Hero[0][6] * 0.75;
        Hero[0][0] = Hero[0][0] - 5;
    }
    // if Hero has poison, apply poison (-10hp)
    if (Hero[2][1] > 0) {
        printf("The Hero was poisoned!\n");
        Hero[0][0] = Hero[0][0] - Hero[2][1];
    }

    // Monster buffs
    // if Monster has Stone Skin, apply Stone Skin (+3def)
    if (Monster[1][0] > 0) {
        printf("The Monster's skin was tough!\n");
        Monster[0][7] = Monster[0][7] + 3;
    }
    // if Monster has Frenzy, apply Frenzy (x2dmg)
    if (Monster[1][1] > 0) {
        printf("The Monster is in a Frenzy!\n");
        Monster[0][6] = Monster[0][6] * 2;
    }

    // Monster debuffs
    // Check if Monster has burn
    if (Monster[2][0] > 0) {
        // if Monster has burn absorb (+5 x1.5dmg)
        if (Monster[3][0] == 1) {
            printf("Monster absorbed the fire!\n");
            Monster[0][6] = Monster[0][6] * 1.5;
            Monster[0][0] = Monster[0][0] + 5;
        }
        // if Monster has burn, apply burn (-5hp x0.75dmg)
        else {
            printf("Monster was burned!\n");
            Monster[0][6] = Monster[0][6] * 0.75;
            Monster[0][0] = Monster[0][0] - 5;
        }
    }
    // if Monster has poison, apply poison (-10hp)
    if (Monster[2][1] > 0) {
        printf("Monster was poisoned!\n");
        Monster[0][0] = Monster[0][0] - Monster[2][1];
    }

    // Deincrement buffs and debuffs by 1
    for (int i = 0; i < 10; i++) {
        if (Hero[1][i] > 0) {
            Hero[1][i]--;
        }
        if (Hero[2][i] > 0) {
            Hero[2][i]--;
        }
        if (Monster[1][i] > 0) {
            Monster[1][i]--;
        }
        if (Monster[2][i] > 0) {
            Monster[2][i]--;
        }
    }
}
