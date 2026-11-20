#include "RPG_Assets.h"
#include "RPG_Subfunctions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int enemy_ai(
    /**
     * @brief The Structure to contain the player character
     */
    World* const Game
) {

    // Mad Bunny AI
    if (Game->Enemy.stats.enemy_type == 1) {
        // The Mad Bunny makes a random choice between 1 abd 4
        int decision = (rand() % 4) + 1;
        // If Mad Bunny is at half health and has 20 mana
        // It burns 20 mp to enter a Frenzy
        if ((Game->Enemy.stats.hp <= (Game->Enemy.stats.max_hp / 2)) &&
            Game->Enemy.stats.mp >= 20) {
            printf("Mad Bunny entered a Frenzy!");
            Game->Enemy.buff.frenzy = 5;
            Game->Enemy.stats.mp = 0;
            Game->Enemy.stats.temp_atk = 0;
        }
        // Otherwise it checks if it is in a rage, and if it isn't
        // And it rolled a 4 it lollygags instead of anything else
        else if (decision == 4 && Game->Enemy.buff.frenzy <= 0) {
            printf("Mad Bunny lollygags");
            Game->Enemy.stats.temp_atk = 0;
        }
        // Then if it is in a rage it headbutts hard
        else if (Game->Enemy.buff.frenzy > 0) {
            printf("Mad Bunny headbutts hard");
        }
        // If it is not in a rage it just headbutts regularly
        else {
            printf("Mad Bunny headbutts");
        }
    }

    // Flame Wolf AI
    else if (Game->Enemy.stats.enemy_type == 2) {

        // The Flame Wolf makes a random choice between 1 abd 4
        int decision = (rand() % 3) + 1;

        // If the Flame Wolf is not on fire and has ten mana
        if (Game->Enemy.debuff.burn <= 0 && Game->Enemy.stats.mp > 10) {
            // The Flame Wolf sets itself on fire for 10 mana
            Game->Enemy.stats.mp = Game->Enemy.stats.mp - 10;
            Game->Enemy.debuff.burn = Game->Enemy.debuff.burn + 5;
            printf("The Flame Wolf ignited!");
            Game->Enemy.stats.temp_atk = 0;
        }
        // If the Flame Wolf has less then 5 mp and has more than 0 burn
        else if (Game->Enemy.stats.mp <= 5 && Game->Enemy.debuff.burn > 0) {
            // If The Flame Wolf would make more mana than it can hold
            if (((Game->Enemy.debuff.burn * 5) + Game->Enemy.stats.mp) >
                Game->Enemy.stats.max_mp) {
                // Only add as much mp as The Flame Wolf can hold
                while (Game->Enemy.stats.mp <= Game->Enemy.stats.max_mp) {
                    Game->Enemy.stats.mp += 5;
                    Game->Enemy.debuff.burn--;
                }
                // Stop mp from overflowing
                Game->Enemy.stats.mp = Game->Enemy.stats.max_mp;
            }
            // Otherwise eat up all the burn into mp
            else {
                Game->Enemy.stats.mp =
                    (Game->Enemy.debuff.burn * 5) + Game->Enemy.stats.mp;
                Game->Enemy.debuff.burn = 0;
            }
            Game->Enemy.stats.temp_atk = 0;
            printf("The Flame Wolf drank the flames");
        }
        // If the decision is 3 and the Flame Wolf has 10 or more mana
        else if (decision > 2 && Game->Enemy.stats.mp >= 10) {
            // Flame wolf does extra damage equal to its burn for 10 mana
            Game->Enemy.stats.temp_atk =
                Game->Enemy.stats.temp_atk + Game->Enemy.debuff.burn;
            Game->Enemy.stats.mp = Game->Enemy.stats.mp - 10;
            // And deals 1/2 of its burn to the Hero
            Game->Hero.debuff.burn += (Game->Enemy.debuff.burn * 0.5);
            printf("The Flame Wolf slices with its fiery claws");
        }
        // If the enemy has burn
        else if (Game->Enemy.debuff.burn > 0) {
            // Flame wolf burns hotter getting more burn
            // Dealing damage equal to burn
            // And adding a bit of mana
            Game->Enemy.debuff.burn += 3;
            Game->Enemy.stats.temp_atk = Game->Enemy.debuff.burn;
            Game->Enemy.stats.mp += 5;
            printf("The Flame Wolf burns hotter!");
        }
        // If The Fire Wolf has no burn and no mana
        else {
            printf("The Flame Wolf slices with its claws");
        }
    }

    // Slime AI
    else if (Game->Enemy.stats.enemy_type == 3) {

        // If Slimes have less hp than they should
        while (((Game->Enemy.gimmick.multiply - 1) * 20) >
               Game->Enemy.stats.hp) {
            // A Slime is murdered
            Game->Enemy.gimmick.multiply -= 1;
            Game->Enemy.stats.max_hp -= 20;
            Game->Enemy.debuff.burn = 0;
            Game->Enemy.debuff.chill = 0;
            Game->Enemy.debuff.poison = 0;
            Game->Enemy.debuff.slime = 0;
        }

        // For each Slime
        for (int i = 0; i < Game->Enemy.gimmick.multiply; i++) {

            // If there is more than one Slime
            if (Game->Enemy.gimmick.multiply > 1) {

                // If The Hero has no slime
                if (Game->Hero.debuff.slime == 0) {
                    // Add 4 slime and 0 dmg
                    printf("Slime %d slimes you", i + 1);
                    Game->Enemy.stats.temp_atk = 0;
                    Game->Hero.debuff.slime = 4;
                }

                // If The Hero has less than 5 slime
                else if (Game->Hero.debuff.slime < 5) {
                    // Add 2 slime and deal normal dmg
                    printf("Slime %d attempts to engulf you", i + 1);
                    Game->Hero.debuff.slime += 2;
                }

                // If The Hero has less than 10 slime
                else if (Game->Hero.debuff.slime < 10) {
                    // Add 2 slime and deal double dmg
                    printf("Slime %d surrounds you", i + 1);
                    Game->Hero.debuff.slime += 2;
                    Game->Enemy.stats.temp_atk *= 2;
                }

                // Otherwise
                else {
                    // Add 2 slime and deal triple dmg
                    printf(
                        "Slime %d completely surrounds you and grows", i + 1
                    );
                    Game->Hero.debuff.slime += 2;
                    Game->Enemy.stats.temp_atk *= 3;
                    Game->Enemy.stats.hp += 5;
                }
                if (i != Game->Enemy.gimmick.multiply) {
                    printf("\n");
                }
            }

            // Otherwise
            else {

                // If The Hero has no slime
                if (Game->Hero.debuff.slime == 0) {
                    printf("A Slime slimes you");
                    Game->Enemy.stats.temp_atk = 0;
                    Game->Hero.debuff.slime = 4;
                }

                // If The Hero has less than 5 slime
                else if (Game->Hero.debuff.slime < 5) {
                    // Add 2 slime and deal normal dmg
                    printf("A Slime attempts to engulf you", i);
                    Game->Hero.debuff.slime += 2;
                }

                // If The Hero has less than 10 slime
                else if (Game->Hero.debuff.slime < 10) {
                    // Add 2 slime and deal double dmg
                    printf("A Slime %d surrounds you", i);
                    Game->Hero.debuff.slime += 2;
                    Game->Enemy.stats.temp_atk *= 2;
                }

                // Otherwise
                else {
                    // Add 2 slime and deal triple dmg
                    printf("A Slime %d completely surrounds you and grows", i);
                    Game->Hero.debuff.slime += 2;
                    Game->Enemy.stats.temp_atk *= 3;
                    Game->Enemy.stats.hp += 5;
                }
            }
        }

        // If Slimes have more hp than they should
        while ((Game->Enemy.gimmick.multiply * 20) < Game->Enemy.stats.hp) {
            // Make a new slime
            Game->Enemy.gimmick.multiply += 1;
            Game->Enemy.stats.max_hp += 20;
            printf("A new slime spawns!");
            // If slimes still have more hp than they should, put it equal to
            // their max hp
            if (Game->Enemy.stats.hp > Game->Enemy.stats.max_hp) {
                Game->Enemy.stats.hp = Game->Enemy.stats.max_hp;
            }
        }
    }

    // Icy Stag
    if (Game->Enemy.stats.enemy_type == 4) {

        // If the Icy Stag has no Cleanse and it has a debuff
        if ((Game->Enemy.debuff.burn || Game->Enemy.debuff.chill ||
             Game->Enemy.debuff.poison || Game->Enemy.debuff.slime) &&
            Game->Enemy.buff.cleanse == 0) {
            printf("The Icy Stag began to cleanse itself");
            // The stag gains cleanse
            Game->Enemy.buff.cleanse += 3;
            Game->Enemy.stats.temp_atk = 0;
        }

        // If the Icy Stag is at less than half hp and it has at least 10 mp
        else if (
            (Game->Enemy.stats.hp <= (Game->Enemy.stats.max_hp / 2)) &&
            (Game->Enemy.stats.mp >= 10)
        ) {
            printf("The Icy Stag grew a defensive shell to protect itself");

            // If Hero attacked this turn
            if (Game->Hero.stats.temp_atk > 0) {
                // Deal damage and apply Chill
                printf("\nYou hit the hard icy shell and took 5 dmg");
                Game->Hero.stats.hp -= 5;
                Game->Hero.debuff.chill += 2;
            }

            // Gain 6 defense and lose 10 mp
            Game->Enemy.stats.temp_def += 6;
            Game->Enemy.stats.mp -= 10;
            Game->Enemy.stats.temp_atk = 0;
        }
        // If The Icy Stag has 15 mp
        else if (Game->Enemy.stats.mp > 15) {
            // Icy Stag casts Blizzard (Chill + Atk)
            printf("The Icy Stag whipped up a blizzard!");
            // Apply chill
            Game->Hero.debuff.chill += 3;
            Game->Enemy.stats.temp_atk += Game->Hero.debuff.chill;
            Game->Enemy.stats.mp -= 15;
        }
        // Else
        else {
            // Icy Stag just attacks
            printf("The Icy Stag attempts to trample you!");
        }
    }

    // Enemy calculations
    // If Enemy didn't do any damage
    if (Game->Enemy.stats.temp_atk <= 0) {
        printf("\n");
    }
    // If Enemy did less damage than the Hero's defense then deal one damage
    else if (Game->Enemy.stats.temp_atk < Game->Hero.stats.temp_def) {
        printf(" for 1 damage\n");
        Game->Hero.stats.hp = Game->Hero.stats.hp - 1;
    }
    // Otherwise calculate and print damage normally
    // (Enemy attack - Hero defense)
    else {
        printf(
            " for %d damage\n",
            (Game->Enemy.stats.temp_atk - Game->Hero.stats.temp_def)
        );
        Game->Hero.stats.hp = Game->Hero.stats.hp - Game->Enemy.stats.temp_atk +
                              Game->Hero.stats.temp_def;
    }

    // Check if it is a bunny if so make bunny pictures
    if (Game->Enemy.stats.enemy_type == 1) {
        // If bunny is in a rage print rage bunny
        if (Game->Enemy.buff.frenzy > 0) {
            assets(2);
        }
        // Otherwise it prints regular bunny
        else {
            assets(1);
        }
    }

    // Check if it is a Fire Wolf if so make wolf pictures
    else if (Game->Enemy.stats.enemy_type == 2) {
        // If Fire Wolf is on fire print Fire Wolf(Ignited)
        if (Game->Enemy.debuff.burn > 0) {
            assets(3);
        }
        // Otherwise it prints Fire Wolf(Unignited)
        else {
            assets(4);
        }
    }

    // Check if it is a Slime if so make slime pictures
    else if (Game->Enemy.stats.enemy_type == 3) {
        // If one slime
        if (Game->Enemy.gimmick.multiply == 1) {
            assets(6);
        }
        // If two slime
        else if (Game->Enemy.gimmick.multiply == 2) {
            assets(7);
        }
        // If more slime
        else {
            assets(8);
        }
    } else if (Game->Enemy.stats.enemy_type == 4) {
        // If Enemy has more temp def than actual def
        if (Game->Enemy.stats.temp_def > (Game->Enemy.stats.def + 3)) {
            assets(11);
        }
        // If Hero has chill
        else if (Game->Hero.debuff.chill > 0) {
            assets(10);
        }
        // Else
        else {
            assets(9);
        }
    }
}
