#include "RPG_Assets.h"
#include "RPG_Subfunctions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int buffs_debuffs(World* const Game) {

    // If Hero has cleanse
    if (Game->Hero.buff.cleanse > 0) {
        if (Game->Hero.debuff.burn > 0) {
            Game->Hero.debuff.burn--;
            Game->Hero.buff.cleanse--;
            printf("The Hero's burn is reduced\n");
        }
        if (Game->Hero.debuff.poison > 0) {
            Game->Hero.debuff.poison--;
            Game->Hero.buff.cleanse--;
            printf("The Hero's poison is reduced\n");
        }
        if (Game->Hero.debuff.chill > 0) {
            Game->Hero.debuff.chill--;
            Game->Hero.buff.cleanse--;
            printf("The Hero's chill is reduced\n");
        }
        if (Game->Hero.debuff.slime > 0) {
            Game->Hero.debuff.slime--;
            Game->Hero.buff.cleanse--;
            printf("The Hero's slime is reduced\n");
        }
    }

    // Hero buffs
    // If Hero has Stone Skin, apply Stone Skin (+3def)
    if (Game->Hero.buff.stone_skin > 0) {
        printf("The Hero's skin was tough!\n");
        Game->Hero.stats.temp_def = Game->Hero.stats.temp_def + 3;
        // Decrease Buff by 1
        Game->Hero.buff.stone_skin--;
    }
    // If Hero has Iron Skin, apply Iron Skin (*2def)
    if (Game->Hero.buff.iron_skin > 0) {
        printf("The Hero's skin was tough!\n");
        Game->Hero.stats.temp_def = Game->Hero.stats.temp_def * 2;
        // Decrease Buff by 1
        Game->Hero.buff.iron_skin--;
    }
    // If Hero has Frenzy, apply Frenzy (x2dmg)
    if (Game->Hero.buff.frenzy > 0) {
        printf("The Hero is in a Frenzy!\n");
        Game->Hero.stats.temp_atk = Game->Hero.stats.temp_atk * 2;
        // Decrease Buff by 1
        Game->Hero.buff.frenzy--;
    }

    // Hero debuffs
    // If Hero has burn
    if (Game->Hero.debuff.burn > 0) {
        // If Hero has any chill
        if (Game->Hero.debuff.chill > 0) {

            // If Hero has more chill than burn
            if (Game->Hero.debuff.chill > Game->Hero.debuff.burn) {
                // Subtract burn from chill
                Game->Hero.debuff.chill -= Game->Hero.debuff.burn;
                Game->Hero.debuff.burn = 0;
            }
            // If Hero has more burn then chill
            else if (Game->Hero.debuff.chill < Game->Hero.debuff.burn) {
                // Subtract chill from burn
                Game->Hero.debuff.burn -= Game->Hero.debuff.chill;
                Game->Hero.debuff.chill = 0;
            }
            // If Hero has the same amount of burn and chill
            else {
                // Set burn and chill to zero
                Game->Hero.debuff.burn = 0;
                Game->Hero.debuff.chill = 0;
            }
        }
        if (Game->Hero.debuff.burn > 0) {
            // Apply burn (-5hp x0.75dmg)
            printf("The Hero was burned!\n");
            Game->Hero.stats.temp_atk = Game->Hero.stats.temp_atk * 0.75;
            Game->Hero.stats.hp = Game->Hero.stats.hp - 5;
            // Decrease Debuff by 1
            Game->Hero.debuff.burn--;
        }
    }
    // If Hero has chill, apply chill (*0.5dmg)
    if (Game->Hero.debuff.chill > 0) {
        printf("The Hero was chilled\n");
        Game->Hero.stats.temp_atk = Game->Hero.stats.temp_atk * 0.5;
        // Decrease Debuff by 1
        Game->Hero.debuff.chill--;
    }
    // If Hero has poison, apply poison (-10hp)
    if (Game->Hero.debuff.poison > 0) {
        printf("The Hero was poisoned!\n");
        Game->Hero.stats.hp = Game->Hero.stats.hp - Game->Hero.debuff.poison;
        // Decrease Debuff by 1
        Game->Hero.debuff.poison--;
    }

    // If Hero has negative mp
    if (Game->Hero.stats.mp < 0) {
        // Eats Hero's hp
        Game->Hero.stats.hp += (Game->Hero.stats.mp * 1.5);
        // Resets mp
        Game->Hero.stats.mp = 0;
        printf("The Hero experienced mana burn.\n");
    }

    // If Hero has slime, apply slime (-5, -10, -15 mp/hp)
    if (Game->Hero.debuff.slime > 0) {
        // If The Hero is Moderately Slimed
        if (Game->Hero.debuff.slime >= 5) {
            // If The Hero is Heavily Slimed
            if (Game->Hero.debuff.slime >= 10) {
                // Decrease Debuff by 3
                Game->Hero.debuff.slime -= 3;
                // Eat 15 Mana
                Game->Hero.stats.mp -= 15;
                printf("The Hero was Heavily Slimed!\n");
            } else {
                // Decrease Debuff by 2
                Game->Hero.debuff.slime -= 2;
                // Eat 10 Mana
                Game->Hero.stats.mp -= 10;
                printf("The Hero was moderately Slimed!\n");
            }
        } else {
            // Decrease Debuff by 1
            Game->Hero.debuff.slime--;
            // Eat 5 Mana
            Game->Hero.stats.mp -= 5;
            printf("The Hero is coated in a thin layer of slime.\n");
        }
        // If Hero has negative mp
        if (Game->Hero.stats.mp < 0) {
            // Eats Hero's hp
            Game->Hero.stats.hp += Game->Hero.stats.mp;
            // Resets mp
            Game->Hero.stats.mp = 0;
            printf("The Slime ate through The Hero's hp.\n");
        } else {
            printf("The Slime ate through The Hero's mp.\n");
        }
    }

    // If Enemy has cleanse
    if (Game->Enemy.buff.cleanse > 0) {
        if (Game->Enemy.debuff.burn > 0) {
            Game->Enemy.debuff.burn--;
            Game->Enemy.buff.cleanse--;
            printf("The Enemy's burn is reduced\n");
        }
        if (Game->Enemy.debuff.poison > 0) {
            Game->Enemy.debuff.poison--;
            Game->Enemy.buff.cleanse--;
            printf("The Enemy's poison is reduced\n");
        }
        if (Game->Enemy.debuff.chill > 0) {
            Game->Enemy.debuff.chill--;
            Game->Enemy.buff.cleanse--;
            printf("The Enemy's chill is reduced\n");
        }
        if (Game->Enemy.debuff.slime > 0) {
            Game->Enemy.debuff.slime--;
            Game->Enemy.buff.cleanse--;
            printf("The Enemy's slime is reduced\n");
        }
    }

    // Monster buffs
    // if Monster has Stone Skin, apply Stone Skin (+3def)
    if (Game->Enemy.buff.stone_skin > 0) {
        printf("The Monster's skin was tough!\n");
        Game->Enemy.stats.temp_def = Game->Enemy.stats.temp_def + 3;
        // Decrease Buff by 1
        Game->Enemy.buff.stone_skin--;
    }
    // if Monster has Iron Skin, apply Iron Skin (*2def)
    if (Game->Enemy.buff.iron_skin > 0) {
        printf("The Monster's skin was tough!\n");
        Game->Enemy.stats.temp_def = Game->Enemy.stats.temp_def * 2;
        // Decrease Buff by 1
        Game->Enemy.buff.iron_skin--;
    }
    // if Monster has Frenzy, apply Frenzy (x2dmg)
    if (Game->Enemy.buff.frenzy > 0) {
        printf("The Monster is in a Frenzy!\n");
        Game->Enemy.stats.temp_atk = Game->Enemy.stats.temp_atk * 2;
        // Decrease Buff by 1
        Game->Enemy.buff.frenzy--;
    }

    // Monster debuffs
    // Check if Monster has burn
    if (Game->Enemy.debuff.burn > 0) {
        // If Enemy has any chill
        if (Game->Enemy.debuff.chill > 0) {

            // If Enemy has more chill than burn
            if (Game->Enemy.debuff.chill > Game->Enemy.debuff.burn) {
                // Subtract burn from chill
                Game->Enemy.debuff.chill -= Game->Enemy.debuff.burn;
                Game->Enemy.debuff.burn = 0;
            }
            // If Enemy has more burn then chill
            else if (Game->Enemy.debuff.chill < Game->Enemy.debuff.burn) {
                // Subtract chill from burn
                Game->Enemy.debuff.burn -= Game->Enemy.debuff.chill;
                Game->Enemy.debuff.chill = 0;
            }
            // If Enemy has the same amount of burn and chill
            else {
                // Set burn and chill to zero
                Game->Enemy.debuff.burn = 0;
                Game->Enemy.debuff.chill = 0;
            }
        }
        // if Monster has burn absorb (+5 x1.5dmg)
        if (Game->Enemy.gimmick.burn_absorb == 1) {
            printf("Monster absorbed the fire!\n");
            Game->Enemy.stats.temp_atk = Game->Enemy.stats.temp_atk * 1.5;
            Game->Enemy.stats.hp = Game->Enemy.stats.hp + 5;
            // Decrease Debuff by 1
            Game->Enemy.debuff.burn--;
            if (Game->Enemy.stats.hp > Game->Enemy.stats.max_hp) {
                Game->Enemy.stats.hp = Game->Enemy.stats.max_hp;
            }
        }
        // if Monster has burn, apply burn (-5hp x0.75dmg)
        else {
            printf("Monster was burned!\n");
            Game->Enemy.stats.temp_atk = Game->Enemy.stats.temp_atk * 0.75;
            Game->Enemy.stats.hp = Game->Enemy.stats.hp - 5;
            // Decrease Debuff by 1
            Game->Enemy.debuff.burn--;
        }
    }
    // If Hero has chill, apply chill (*0.5dmg)
    if (Game->Enemy.debuff.chill > 0) {
        printf("The Enemy was chilled\n");
        Game->Enemy.stats.temp_atk = Game->Enemy.stats.temp_atk * 0.5;
        // Decrease Debuff by 1
        Game->Enemy.debuff.chill--;
    }
    // if Monster has poison, apply poison (hp-poison)
    if (Game->Enemy.debuff.poison > 0) {
        printf("Monster was poisoned!\n");
        Game->Enemy.stats.hp = Game->Enemy.stats.hp - Game->Enemy.debuff.poison;
        // Decrease Debuff by 1
        Game->Enemy.debuff.poison--;
    }

    // If Enemy has negative mp
    if (Game->Enemy.stats.mp < 0) {
        // Eats Enemy's hp
        Game->Enemy.stats.hp += (Game->Hero.stats.mp * 1.5);
        // Resets mp
        Game->Enemy.stats.mp = 0;
        printf("The Enemy experienced mana burn.\n");
    }

    // If Enemy has slime, apply slime (-5, -10, -15 mp/hp)
    if (Game->Enemy.debuff.slime > 0) {
        // If The Enemy is Moderately Slimed
        if (Game->Enemy.debuff.slime >= 5) {
            // If The Enemy is Heavily Slimed
            if (Game->Enemy.debuff.slime >= 10) {
                // Decrease Debuff by 3
                Game->Enemy.debuff.slime -= 3;
                // Eat 15 Mana
                Game->Enemy.stats.mp -= 15;
                printf("The Enemy was Heavily Slimed!\n");
            } else {
                // Decrease Debuff by 2
                Game->Enemy.debuff.slime -= 2;
                // Eat 10 Mana
                Game->Enemy.stats.mp -= 10;
                printf("The Enemy was moderately Slimed!\n");
            }
        } else {
            // Decrease Debuff by 1
            Game->Enemy.debuff.slime--;
            // Eat 5 Mana
            Game->Enemy.stats.mp -= 5;
            printf("The Enemy is coated in a thin layer of slime.\n");
        }
        // If Enemy has negative mp
        if (Game->Enemy.stats.mp < 0) {
            // Eats Enemy's hp
            Game->Enemy.stats.hp += Game->Enemy.stats.mp;
            // Resets mp
            Game->Enemy.stats.mp = 0;
            printf("The Slime ate through The Enemy's hp.\n");
        } else {
            printf("The Slime ate through The Enemy's mp.\n");
        }
    }
}
