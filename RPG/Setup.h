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
    int item_amount[10];
} Items;

typedef struct player {
    Hero_Stats stat;
    Buffs buff;
    Debuffs debuff;
    int spell[10];
    Items item;
} Player;

typedef struct monster_stats {
    int hp;
    int max_hp;
    int mp;
    int max_mp;
    int atk;
    int def;
    int temp_atk;
    int temp_def;
    int monster_type;
} Monster_Stats;

typedef struct gimmick {
    int poison_heal;
    int burn_absorb;
} Gimmick;

typedef struct enemy {
    Monster_Stats stat;
    Buffs buffs;
    Debuffs debuffs;
    Gimmick gimmick;
} Enemy;
