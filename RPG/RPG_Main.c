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
    World Game;
    // Set Hero stats
    Game.Hero.stats.hp = 100;
    Game.Hero.stats.max_hp = 100;
    Game.Hero.stats.mp = 100;
    Game.Hero.stats.max_mp = 100;
    Game.Hero.stats.atk = 5;
    Game.Hero.stats.def = 1;
    Game.Hero.stats.temp_atk = 0;
    Game.Hero.stats.temp_def = 0;
    Game.Hero.stats.lvl = 1;
    Game.Hero.stats.exp = 0;
    Game.Hero.stats.gold = 50;

    // Set Hero's Buffs/Debuffs starting at 0
    Game.Hero.buff.stone_skin = 0;
    Game.Hero.buff.iron_skin = 0;
    Game.Hero.buff.frenzy = 0;
    Game.Hero.buff.cleanse = 0;
    Game.Hero.debuff.burn = 0;
    Game.Hero.debuff.poison = 0;
    Game.Hero.debuff.chill = 0;
    Game.Hero.debuff.slime = 0;

    // Set the Hero's starting spells
    // Check
    Game.Hero.spell.spell_id[0] = 1;
    Game.Hero.spell.spell_lvl[0] = 0;
    // Firebolt
    Game.Hero.spell.spell_id[1] = 2;
    Game.Hero.spell.spell_lvl[1] = 0;
    // Stone Skin
    Game.Hero.spell.spell_id[2] = 3;
    Game.Hero.spell.spell_lvl[2] = 0;
    // Poison shot
    Game.Hero.spell.spell_id[3] = 4;
    Game.Hero.spell.spell_lvl[3] = 0;
    // Empty
    Game.Hero.spell.spell_id[4] = 0;
    Game.Hero.spell.spell_id[10] = 0;

    // Set the starting items
    // Hp potion
    Game.Hero.item.item_id[0] = 1;
    // Stackable = Yes
    Game.Hero.item.item_stackable[0] = 1;
    // Item amount 2
    Game.Hero.item.item_amount[0] = 2;

    // Mp potion
    Game.Hero.item.item_id[1] = 2;
    // Stackable = Yes
    Game.Hero.item.item_stackable[1] = 1;
    // Item amount 1
    Game.Hero.item.item_amount[1] = 1;

    // Ice Flask
    Game.Hero.item.item_id[2] = 3;
    // Stackable = Yes
    Game.Hero.item.item_stackable[2] = 1;
    // Item amount 1
    Game.Hero.item.item_amount[2] = 1;

    // Empty
    Game.Hero.item.item_id[3] = 0;
    // Stackable = No
    Game.Hero.item.item_stackable[3] = 0;
    // Item amount 0
    Game.Hero.item.item_amount[3] = 0;

    // Empty
    Game.Hero.item.item_id[10] = 0;

    // In case the Enemy isn't chosen properly set Enemy hp to 0
    Game.Enemy.stats.hp = 0;

    // Set Enemy's Buffs/Debuffs starting at 0
    Game.Enemy.buff.stone_skin = 0;
    Game.Enemy.buff.iron_skin = 0;
    Game.Enemy.buff.frenzy = 0;
    Game.Enemy.buff.cleanse = 0;
    Game.Enemy.debuff.burn = 0;
    Game.Enemy.debuff.poison = 0;
    Game.Enemy.debuff.chill = 0;
    Game.Enemy.debuff.slime = 0;
    // Set Gimmicks to 0
    Game.Enemy.gimmick.burn_absorb = 0;
    Game.Enemy.gimmick.poison_heal = 0;

    // Set random numbers for the game
    srand(time(NULL));

    // Start the World Menu
    playerWorld(&Game);

    // Goodbye message when the player exits
    printf("\nThanks for playing! See you next time! :)\n");

    return 0;
}
