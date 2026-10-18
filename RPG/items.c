/**
 * @file spells+items.c
 * @author Gavin O.
 * @brief Contains the spell and item info for the player
 * @version 0.1
 * @date 2026-10-09
 *
 * @copyright Copyright (c) 2026
 *
 */
#include "RPG_Subfunctions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

const char* items(
    /**
     * @brief The item in question you are using
     */
    int item,
    /**
     * @brief Tells if you are calling a description or using an item
     */
    int description,
    /**
     * @brief The Structure to contain the player character
     */
    Player* const Hero,
    /**
     * @brief The Structure to contain the enemy
     */
    Opponent* const Enemy
) {
    // Checks list of spells for names and effects

    // Item Name Hp Potion
    if (item == 1) {
        if (description == 0) {
            return "Hp Potion";
        } else {
            // Heal 30
            Hero->stats.temp_atk = -30;
        }

    }

    // Item Name Mp Potion
    else if (item == 2) {
        if (description == 0) {
            return "Mp Potion";
        } else {
            // Restore 30 mp (Have a message)
            Hero->stats.mp = Hero->stats.mp + 30;
            if (Hero->stats.mp > Hero->stats.max_mp) {
                Hero->stats.mp = Hero->stats.max_mp;
                printf("The Hero restored their Mp to Max\n");
            } else {
                printf("The Hero restored 30Mp\n");
            }
        }
    }

    // Item Name Ice Flask
    else if (item == 3) {
        if (description == 0) {
            return "Ice Flask";
        } else {
            // Deal 15 damage
            Hero->stats.temp_atk = 15;

            Enemy->debuff.chill += 5;
        }
    }
}
