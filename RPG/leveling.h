/**
 * @file leveling.h
 * @author Malik A.
 * @brief header file that contains the Leveling System
 * @version 0.1
 * @date 2026-10-27
 *
 * @copyright Copyright (c) 2026
 *
 */

/**
 * @brief how much exp the Hero needs to reach the next level
 *
 * @param lvl The heros current level
 * @return exp needed for the next level
 */
int exp_needed(int lvl);

/**
 * @brief how much exp a monster gives when it dies
 *
 * @param Enemy The Structure to hold the Enemy
 * @return exp the monster is worth
 */
int exp_reward(Opponent* const Enemy);

/**
 * @brief Gives the Hero exp for killing a monster and levels them up the max level is 25
 *
 * @param Hero The Structure to hold the Player
 * @param Enemy The Structure to hold the Enemy
 * @return 1 if the Hero leveled up, 0 if not
 */
int level_up(Player* const Hero, Opponent* const Enemy);
