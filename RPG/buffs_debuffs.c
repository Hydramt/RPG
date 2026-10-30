#include "RPG_Assets.h"
#include "RPG_Subfunctions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int buffs_debuffs(Player* const Hero, Opponent* const Enemy) {

    // If Hero has cleanse
    if (Hero->buff.cleanse > 0) {
        if (Hero->debuff.burn > 0) {
            Hero->debuff.burn--;
            Hero->buff.cleanse--;
            printf("The Hero's burn is reduced\n");
        }
        if (Hero->debuff.poison > 0) {
            Hero->debuff.poison--;
            Hero->buff.cleanse--;
            printf("The Hero's poison is reduced\n");
        }
        if (Hero->debuff.chill > 0) {
            Hero->debuff.chill--;
            Hero->buff.cleanse--;
            printf("The Hero's chill is reduced\n");
        }
        if (Hero->debuff.slime > 0) {
            Hero->debuff.slime--;
            Hero->buff.cleanse--;
            printf("The Hero's slime is reduced\n");
        }
    }

    // Hero buffs
    // If Hero has Stone Skin, apply Stone Skin (+3def)
    if (Hero->buff.stone_skin > 0) {
        printf("The Hero's skin was tough!\n");
        Hero->stats.temp_def = Hero->stats.temp_def + 3;
        // Decrease Buff by 1
        Hero->buff.stone_skin--;
    }
    // If Hero has Iron Skin, apply Iron Skin (*2def)
    if (Hero->buff.iron_skin > 0) {
        printf("The Hero's skin was tough!\n");
        Hero->stats.temp_def = Hero->stats.temp_def * 2;
        // Decrease Buff by 1
        Hero->buff.iron_skin--;
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

    // If Hero has negative mp
    if (Hero->stats.mp < 0) {
        // Eats Hero's hp
        Hero->stats.hp += (Hero->stats.mp * 1.5);
        // Resets mp
        Hero->stats.mp = 0;
        printf("The Hero experienced mana burn.\n");
    }

    // If Hero has slime, apply slime (-5, -10, -15 mp/hp)
    if (Hero->debuff.slime > 0) {
        // If The Hero is Moderately Slimed
        if (Hero->debuff.slime >= 5) {
            // If The Hero is Heavily Slimed
            if (Hero->debuff.slime >= 10) {
                // Decrease Debuff by 3
                Hero->debuff.slime -= 3;
                // Eat 15 Mana
                Hero->stats.mp -= 15;
                printf("The Hero was Heavily Slimed!\n");
            } else {
                // Decrease Debuff by 2
                Hero->debuff.slime -= 2;
                // Eat 10 Mana
                Hero->stats.mp -= 10;
                printf("The Hero was moderately Slimed!\n");
            }
        } else {
            // Decrease Debuff by 1
            Hero->debuff.slime--;
            // Eat 5 Mana
            Hero->stats.mp -= 5;
            printf("The Hero is coated in a thin layer of slime.\n");
        }
        // If Hero has negative mp
        if (Hero->stats.mp < 0) {
            // Eats Hero's hp
            Hero->stats.hp += Hero->stats.mp;
            // Resets mp
            Hero->stats.mp = 0;
            printf("The Slime ate through The Hero's hp.\n");
        } else {
            printf("The Slime ate through The Hero's mp.\n");
        }
    }

    // If Enemy has cleanse
    if (Enemy->buff.cleanse > 0) {
        if (Enemy->debuff.burn > 0) {
            Enemy->debuff.burn--;
            Enemy->buff.cleanse--;
            printf("The Enemy's burn is reduced\n");
        }
        if (Enemy->debuff.poison > 0) {
            Enemy->debuff.poison--;
            Enemy->buff.cleanse--;
            printf("The Enemy's poison is reduced\n");
        }
        if (Enemy->debuff.chill > 0) {
            Enemy->debuff.chill--;
            Enemy->buff.cleanse--;
            printf("The Enemy's chill is reduced\n");
        }
        if (Enemy->debuff.slime > 0) {
            Enemy->debuff.slime--;
            Enemy->buff.cleanse--;
            printf("The Enemy's slime is reduced\n");
        }
    }

    // Monster buffs
    // if Monster has Stone Skin, apply Stone Skin (+3def)
    if (Enemy->buff.stone_skin > 0) {
        printf("The Monster's skin was tough!\n");
        Enemy->stats.temp_def = Enemy->stats.temp_def + 3;
        // Decrease Buff by 1
        Enemy->buff.stone_skin--;
    }
    // if Monster has Iron Skin, apply Iron Skin (*2def)
    if (Enemy->buff.iron_skin > 0) {
        printf("The Monster's skin was tough!\n");
        Enemy->stats.temp_def = Enemy->stats.temp_def * 2;
        // Decrease Buff by 1
        Enemy->buff.iron_skin--;
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

    // If Enemy has negative mp
    if (Enemy->stats.mp < 0) {
        // Eats Enemy's hp
        Enemy->stats.hp += (Hero->stats.mp * 1.5);
        // Resets mp
        Enemy->stats.mp = 0;
        printf("The Enemy experienced mana burn.\n");
    }

    // If Enemy has slime, apply slime (-5, -10, -15 mp/hp)
    if (Enemy->debuff.slime > 0) {
        // If The Enemy is Moderately Slimed
        if (Enemy->debuff.slime >= 5) {
            // If The Enemy is Heavily Slimed
            if (Enemy->debuff.slime >= 10) {
                // Decrease Debuff by 3
                Enemy->debuff.slime -= 3;
                // Eat 15 Mana
                Enemy->stats.mp -= 15;
                printf("The Enemy was Heavily Slimed!\n");
            } else {
                // Decrease Debuff by 2
                Enemy->debuff.slime -= 2;
                // Eat 10 Mana
                Enemy->stats.mp -= 10;
                printf("The Enemy was moderately Slimed!\n");
            }
        } else {
            // Decrease Debuff by 1
            Enemy->debuff.slime--;
            // Eat 5 Mana
            Enemy->stats.mp -= 5;
            printf("The Enemy is coated in a thin layer of slime.\n");
        }
        // If Enemy has negative mp
        if (Enemy->stats.mp < 0) {
            // Eats Enemy's hp
            Enemy->stats.hp += Enemy->stats.mp;
            // Resets mp
            Enemy->stats.mp = 0;
            printf("The Slime ate through The Enemy's hp.\n");
        } else {
            printf("The Slime ate through The Enemy's mp.\n");
        }
    }
}
