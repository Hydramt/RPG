/**
 * @file RPG_Main.c
 * @author Gavin O. +
 * @brief RPG_Game
 * @version 0.1
 * @date 2026-10-15
 *
 * @copyright Copyright (c) 2026
 *
 */
#include "RPG_Assets.h"
#include "RPG_Subfunctions.h"
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

    // Set Hero's Buffs/Debuffs starting at 0
    Hero.buff.stone_skin = 0;
    Hero.buff.frenzy = 0;
    Hero.debuff.burn = 0;
    Hero.debuff.poison = 0;
    Hero.debuff.chill = 0;
    Hero.debuff.slime = 0;

    // Set the Hero's starting spells
    // Check
    Hero.spell[0] = 1;
    // Firebolt
    Hero.spell[1] = 2;
    // Stone Skin
    Hero.spell[2] = 3;
    // Poison shot
    Hero.spell[3] = 4;
    // Empty
    Hero.spell[4] = 0;

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
    Hero.item.item_amount[2] = 1;

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
    Enemy.buff.frenzy = 0;
    Enemy.debuff.burn = 0;
    Enemy.debuff.poison = 0;
    Enemy.debuff.chill = 0;
    Enemy.debuff.slime = 0;
    // Set Gimmicks to 0
    Enemy.gimmick.burn_absorb = 0;
    Enemy.gimmick.poison_heal = 0;

    // Set win condition
    int win = 0;
    while (win == 0) {
        // Set random
        srand(time(NULL));

        // the main function that will allow the player to choose options
        int player_choice;

        // function that tells if you ran away
        int cowardice = 0;

        printf("Choose your difficulty\n");
        printf("1. Easy\n");
        printf("2. Medium\n");
        printf("3. Hard\n");
        scanf("%d", &player_choice);

        if (player_choice == 1) {
            monster(&Enemy, 1);
        } else if (player_choice == 2) {
            monster(&Enemy, 2);
        } else if (player_choice == 3) {
            monster(&Enemy, 3);
        } else {
            printf("Incorrect input\n");
            printf("Please try again\n");
        }

        // Enemy intro message
        // If Mad Bunny
        if (Enemy.stats.enemy_type == 1) {
            printf("The Mad Bunny attacks!\n");
            assets(1);
        }

        // If Fire Wolf
        else if (Enemy.stats.enemy_type == 2) {
            printf("The Fire Wolf attacks!\n");
            assets(4);
        }

        // If Slime
        else if (Enemy.stats.enemy_type == 3) {
            // One Slime
            if (Enemy.gimmick.multiply == 1) {
                printf("A Slime attacks!\n");
                assets(6);
            }
            // Two Slimes
            else if (Enemy.gimmick.multiply == 2) {
                printf("Two Slimes attack!\n");
                assets(7);
            }
            // More Slimes
            else {
                printf("A horde of Slimes attack!\n");
                assets(8);
            }
        }

        // The combat loop
        cowardice = combat(&Hero, &Enemy, cowardice);

        // if you killed the Enemy and didn't run away you win!
        if (Enemy.stats.hp <= 0 && cowardice > 0) {
            printf("You Win!");
            win = 1;
        }
    }
}
