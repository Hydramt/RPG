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
 * @brief Apply Buffs and Debuffs. Then Deincrement them
 *
 * @param Monster The Monster 2d array
 * @param Hero The Hero 2d array
 * @return Buff and Debuff damage and effects
 */
int buffs_debuffs(int Hero[6][10], int Monster[4][10]);

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

/**
 * @brief Calling spells for when the Hero casts them
 *
 * @param spell ID For which specific spell is called
 * @param description 0 if you want the name 1 if you want to use in a battle
 * @param Hero The Hero as a 2D array
 * @param Monster The Monster as a 2D array
 * @return Name of Spell or Casting of spell
 */
const char*
spells(int spell, int description, int Hero[6][10], int Monster[4][10]);

/**
 * @brief
 *
 * @param item ID For which specific item is called
 * @param description 0 if you want the name 1 if you want to use in a battle
 * @param Hero The Hero as a 2D array
 * @param Monster The Monster as a 2D array
 * @return Name of Item or Using of item
 */
const char*
items(int item, int description, int Hero[6][10], int Monster[4][10]);
