/**
 * @file RPG_World.h
 * @author Aniel Serrano
 * @brief Open world functions
 * @version 0.1
 * @date 2026-10-21
 */

#ifndef RPG_WORLD_H
#define RPG_WORLD_H

#include "combat.h"

/**
 * @brief Shows the world menu
 */
void showWorldMenu(void);

/**
 * @brief Gets the player's location choice
 */
int getWorldChoice(void);

/**
 * @brief Shows the village menu
 */
void showVillageMenu(void);

/**
 * @brief Shows the shop menu
 */
void showShopMenu(void);

/**
 * @brief Shows the quest board
 */
void visitQuestBoard(void);

/**
 * @brief Allows the player to buy an item
 * @param gold The player's current gold
 * @param itemIDs Items in the inventory
 * @param itemAmounts Amount of each item
 * @param itemStackable Checks if items can stack
 * @param itemID The item being purchased
 * @param price Cost of the item
 */
void buyShopItem(int *gold, int itemIDs[],
                 int itemAmounts[], int itemStackable[],
                 int itemID, int price);

/**
 * @brief Opens the village shop
 * @param gold The player's gold
 * @param itemIDs Items in the inventory
 * @param itemAmounts Amount of each item
 * @param itemStackable Checks if items can stack
 */
void visitShop(int *gold, int itemIDs[], int itemAmounts[],
               int itemStackable[]);

/**
 * @brief Lets the player visit the village
 * @param hp The player's current HP
 * @param maxHp The player's maximum HP
 * @param mp The player's current MP
 * @param maxMp The player's maximum MP
 * @param gold The player's gold
 * @param itemIDs Items in the inventory
 * @param itemAmounts Amount of each item
 * @param itemStackable Checks if items can stack
 */
void visitVillage(int *hp, int maxHp, int *mp, int maxMp,
                  int *gold, int itemIDs[], int itemAmounts[],
                  int itemStackable[]);

/**
 * @brief Starts a battle in the forest
 * @param Hero The player character
 * @param Enemy The current enemy
 */
void visitForest(Player *Hero, Opponent *Enemy);

/**
 * @brief Starts a battle in the cave
 * @param Hero The player character
 * @param Enemy The current enemy
 */
void visitCave(Player *Hero, Opponent *Enemy);

/**
 * @brief Runs the open world
 * @param Hero The player character
 * @param Enemy The current enemy
 */
void playWorld(Player *Hero, Opponent *Enemy);

#endif