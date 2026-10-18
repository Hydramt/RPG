#include "RPG_Assets.h"
#include "RPG_Subfunctions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int buffs_debuffs(Player* const Hero, Opponent* const Enemy) {

    // Hero buffs
    // If Hero has Stone Skin, apply Stone Skin (+3def)
    if (Hero->buff.stone_skin > 0) {
        printf("The Hero's skin was tough!\n");
        Hero->stats.temp_def = Hero->stats.temp_def + 3;
        // Decrease Buff by 1
        Hero->buff.stone_skin--;
    }
    // If Hero has Frenzy, apply Frenzy (x2dmg)
    if (Hero->buff.frenzy > 0) {
        printf("The Hero is in a Frenzy!\n");
        Hero->stats.temp_atk = Hero->stats.temp_atk * 2;
        // Decrease Buff by 1
        Hero->buff.frenzy--;
    }

    // Hero debuffs
    // If Hero has burn
    if (Hero->debuff.burn > 0) {
        // If Hero has any chill
        if (Hero->debuff.chill > 0) {

            // If Hero has more chill than burn
            if (Hero->debuff.chill > Hero->debuff.burn) {
                // Subtract burn from chill
                Hero->debuff.chill -= Hero->debuff.burn;
                Hero->debuff.burn = 0;
            }
            // If Hero has more burn then chill
            else if (Hero->debuff.chill < Hero->debuff.burn) {
                // Subtract chill from burn
                Hero->debuff.burn -= Hero->debuff.chill;
                Hero->debuff.chill = 0;
            }
            // If Hero has the same amount of burn and chill
            else {
                // Set burn and chill to zero
                Hero->debuff.burn = 0;
                Hero->debuff.chill = 0;
            }
        }
        if (Hero->debuff.burn > 0) {
            // Apply burn (-5hp x0.75dmg)
            printf("The Hero was burned!\n");
            Hero->stats.temp_atk = Hero->stats.temp_atk * 0.75;
            Hero->stats.hp = Hero->stats.hp - 5;
            // Decrease Debuff by 1
            Hero->debuff.burn--;
        }
    }
    // If Hero has chill, apply chill (*0.5dmg)
    if (Hero->debuff.chill > 0) {
        printf("The Hero was chill\n");
        Hero->stats.temp_atk = Hero->stats.temp_atk * 0.5;
        // Decrease Debuff by 1
        Hero->debuff.chill--;
    }
    // If Hero has poison, apply poison (-10hp)
    if (Hero->debuff.poison > 0) {
        printf("The Hero was poisoned!\n");
        Hero->stats.hp = Hero->stats.hp - Hero->debuff.poison;
        // Decrease Debuff by 1
        Hero->debuff.poison--;
    }

    // Monster buffs
    // if Monster has Stone Skin, apply Stone Skin (+3def)
    if (Enemy->buff.stone_skin > 0) {
        printf("The Monster's skin was tough!\n");
        Enemy->stats.temp_def = Enemy->stats.temp_def + 3;
        // Decrease Buff by 1
        Enemy->buff.stone_skin--;
    }
    // if Monster has Frenzy, apply Frenzy (x2dmg)
    if (Enemy->buff.frenzy > 0) {
        printf("The Monster is in a Frenzy!\n");
        Enemy->stats.temp_atk = Enemy->stats.temp_atk * 2;
        // Decrease Buff by 1
        Enemy->buff.frenzy--;
    }

    // Monster debuffs
    // Check if Monster has burn
    if (Enemy->debuff.burn > 0) {
        // If Enemy has any chill
        if (Enemy->debuff.chill > 0) {

            // If Enemy has more chill than burn
            if (Enemy->debuff.chill > Enemy->debuff.burn) {
                // Subtract burn from chill
                Enemy->debuff.chill -= Enemy->debuff.burn;
                Enemy->debuff.burn = 0;
            }
            // If Enemy has more burn then chill
            else if (Enemy->debuff.chill < Enemy->debuff.burn) {
                // Subtract chill from burn
                Enemy->debuff.burn -= Enemy->debuff.chill;
                Enemy->debuff.chill = 0;
            }
            // If Enemy has the same amount of burn and chill
            else {
                // Set burn and chill to zero
                Enemy->debuff.burn = 0;
                Enemy->debuff.chill = 0;
            }
        }
        // if Monster has burn absorb (+5 x1.5dmg)
        if (Enemy->gimmick.burn_absorb == 1) {
            printf("Monster absorbed the fire!\n");
            Enemy->stats.temp_atk = Enemy->stats.temp_atk * 1.5;
            Enemy->stats.hp = Enemy->stats.hp + 5;
            // Decrease Debuff by 1
            Enemy->debuff.burn--;
        }
        // if Monster has burn, apply burn (-5hp x0.75dmg)
        else {
            printf("Monster was burned!\n");
            Enemy->stats.temp_atk = Enemy->stats.temp_atk * 0.75;
            Enemy->stats.hp = Enemy->stats.hp - 5;
            // Decrease Debuff by 1
            Enemy->debuff.burn--;
        }
    }
    // If Hero has chill, apply chill (*0.5dmg)
    if (Enemy->debuff.chill > 0) {
        printf("The Enemy was chilled\n");
        Enemy->stats.temp_atk = Enemy->stats.temp_atk * 0.5;
        // Decrease Debuff by 1
        Enemy->debuff.chill--;
    }
    // if Monster has poison, apply poison (hp-poison)
    if (Enemy->debuff.poison > 0) {
        printf("Monster was poisoned!\n");
        Enemy->stats.hp = Enemy->stats.hp - Enemy->debuff.poison;
        // Decrease Debuff by 1
        Enemy->debuff.poison--;
    }
}
