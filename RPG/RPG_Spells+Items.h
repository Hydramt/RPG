/**
 * @file RPG_Subfunctions.h
 * @author Gavin O.
 * @brief Call spells and items for the Hero
 * @version 0.1
 * @date 2026-10-07
 *
 * @copyright Copyright (c) 2026
 *
 */

/**
 * @brief The function to use the check spell
 *
 * @param Monster Monster as a 2d array
 * @return Info about the Monster
 */
int check(int grab);

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
