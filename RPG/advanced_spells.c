#include "RPG_Subfunctions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int check(int grab) {
    switch (grab) {
        case 1:
            printf("The Mad Bunny\n");
            printf("Str:3 Def:0\n");
            printf("Max Hp:40 Max Mp:20\n");
            printf("Mad Bunnies: A beginner enemy.\n");
            printf("Beware, at half health it enters\n");
            printf("a frenzy.\n");
            break;
        case 2:
            printf("The Fire Wolf\n");
            printf("Str:7 Def:2\n");
            printf("Max Hp:80 Max Mp:50\n");
            printf("The Fire Wolf: A dangerous inhabitant\n");
            printf("of The Cave. The hotter it burns the\n");
            printf("stronger it is! Using chill may be\n");
            printf("helpful.\n");
            break;
        case 3:
            printf("Slime\n");
            printf("Str:4 Def:4\n");
            printf("Max Hp:20 Max Mp:0\n");
            printf("Slimes: One of the most basic enemies.\n");
            printf("They like to eat your hp and mana slowly.\n");
            printf("Beware groups of them as they can quickly\n");
            printf("multiply and swarm you.\n");
            break;
        case 4:
            printf("The Icy Stag\n");
            printf("Str:6 Def:3\n");
            printf("Max Hp:60 Max Mp:100\n");
            printf("The Icy Stag: A creature of the cold.\n");
            printf("It does not like debuffs and will attempt\n");
            printf("to shed them if possible. When it reaches\n");
            printf("half health it will attempt to defend\n");
            printf("itself with it's icy shell. It's mana is\n");
            printf("not endless.\n");
            break;
    }
}

const char* spells(
    /**
     * @brief The spell being used
     */
    int spell_slot,
    /**
     * @brief Whether or not you are calling the name or the effect
     */
    int description,
    /**
     * @brief The Structure to contain the player character
     */
    World* const Game
) {
    // Checks list of spells for names and effects

    switch (Game->Hero.spell.spell_lvl[spell_slot]) {
        case 0:
            switch (Game->Hero.spell.spell_id[spell_slot]) {
                case 1:
                    // Spell Name Check
                    if (description == 0) {
                        return "Check";
                    } else {
                        // Drink 5 mana
                        Game->Hero.stats.mp = Game->Hero.stats.mp - 5;
                        Game->Hero.stats.temp_atk = 0;
                        check(Game->Enemy.stats.enemy_type);
                    }
                    break;
                case 2:
                    // Spell Name Firebolt
                    if (description == 0) {
                        return "Firebolt";
                    } else {
                        // Deal 15 damage
                        Game->Hero.stats.temp_atk = 15;
                        // Drink 10 mana
                        Game->Hero.stats.mp = Game->Hero.stats.mp - 10;

                        // 33% chance to burn for 3 turns
                        if (rand() % 3 > 1) {
                            Game->Enemy.debuff.burn =
                                Game->Enemy.debuff.burn + 3;
                        }
                    }
                    break;
                case 3:
                    // Spell Name Stone Skin
                    if (description == 0) {
                        return "Stone Skin";
                    } else {
                        // Get Stone Skin for 4 turns
                        Game->Hero.buff.stone_skin =
                            Game->Hero.buff.stone_skin + 4;
                        // Drink 20 mana
                        Game->Hero.stats.mp = Game->Hero.stats.mp - 20;
                    }
                    break;
                case 4:
                    // Spell Name Poison Shot
                    if (description == 0) {
                        return "Poison Shot";
                    } else {
                        // Deal 5 damage
                        Game->Hero.stats.temp_atk = 5;
                        // Drink 10 mana
                        Game->Hero.stats.mp = Game->Hero.stats.mp - 10;

                        // Applies 3 poison
                        Game->Enemy.debuff.poison =
                            Game->Enemy.debuff.poison + 3;
                    }
                    break;
                case 5:
                    // Spell Name Ice Spray
                    if (description == 0) {
                        return "Ice Spray";
                    }
                    // Deal 5 damage
                    Game->Hero.stats.temp_atk = 5;
                    // Drink 10 mana
                    Game->Hero.stats.mp = Game->Hero.stats.mp - 15;

                    // Apply 4 Chill
                    Game->Enemy.debuff.chill += 4;
                    break;
                case 6:
                    // Spell Name Inner Fire
                    if (description == 0) {
                        return "Inner Fire";
                    }
                    // Drink 10 mana
                    Game->Hero.stats.mp = Game->Hero.stats.mp - 10;
                    // Add 4 Frenzy
                    Game->Hero.buff.frenzy += 4;
                    // Add 4 Burn
                    Game->Hero.debuff.burn += 4;
                    break;
                case 7:
                    // Spell Name Slime Shot
                    if (description == 0) {
                        return "Slime Shot";
                    }
                    // Drink 10 mana
                    Game->Hero.stats.mp = Game->Hero.stats.mp - 10;
                    // Add 5 Slime
                    Game->Enemy.debuff.slime += 5;
                    // Deal damage
                    Game->Hero.stats.temp_atk = 10;
                    break;
                case 8:
                    // Spell Name Magic Missile
                    if (description == 0) {
                        return "Magic Missile";
                    }
                    // Drink 5 mana
                    Game->Hero.stats.mp = Game->Hero.stats.mp - 5;
                    // Deal 20 dmg
                    Game->Hero.stats.temp_atk += 20;
                    break;
                case 9:
                    // Spell Name Heal
                    if (description == 0) {
                        return "Heal";
                    }
                    // Drink 10 mana
                    Game->Hero.stats.mp = Game->Hero.stats.mp - 10;
                    // Heal 20 dmg
                    Game->Hero.stats.temp_atk = -20;
                    break;
            }
            break;

        // Level 1 spells
        case 1:
            switch (Game->Hero.spell.spell_id[spell_slot]) {
                case 1:
                    // Spell Name Check
                    if (description == 0) {
                        return "Check";
                    } else {
                        Game->Hero.stats.temp_atk = 0;
                        check(Game->Enemy.stats.enemy_type);
                        Game->Hero.stats.mp += 5;
                        if (Game->Hero.stats.mp > Game->Hero.stats.max_mp) {
                            Game->Hero.stats.mp = Game->Hero.stats.max_mp;
                        }
                    }
                    break;

                // Firebolt evolutions
                case 2:
                    switch (Game->Hero.spell.spell_type[spell_slot]) {

                        // Greater Firebolt Spell
                        case 1:
                            if (description == 0) {
                                return "Greater Firebolt";
                            } else {
                                // Deal 25 damage
                                Game->Hero.stats.temp_atk = 25;
                                // Drink 15 mana
                                Game->Hero.stats.mp = Game->Hero.stats.mp - 15;

                                // 50% chance to burn for 5 turns
                                if (rand() % 2 > 1) {
                                    Game->Enemy.debuff.burn =
                                        Game->Enemy.debuff.burn + 5;
                                }
                            }
                            break;

                        // Pyre Spell
                        case 2:
                            if (description == 0) {
                                return "Pyre";
                            } else {
                                // Deal 15 damage
                                Game->Hero.stats.temp_atk = 15;
                                // Drink 10 mana
                                Game->Hero.stats.mp = Game->Hero.stats.mp - 10;
                                // Apply 10 burn
                                Game->Enemy.debuff.burn =
                                    Game->Enemy.debuff.burn + 10;
                            }
                            break;

                        // Fire Ball Spell
                        case 3:
                            if (description == 0) {
                                return "Fire Ball";
                            } else {
                                // Deal 30 damage
                                Game->Hero.stats.temp_atk = 30;
                                // Drink 25 mana
                                Game->Hero.stats.mp = Game->Hero.stats.mp - 25;
                                // Apply 2 burn
                                Game->Enemy.debuff.burn =
                                    Game->Enemy.debuff.burn + 2;
                            }
                            break;
                    }
                    break;

                // Stone Skin evolutions
                case 3:
                    switch (Game->Hero.spell.spell_type[spell_slot]) {

                        // Greater Stone Skin
                        case 1:
                            if (description == 0) {
                                return "Greater Stone Skin";
                            } else {
                                // Get Stone Skin for 8 turns
                                Game->Hero.buff.stone_skin =
                                    Game->Hero.buff.stone_skin + 8;
                                // Drink 15 mana
                                Game->Hero.stats.mp = Game->Hero.stats.mp - 15;
                            }
                            break;

                        // Iron Skin
                        case 2:
                            if (description == 0) {
                                return "Iron Skin";
                            } else {
                                // Get Iron Skin for 3 turns
                                Game->Hero.buff.iron_skin =
                                    Game->Hero.buff.iron_skin + 3;
                                // Drink 30 mana
                                Game->Hero.stats.mp = Game->Hero.stats.mp - 30;
                            }
                            break;

                        // Lava Skin
                        case 3:
                            if (description == 0) {
                                return "Lava Skin";
                            } else {
                                // Get Stone Skin for 4 turns
                                Game->Hero.buff.stone_skin =
                                    Game->Hero.buff.stone_skin + 4;
                                // Get Frenzy for 3 turns
                                Game->Hero.buff.frenzy += 3;
                                // Get Burn for 3 turns
                                Game->Hero.debuff.burn += 3;
                                // Enemy gets Burn for 6 turns
                                Game->Enemy.debuff.burn += 6;
                                // Drink 40 mana
                                Game->Hero.stats.mp = Game->Hero.stats.mp - 40;
                            }
                            break;
                    }
                    break;

                // Poison shot evolutions
                case 4:
                    switch (Game->Hero.spell.spell_type[spell_slot]) {

                        // Greater Poison Shot
                        case 1:
                            if (description == 0) {
                                return "Greater Poison Shot";
                            } else {
                                // Deal 10 damage
                                Game->Hero.stats.temp_atk = 10;
                                // Drink 15 mana
                                Game->Hero.stats.mp = Game->Hero.stats.mp - 15;
                                // Applies 6 poison
                                Game->Enemy.debuff.poison =
                                    Game->Enemy.debuff.poison + 6;
                            }
                            break;

                        // Spell Name Gunk Shot
                        case 2:
                            if (description == 0) {
                                return "Gunk Shot";
                            } else {
                                // Deal 10 damage
                                Game->Hero.stats.temp_atk = 5;
                                // Drink 15 mana
                                Game->Hero.stats.mp = Game->Hero.stats.mp - 15;
                                // Applies 4 poison
                                Game->Enemy.debuff.poison += 4;
                                // Applies 4 slime
                                Game->Enemy.debuff.slime += 4;
                            }
                            break;
                    }
                    break;

                // Ice Spray Evolutions
                case 5:
                    switch (Game->Hero.spell.spell_type[spell_slot]) {
                        // Spell Name Greater Ice Spray
                        case 1:
                            if (description == 0) {
                                return "Greater Ice Spray";
                            }
                            // Deal 10 damage
                            Game->Hero.stats.temp_atk = 10;
                            // Drink 10 mana
                            Game->Hero.stats.mp = Game->Hero.stats.mp - 10;

                            // Apply 6 Chill
                            Game->Enemy.debuff.chill += 6;
                            break;

                        // Spell Name Blizzard
                        case 2:
                            if (description == 0) {
                                return "Blizzard";
                            }
                            // Deal 25 damage
                            Game->Hero.stats.temp_atk = 25;
                            // Drink 20 mana
                            Game->Hero.stats.mp = Game->Hero.stats.mp - 20;

                            // Apply 4 Chill
                            Game->Enemy.debuff.chill += 4;
                            break;

                        // Spell Name Ice Spike
                        case 3:
                            if (description == 0) {
                                return "Ice Spike";
                            }
                            // Deal 25 damage
                            Game->Hero.stats.temp_atk = 35;
                            // Drink 20 mana
                            Game->Hero.stats.mp = Game->Hero.stats.mp - 30;
                            break;
                    }
                    break;
            }
            break;
    }
}
