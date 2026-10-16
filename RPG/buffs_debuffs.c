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
    Player* const Hero,
    /**
     * @brief The Monster as a 2d array
     *
     * @param 0 Stats 0-hp 1-maxhp 2-mp 3-maxmp 4-atk 5-def 6-tempatk 7-tempdef
     * 8-Montype
     * @param 1 Buff Storage 0-Stone_Skin 1-Frenzy
     * @param 2 Debuff Storage 0-Burn 1-Poison
     * @param 3 Gimmicks 0-Burn_Heal 1-Poison_Heal
     */
    Opponent* const Enemy
) {

    // Hero buffs
    // if Hero has Stone Skin, apply Stone Skin (+3def)
    if (Hero->buff.stone_skin > 0) {
        printf("The Hero's skin was tough!\n");
        Hero->stats.temp_def = Hero->stats.temp_def + 3;
    }
    // if Hero has Frenzy, apply Frenzy (x2dmg)
    if (Hero->buff.frenzy > 0) {
        printf("The Hero is in a Frenzy!\n");
        Hero->stats.temp_atk = Hero->stats.temp_atk * 2;
    }

    // Hero debuffs
    // if Hero has burn, apply burn (-5hp x0.75dmg)
    if (Hero->debuff.burn > 0) {
        printf("The Hero was burned!\n");
        Hero->stats.temp_atk = Hero->stats.temp_atk * 0.75;
        Hero->stats.hp = Hero->stats.hp - 5;
    }
    // if Hero has poison, apply poison (-10hp)
    if (Hero->debuff.poison > 0) {
        printf("The Hero was poisoned!\n");
        Hero->stats.hp = Hero->stats.hp - Hero->debuff.poison;
    }

    // Monster buffs
    // if Monster has Stone Skin, apply Stone Skin (+3def)
    if (Enemy->buff.stone_skin > 0) {
        printf("The Monster's skin was tough!\n");
        Enemy->stats.temp_def = Enemy->stats.temp_def + 3;
    }
    // if Monster has Frenzy, apply Frenzy (x2dmg)
    if (Enemy->buff.frenzy > 0) {
        printf("The Monster is in a Frenzy!\n");
        Enemy->stats.temp_atk = Enemy->stats.temp_atk * 2;
    }

    // Monster debuffs
    // Check if Monster has burn
    if (Enemy->debuff.burn > 0) {
        // if Monster has burn absorb (+5 x1.5dmg)
        if (Enemy->gimmick.burn_absorb == 1) {
            printf("Monster absorbed the fire!\n");
            Enemy->stats.temp_atk = Enemy->stats.temp_atk * 1.5;
            Enemy->stats.hp = Enemy->stats.hp + 5;
        }
        // if Monster has burn, apply burn (-5hp x0.75dmg)
        else {
            printf("Monster was burned!\n");
            Enemy->stats.temp_atk = Enemy->stats.temp_atk * 0.75;
            Enemy->stats.hp = Enemy->stats.hp - 5;
        }
    }
    // if Monster has poison, apply poison (-10hp)
    if (Enemy->debuff.poison > 0) {
        printf("Monster was poisoned!\n");
        Enemy->stats.hp = Enemy->stats.hp - Enemy->debuff.poison;
    }

    // Deincrement buffs and debuffs by 1

    // Hero Buffs/Debuffs
    if (Hero->buff.frenzy > 0) {
        Hero->buff.frenzy--;
    }
    if (Hero->buff.stone_skin > 0) {
        Hero->buff.stone_skin--;
    }
    if (Hero->debuff.burn > 0) {
        Hero->debuff.burn--;
    }
    if (Hero->debuff.poison > 0) {
        Hero->debuff.poison--;
    }

    // Enemy Buffs/Debuffs
    if (Enemy->buff.frenzy > 0) {
        Enemy->buff.frenzy--;
    }
    if (Enemy->buff.stone_skin > 0) {
        Enemy->buff.stone_skin--;
    }
    if (Enemy->debuff.burn > 0) {
        Enemy->debuff.burn--;
    }
    if (Enemy->debuff.poison > 0) {
        Enemy->debuff.poison--;
    }
}
