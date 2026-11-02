/**
 * @file RPG_Main.c
 * @author Gavin O. , Aniel S.
 * @brief RPG_Game
 * @version 0.1
 * @date 2026-10-15
 *
 * @copyright Copyright (c) 2026
 *
 */
#include "RPG_Assets.h"
#include "RPG_Subfunctions.h"
#include "RPG_World.h"
#include "combat.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(void) {

    /**
     * @brief The Structure to contain the player character
     */
    Player Hero;
    // Set Hero stats
    Hero.stats.hp = 100;
    Hero.stats.max_hp = 100;
    Hero.stats.mp = 100;
    Hero.stats.max_mp = 100;
    Hero.stats.atk = 5;
    Hero.stats.def = 1;
    Hero.stats.temp_atk = 0;
    Hero.stats.temp_def = 0;
    Hero.stats.lvl = 1;
    Hero.stats.exp = 0;
    Hero.stats.gold = 500;

    // Set Hero's Buffs/Debuffs starting at 0
    Hero.buff.stone_skin = 0;
    Hero.buff.iron_skin = 0;
    Hero.buff.frenzy = 0;
    Hero.buff.cleanse = 0;
    Hero.debuff.burn = 0;
    Hero.debuff.poison = 0;
    Hero.debuff.chill = 0;
    Hero.debuff.slime = 0;

    // Set the Hero's starting spells
    // Check
    Hero.spell.spell_id[0] = 1;
    Hero.spell.spell_lvl[0] = 0;
    // Firebolt
    Hero.spell.spell_id[1] = 2;
    Hero.spell.spell_lvl[1] = 0;
    // Stone Skin
    Hero.spell.spell_id[2] = 3;
    Hero.spell.spell_lvl[2] = 0;
    // Poison shot
    Hero.spell.spell_id[3] = 4;
    Hero.spell.spell_lvl[3] = 0;
    // Empty
    Hero.spell.spell_id[4] = 0;

    // Set the starting items
    // Hp potion
    Hero.item.item_id[0] = 1;
    // Stackable = Yes
    Hero.item.item_stackable[0] = 1;
    // Item amount 2
    Hero.item.item_amount[0] = 2;

    // Mp potion
    Hero.item.item_id[1] = 2;
    // Stackable = Yes
    Hero.item.item_stackable[1] = 1;
    // Item amount 1
    Hero.item.item_amount[1] = 1;

    // Ice Flask
    Hero.item.item_id[2] = 3;
    // Stackable = Yes
    Hero.item.item_stackable[2] = 1;
    // Item amount 1
    Hero.item.item_amount[2] = 100;

    // Empty
    Hero.item.item_id[3] = 0;
    // Stackable = No
    Hero.item.item_stackable[3] = 0;
    // Item amount 0
    Hero.item.item_amount[3] = 0;

    /**
     * @brief The structure to contain the Enemy
     */
    Opponent Enemy;
    // In case the Enemy isn't chosen properly set Enemy hp to 0
    Enemy.stats.hp = 0;

    // Set Enemy's Buffs/Debuffs starting at 0
    Enemy.buff.stone_skin = 0;
    Enemy.buff.iron_skin = 0;
    Enemy.buff.frenzy = 0;
    Enemy.buff.cleanse = 0;
    Enemy.debuff.burn = 0;
    Enemy.debuff.poison = 0;
    Enemy.debuff.chill = 0;
    Enemy.debuff.slime = 0;
    // Set Gimmicks to 0
    Enemy.gimmick.burn_absorb = 0;
    Enemy.gimmick.poison_heal = 0;

    // Set random numbers for the game
    srand(time(NULL));

    // Start the World Menu
    playerWorld(&Hero, &Enemy);

    // Goodbye message when the player exits
    printf("\nThanks for playing! See you next time! :)\n");

    return 0;
}
