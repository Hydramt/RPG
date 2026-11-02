/**
 * @file RPG_Battle_Subfunctions.h
 * @author Gavin O., Malik A.
 * @brief Contains The Damage Calculator and The Enemy AI
 * @version 0.1
 * @date 2026-10-09
 *
 * @copyright Copyright (c) 2026
 *
 */

/**
 * @brief How many turns of what buffs you have
 */
typedef struct buffs {
    /**
     * @brief +3 def
     */
    int stone_skin;
    /**
     * @brief *2 def
     */
    int iron_skin;
    /**
     * @brief *2 dmg
     */
    int frenzy;
    /**
     * @brief Removes Buffs and Debuffs
     */
    int cleanse;
} Buffs;

/**
 * @brief How many turns of what debuffs you have
 */
typedef struct debuffs {
    /**
     * @brief *0.75 atk -5hp (burn cancels out chill)
     */
    int burn;
    /**
     * @brief -poison amount hp
     */
    int poison;
    /**
     * @brief *0.5 atk (chill cancels out burn)
     */
    int chill;
    /**
     * @brief -5, -10, -15 mp/hp
     */
    int slime;
} Debuffs;

/**
 * @brief Stats for a player
 */
typedef struct hero_stats {
    /**
     * @brief How much till you die
     */
    int hp;
    /**
     * @brief The max amount of hp you can have
     */
    int max_hp;
    /**
     * @brief How many spells you can cast
     */
    int mp;
    /**
     * @brief The max amount of mp you can have
     */
    int max_mp;
    /**
     * @brief Your default attack
     */
    int atk;
    /**
     * @brief Your default defense
     */
    int def;
    /**
     * @brief Modifiable attack
     */
    int temp_atk;
    /**
     * @brief Modifiable defense
     */
    int temp_def;
    /**
     * @brief What level the player is
     */
    int lvl;
    /**
     * @brief How much exp the player has
     */
    int exp;
    /**
     * @brief How much gold the player has
     */
    int gold;
} Hero_Stats;

/**
 * @brief Hero Spell storage
 */
typedef struct spells {
    /**
     * @brief Which spell it is
     */
    int spell_id[10];
    /**
     * @brief The level of the spell
     */
    int spell_lvl[10];
    /**
     * @brief The type of the spell
     */
    int spell_type[10];
} Spells;

/**
 * @brief The items the player has in their inventory
 */
typedef struct items {
    /**
     * @brief Which item it is
     */
    int item_id[10];
    /**
     * @brief If the item can stack
     */
    int item_stackable[10];
    /**
     * @brief How many items you have
     */
    int item_amount[10];
} Items;

/**
 * @brief The player character
 */
typedef struct player {
    Hero_Stats stats;
    Buffs buff;
    Debuffs debuff;
    Spells spell;
    Items item;
} Player;

/**
 * @brief Stats for a enemy
 */
typedef struct enemy_stats {
    /**
     * @brief How much till you die
     */
    int hp;
    /**
     * @brief The max amount of hp you can have
     */
    int max_hp;
    /**
     * @brief How many spells you can cast
     */
    int mp;
    /**
     * @brief The max amount of mp you can have
     */
    int max_mp;
    /**
     * @brief Your default attack
     */
    int atk;
    /**
     * @brief Your default defense
     */
    int def;
    /**
     * @brief Modifiable attack
     */
    int temp_atk;
    /**
     * @brief Modifiable defense
     */
    int temp_def;
    /**
     * @brief What type of enemy it is
     */
    int enemy_type;
} Enemy_Stats;

/**
 * @brief Gimmicks enemies can have
 */
typedef struct gimmick {
    /**
     * @brief Heal from poison
     */
    int poison_heal;
    /**
     * @brief Heal from burn
     */
    int burn_absorb;
    /**
     * @brief Allows there to be more than one Enemy at a time
     */
    int multiply;
} Gimmick;

/**
 * @brief The Enemy
 */
typedef struct opponent {
    Enemy_Stats stats;
    Buffs buff;
    Debuffs debuff;
    Gimmick gimmick;
} Opponent;

/**
 * @brief Apply Buffs and Debuffs. Then Decrease them
 *
 * @param Enemy The Structure to hold the Enemy
 * @param Hero The Structure to hold the Player
 * @return Buff and Debuff damage and effects
 */
int buffs_debuffs(Player* const Hero, Opponent* const Enemy);

/**
 * @brief How the Enemy makes decisions and attacks
 *
 * @param Enemy The Structure to hold the Enemy
 * @param Hero The Structure to hold the Player
 * @return Enemy damage and effects
 */
int enemy_ai(Player* const Hero, Opponent* const Enemy);

/**
 * @brief How the Hero deals damage and inflicts effects
 *
 * @param Enemy The Structure to hold the Enemy
 * @param Hero The Structure to hold the Player
 * @return Hero damage and effects
 */
int damage_calculator(Player* const Hero, Opponent* const Enemy);

/**
 * @brief Calling spells for when the Hero casts them
 *
 * @param spell ID For which specific spell is called
 * @param description 0 if you want the name 1 if you want to use in a battle
 * @param Enemy The Structure to hold the Enemy
 * @param Hero The Structure to hold the Player
 * @return Name of Spell or Casting of spell
 */
const char*
spells(int spell, int description, Player* const Hero, Opponent* const Enemy);

/**
 * @brief
 *
 * @param item ID For which specific item is called
 * @param description 0 if you want the name 1 if you want to use in a battle
 * @param Enemy The Structure to hold the Enemy
 * @param Hero The Structure to hold the Player
 * @return Name of Item or Using of item
 */
const char*
items(int item, int description, Player* const Hero, Opponent* const Enemy);

/**
 * @brief Set Monster Stats to new Monster Stats
 *
 * @param Enemy The Structure to hold the Enemy
 * @param grab Which enemy it sets to
 * @return New Monster Stats
 */
void monster(Opponent* const Enemy, int grab);

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
 * @brief Gives the Hero exp for killing a monster and levels them up the max
 * level is 25
 *
 * @param Hero The Structure to hold the Player
 * @param Enemy The Structure to hold the Enemy
 * @return 1 if the Hero leveled up, 0 if not
 */
int level_up(Player* const Hero, Opponent* const Enemy);
