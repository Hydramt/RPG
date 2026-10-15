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

const char*
items(int item, int description, int Hero[6][10], int Monster[4][10]) {
    // Checks list of spells for names and effects

    // Item Name Hp Potion
    if (item == 1) {
        if (description == 0) {
            return "Hp Potion";
        } else {
            Hero[0][6] = -20;
        }

    }

    // Item Name Mp Potion
    else if (item == 2) {
        if (description == 0) {
            return "Mp Potion";
        } else {
            Hero[0][2] = Hero[0][2] + 20;
            if (Hero[0][2] > Hero[0][3]) {
                Hero[0][2] = Hero[0][3];
                printf("The Hero restored their Mp to Max\n");
            } else {
                printf("The Hero restored 20Mp\n");
            }
        }
    }

    // Item Name Ice Potion
    else if (item == 3) {
        if (description == 0) {
            return "Ice Potion";
        } else {
            Hero[0][6] = 15;
        }
    }
}
