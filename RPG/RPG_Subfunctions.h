/**
 * @file RPG_Battle_Subfunctions.h
 * @author Gavin O.
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
     * @brief *2 dmg
     */
    int frenzy;
} Buffs;

/**
 * @brief How many turns of what debuffs you have
 */
typedef struct debuffs {
    /**
     * @brief *0.75 atk -5hp
     */
    int burn;
    /**
     * @brief -poison amount hp
     */
    int poison;
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
} Hero_Stats;

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
    /**
     * @brief Storage for the player's spells
     */
    int spell[10];
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
    // Heal from poison
    int poison_heal;
    // Heal from burn
    int burn_absorb;
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
 * @brief Apply Buffs and Debuffs. Then Deincrement them
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
