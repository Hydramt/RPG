/**
 * @file combat.h
 * @author Gavin O.
 * @brief Holds combat subfunction
 * @version 0.1
 * @date 2026-10-16
 *
 * @copyright Copyright (c) 2026
 *
 */

#ifndef combat_H
#define combat_H

#include "RPG_Assets.h"
#include "RPG_Subfunctions.h"

/**
 * @brief Starting a combat with an enemy
 *
 * @param Hero The player character
 * @param Enemy The current enemy
 * @param cowardice Whether or not you run away
 * @return int
 */
int combat(World* const Game);

#endif
