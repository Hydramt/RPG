/**
 * @file RPG_Battle_Subfunctions.h
 * @author Gavin O.
 * @brief Contains The Damage Calculator and The Monster AI
 * @version 0.1
 * @date 2026-10-09
 *
 * @copyright Copyright (c) 2026
 *
 */

/**
 * @brief How the Monster makes decisions and attacks
 *
 * @param Monster The Monster 2d array
 * @param Hero The Hero 2d array
 * @return Monster damage and effects
 */
int monster_ai(int Hero[6][10], int Monster[4][10]);

/**
 * @brief How the Hero deals damage and inflicts effects
 *
 * @param Hero The Hero 2d array
 * @param Monster The Monster 2d array
 * @return Hero damage and effects
 */
int damage_calculator(int Hero[6][10], int Monster[4][10]);
