#include "RPG_Assets.h"
#include "RPG_Battle_Subfunctions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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

    Monster[0][6] = Monster[0][4];
    Monster[0][7] = Monster[0][5];
    Hero[0][7] = Hero[0][5];
    // Apply Buffs/Debuffs
    buffs_debuffs(Hero, Monster);

    // Hero calculations
    // If Hero didn't do any damage, do nothing
    // If the hero did - damage heal
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

    // Decide for Monster's
    if (Monster[0][0] > 0) {
        monster_ai(Hero, Monster);
    } else {
        death(Monster[0][8]);
    }

    // Print known stats
    printf("Monster Hp:%d\n", Monster[0][0]);
    printf("Monster Mp:%d\n", Monster[0][2]);
    printf("Hero Hp:%d\n", Hero[0][0]);
    printf("Hero Mp:%d\n", Hero[0][2]);
    Hero[0][6] = 0;
    Monster[0][6] = 0;
    Hero[0][7] = 0;
    Monster[0][7] = 0;

    return 0;
}
