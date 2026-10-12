/**
 * @file RPG_Assets.h
 * @author Gavin O.
 * @brief Header file that contains the Assets and Death messages
 * @version 0.1
 * @date 2026-10-09
 *
 * @copyright Copyright (c) 2026
 *
 */

/**
 * @brief Message that happens when a monster dies
 *
 * @param type Tells what monster died
 * @return Death message
 */
int death(int type);

/**
 * @brief A function containing all of the common assets for the RPG
 *
 * @param grab Int that retrieves the image you want
 * @return Printed assets
 */
int assets(int grab);
