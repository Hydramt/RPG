/**
 * @file spells+items.c
 * @author Gavin O.
 * @brief Contains the spell and item info for the player
 * @version 0.1
 * @date 2026-10-09
 *
 * @copyright Copyright (c) 2026
 *
 */
#include "RPG_Subfunctions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

const char* items(
    /**
     * @brief The item in question you are using
     */
    int item,
    /**
     * @brief Tells if you are calling a description or using an item
     */
    int description,
    /**
     * @brief The Structure to contain the player character
     */
    Player* const Hero,
    /**
     * @brief The Structure to contain the enemy
     */
    Opponent* const Enemy
) {
    // Checks list of spells for names and effects

    // Item Name Hp Potion
    switch (item) {
        case 1:
            if (description == 0) {
                return "Hp Potion";
            } else {
                // Heal 30
                Hero->stats.temp_atk = -30;
            }
            break;
        case 2:
            if (description == 0) {
                return "Mp Potion";
            } else {
                // Restore 30 mp (Have a message)
                Hero->stats.mp = Hero->stats.mp + 30;
                if (Hero->stats.mp > Hero->stats.max_mp) {
                    Hero->stats.mp = Hero->stats.max_mp;
                    printf("The Hero restored their Mp to Max\n");
                } else {
                    printf("The Hero restored 30Mp\n");
                }
            }
            break;
        case 3:
            if (description == 0) {
                return "Ice Flask";
            } else {
                // Deal 15 damage
                Hero->stats.temp_atk = 15;

                Enemy->debuff.chill += 5;
            }
            break;
        case 4:
            if (description == 0) {
                return "Cleansing Potion";
            } else {
                // Remove Debuffs and Buffs
                Hero->debuff.burn = 0;
                Hero->debuff.chill = 0;
                Hero->debuff.poison = 0;
                Hero->debuff.slime = 0;
                Hero->buff.frenzy = 0;
                Hero->buff.stone_skin = 0;
                Hero->buff.cleanse += 5;
            }
            break;
        case 5:
            if (description == 0) {
                return "Spell Scroll: Check";
            } else {
                int count = 0;
                for (int i = 0; i < 10; i++) {
                    if (Hero->spell.spell_id[i] == 0) {
                        Hero->spell.spell_id[i] = 1;
                        Hero->spell.spell_lvl[i] = 0;
                        Hero->spell.spell_type[i] = 0;
                        if (i != 10) {
                            Hero->spell.spell_id[i + 1] = 0;
                            i = 10;
                        } else {
                            count++;
                        }
                    }
                }
                if (count == 10) {
                    printf("Too many spells\n");
                } else {
                    printf("You Learned Check!\n");
                }
            }
            break;
        case 6:
            if (description == 0) {
                return "Spell Scroll: Firebolt";
            } else {
                int count = 0;
                for (int i = 0; i < 10; i++) {
                    if (Hero->spell.spell_id[i] == 0) {
                        Hero->spell.spell_id[i] = 2;
                        Hero->spell.spell_lvl[i] = 0;
                        Hero->spell.spell_type[i] = 0;
                        if (i != 10) {
                            Hero->spell.spell_id[i + 1] = 0;
                            i = 10;
                        } else {
                            count++;
                        }
                    }
                }
                if (count == 10) {
                    printf("Too many spells\n");
                } else {
                    printf("You Learned Firebolt!\n");
                }
            }
        case 7:
            if (description == 0) {
                return "Spell Scroll: Stone Skin";
            } else {
                int count = 0;
                for (int i = 0; i < 10; i++) {
                    if (Hero->spell.spell_id[i] == 0) {
                        Hero->spell.spell_id[i] = 3;
                        Hero->spell.spell_lvl[i] = 0;
                        Hero->spell.spell_type[i] = 0;
                        if (i != 10) {
                            Hero->spell.spell_id[i + 1] = 0;
                            i = 10;
                        } else {
                            count++;
                        }
                    }
                }
                if (count == 10) {
                    printf("Too many spells\n");
                } else {
                    printf("You Learned Stone Skin!\n");
                }
            }
            break;
        case 8:
            if (description == 0) {
                return "Spell Scroll: Poison Shot";
            } else {
                int count = 0;
                for (int i = 0; i < 10; i++) {
                    if (Hero->spell.spell_id[i] == 0) {
                        Hero->spell.spell_id[i] = 4;
                        Hero->spell.spell_lvl[i] = 0;
                        Hero->spell.spell_type[i] = 0;
                        if (i != 10) {
                            Hero->spell.spell_id[i + 1] = 0;
                            i = 10;
                        } else {
                            count++;
                        }
                    }
                }
                if (count == 10) {
                    printf("Too many spells\n");
                } else {
                    printf("You Learned Poison Shot!\n");
                }
            }
            break;
        case 9:
            if (description == 0) {
                return "Spell Scroll: Icy Spray";
            } else {
                int count = 0;
                for (int i = 0; i < 10; i++) {
                    if (Hero->spell.spell_id[i] == 0) {
                        Hero->spell.spell_id[i] = 5;
                        Hero->spell.spell_lvl[i] = 0;
                        Hero->spell.spell_type[i] = 0;
                        if (i != 10) {
                            Hero->spell.spell_id[i + 1] = 0;
                            i = 10;
                        } else {
                            count++;
                        }
                    }
                }
                if (count == 10) {
                    printf("Too many spells\n");
                } else {
                    printf("You Learned Icy Spray!\n");
                }
            }
            break;
        case 10:
            if (description == 0) {
                return "Spell Scroll: Inner Fire";
            } else {
                int count = 0;
                for (int i = 0; i < 10; i++) {
                    if (Hero->spell.spell_id[i] == 0) {
                        Hero->spell.spell_id[i] = 6;
                        Hero->spell.spell_lvl[i] = 0;
                        Hero->spell.spell_type[i] = 0;
                        if (i != 10) {
                            Hero->spell.spell_id[i + 1] = 0;
                            i = 10;
                        } else {
                            count++;
                        }
                    }
                }
                if (count == 10) {
                    printf("Too many spells\n");
                } else {
                    printf("You Learned Inner Fire!\n");
                }
            }
            break;
        case 11:
            if (description == 0) {
                return "Spell Scroll: Slime Shot";
            } else {
                int count = 0;
                for (int i = 0; i < 10; i++) {
                    if (Hero->spell.spell_id[i] == 0) {
                        Hero->spell.spell_id[i] = 7;
                        Hero->spell.spell_lvl[i] = 0;
                        Hero->spell.spell_type[i] = 0;
                        if (i != 10) {
                            Hero->spell.spell_id[i + 1] = 0;
                            i = 10;
                        } else {
                            count++;
                        }
                    }
                }
                if (count == 10) {
                    printf("Too many spells\n");
                } else {
                    printf("You Learned Slime Shot!\n");
                }
            }
            break;
        case 12:
            if (description == 0) {
                return "Spell Scroll: Magic Missile";
            } else {
                int count = 0;
                for (int i = 0; i < 10; i++) {
                    if (Hero->spell.spell_id[i] == 0) {
                        Hero->spell.spell_id[i] = 8;
                        Hero->spell.spell_lvl[i] = 0;
                        Hero->spell.spell_type[i] = 0;
                        if (i != 10) {
                            Hero->spell.spell_id[i + 1] = 0;
                            i = 10;
                        } else {
                            count++;
                        }
                    }
                }
                if (count == 10) {
                    printf("Too many spells\n");
                } else {
                    printf("You Learned Magic Missile!\n");
                }
            }
            break;
        case 13:
            if (description == 0) {
                return "Spell Scroll: Heal";
            } else {
                int count = 0;
                for (int i = 0; i < 10; i++) {
                    if (Hero->spell.spell_id[i] == 0) {
                        Hero->spell.spell_id[i] = 9;
                        Hero->spell.spell_lvl[i] = 0;
                        Hero->spell.spell_type[i] = 0;
                        if (i != 10) {
                            Hero->spell.spell_id[i + 1] = 0;
                            i = 10;
                        } else {
                            count++;
                        }
                    }
                }
                if (count == 10) {
                    printf("Too many spells\n");
                } else {
                    printf("You Learned Heal!\n");
                }
            }
            break;
    }
}
