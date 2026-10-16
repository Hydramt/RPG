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
 * @brief
 *
 */

typedef struct buffs {
    int stone_skin;
    int frenzy;
} Buffs;

typedef struct debuffs {
    int burn;
    int poison;
} Debuffs;

typedef struct hero_stats {
    int hp;
    int max_hp;
    int mp;
    int max_mp;
    int atk;
    int def;
    int temp_atk;
    int temp_def;
    int lvl;
    int exp;
} Hero_Stats;

typedef struct items {
    int item_id[10];
    int item_stackable[10];
    int item_amount[10];
} Items;

typedef struct player {
    Hero_Stats stats;
    Buffs buff;
    Debuffs debuff;
    int spell[10];
    Items item;
} Player;

typedef struct enemy_stats {
    int hp;
    int max_hp;
    int mp;
    int max_mp;
    int atk;
    int def;
    int temp_atk;
    int temp_def;
    int enemy_type;
} Enemy_Stats;

typedef struct gimmick {
    int poison_heal;
    int burn_absorb;
} Gimmick;

typedef struct opponent {
    Enemy_Stats stats;
    Buffs buff;
    Debuffs debuff;
    Gimmick gimmick;
} Opponent;

/**
 * @brief Apply Buffs and Debuffs. Then Deincrement them
 *
 * @param Enemy The Enemy 2d array
 * @param Hero The Hero 2d array
 * @return Buff and Debuff damage and effects
 */
int buffs_debuffs(Player* const Hero, Opponent* const Enemy);

/**
 * @brief How the Enemy makes decisions and attacks
 *
 * @param Enemy The Enemy 2d array
 * @param Hero The Hero 2d array
 * @return Enemy damage and effects
 */
int enemy_ai(Player* const Hero, Opponent* const Enemy);

/**
 * @brief How the Hero deals damage and inflicts effects
 *
 * @param Hero The Hero 2d array
 * @param Enemy The Enemy 2d array
 * @return Hero damage and effects
 */
int damage_calculator(Player* const Hero, Opponent* const Enemy);

/**
 * @brief Calling spells for when the Hero casts them
 *
 * @param spell ID For which specific spell is called
 * @param description 0 if you want the name 1 if you want to use in a battle
 * @param Hero The Hero as a 2D array
 * @param Enemy The Enemy as a 2D array
 * @return Name of Spell or Casting of spell
 */
const char*
spells(int spell, int description, Player* const Hero, Opponent* const Enemy);

/**
 * @brief
 *
 * @param item ID For which specific item is called
 * @param description 0 if you want the name 1 if you want to use in a battle
 * @param Hero The Hero as a 2D array
 * @param Enemy The Enemy as a 2D array
 * @return Name of Item or Using of item
 */
const char*
items(int item, int description, Player* const Hero, Opponent* const Enemy);
