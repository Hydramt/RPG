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
    Player* const Hero,
    /**
     * @brief The Structure to contain the enemy
     */
    Opponent* const Enemy
) {

    // Mad Bunny AI
    if (Enemy->stats.enemy_type == 1) {
        // The Mad Bunny makes a random choice between 1 abd 4
        int decision = (rand() % 4) + 1;
        // If Mad Bunny is at half health and has 20 mana
        // It burns 20 mp to enter a Frenzy
        if ((Enemy->stats.hp <= (Enemy->stats.max_hp / 2)) &&
            Enemy->stats.mp >= 20) {
            printf("Mad Bunny entered a Frenzy!");
            Enemy->buff.frenzy = 5;
            Enemy->stats.mp = 0;
            Enemy->stats.temp_atk = 0;
        }
        // Otherwise it checks if it is in a rage, and if it isn't
        // And it rolled a 4 it lollygags instead of anything else
        else if (decision == 4 && Enemy->buff.frenzy <= 0) {
            printf("Mad Bunny lollygags");
            Enemy->stats.temp_atk = 0;
        }
        // Then if it is in a rage it headbutts hard
        else if (Enemy->buff.frenzy > 0) {
            printf("Mad Bunny headbutts hard");
        }
        // If it is not in a rage it just headbutts regularly
        else {
            printf("Mad Bunny headbutts");
        }
    }

    // Flame Wolf AI
    else if (Enemy->stats.enemy_type == 2) {

        // The Flame Wolf makes a random choice between 1 abd 4
        int decision = (rand() % 3) + 1;

        // If the Flame Wolf is not on fire and has ten mana
        if (Enemy->debuff.burn <= 0 && Enemy->stats.mp > 10) {
            // The Flame Wolf sets itself on fire for 10 mana
            Enemy->stats.mp = Enemy->stats.mp - 10;
            Enemy->debuff.burn = Enemy->debuff.burn + 5;
            printf("The Flame Wolf ignited!");
            Enemy->stats.temp_atk = 0;
        }
        // If the Flame Wolf has less then 5 mp and has more than 0 burn
        else if (Enemy->stats.mp <= 5 && Enemy->debuff.burn > 0) {
            // If The Flame Wolf would make more mana than it can hold
            if (((Enemy->debuff.burn * 5) + Enemy->stats.mp) >
                Enemy->stats.max_mp) {
                // Only add as much mp as The Flame Wolf can hold
                while (Enemy->stats.mp <= Enemy->stats.max_mp) {
                    Enemy->stats.mp += 5;
                    Enemy->debuff.burn--;
                }
                // Stop mp from overflowing
                Enemy->stats.mp = Enemy->stats.max_mp;
            }
            // Otherwise eat up all the burn into mp
            else {
                Enemy->stats.mp = (Enemy->debuff.burn * 5) + Enemy->stats.mp;
                Enemy->debuff.burn = 0;
            }
            Enemy->stats.temp_atk = 0;
            printf("The Flame Wolf drank the flames");
        }
        // If the decision is 3 and the Flame Wolf has 10 or more mana
        else if (decision > 2 && Enemy->stats.mp >= 10) {
            // Flame wolf does extra damage equal to its burn for 10 mana
            Enemy->stats.temp_atk = Enemy->stats.temp_atk + Enemy->debuff.burn;
            Enemy->stats.mp = Enemy->stats.mp - 10;
            // And deals 1/2 of its burn to the Hero
            Hero->debuff.burn += (Enemy->debuff.burn * 0.5);
            printf("The Flame Wolf slices with its fiery claws");
        }
        // If the enemy has burn
        else if (Enemy->debuff.burn > 0) {
            // Flame wolf burns hotter getting more burn
            // Dealing damage equal to burn
            // And adding a bit of mana
            Enemy->debuff.burn += 3;
            Enemy->stats.temp_atk = Enemy->debuff.burn;
            Enemy->stats.mp += 5;
            printf("The Flame Wolf burns hotter!");
        }
        // If The Fire Wolf has no burn and no mana
        else {
            printf("The Flame Wolf slices with its claws");
        }
    }

    // Slime AI
    else if (Enemy->stats.enemy_type == 3) {

        // If Slimes have less hp than they should
        while (((Enemy->gimmick.multiply - 1) * 20) > Enemy->stats.hp) {
            // A Slime is murdered
            Enemy->gimmick.multiply -= 1;
            Enemy->stats.max_hp -= 20;
            Enemy->debuff.burn = 0;
            Enemy->debuff.chill = 0;
            Enemy->debuff.poison = 0;
            Enemy->debuff.slime = 0;
        }

        // For each Slime
        for (int i = 0; i < Enemy->gimmick.multiply; i++) {

            // If there is more than one Slime
            if (Enemy->gimmick.multiply > 1) {

                // If The Hero has no slime
                if (Hero->debuff.slime == 0) {
                    // Add 4 slime and 0 dmg
                    printf("Slime %d slimes you", i + 1);
                    Enemy->stats.temp_atk = 0;
                    Hero->debuff.slime = 4;
                }

                // If The Hero has less than 5 slime
                else if (Hero->debuff.slime < 5) {
                    // Add 2 slime and deal normal dmg
                    printf("Slime %d attempts to engulf you", i + 1);
                    Hero->debuff.slime += 2;
                }

                // If The Hero has less than 10 slime
                else if (Hero->debuff.slime < 10) {
                    // Add 2 slime and deal double dmg
                    printf("Slime %d surrounds you", i + 1);
                    Hero->debuff.slime += 2;
                    Enemy->stats.temp_atk *= 2;
                }

                // Otherwise
                else {
                    // Add 2 slime and deal triple dmg
                    printf(
                        "Slime %d completely surrounds you and grows", i + 1
                    );
                    Hero->debuff.slime += 2;
                    Enemy->stats.temp_atk *= 3;
                    Enemy->stats.hp += 5;
                }
                if (i != Enemy->gimmick.multiply) {
                    printf("\n");
                }
            }

            // Otherwise
            else {

                // If The Hero has no slime
                if (Hero->debuff.slime == 0) {
                    printf("A Slime slimes you");
                    Enemy->stats.temp_atk = 0;
                    Hero->debuff.slime = 4;
                }

                // If The Hero has less than 5 slime
                else if (Hero->debuff.slime < 5) {
                    // Add 2 slime and deal normal dmg
                    printf("A Slime attempts to engulf you", i);
                    Hero->debuff.slime += 2;
                }

                // If The Hero has less than 10 slime
                else if (Hero->debuff.slime < 10) {
                    // Add 2 slime and deal double dmg
                    printf("A Slime %d surrounds you", i);
                    Hero->debuff.slime += 2;
                    Enemy->stats.temp_atk *= 2;
                }

                // Otherwise
                else {
                    // Add 2 slime and deal triple dmg
                    printf("A Slime %d completely surrounds you and grows", i);
                    Hero->debuff.slime += 2;
                    Enemy->stats.temp_atk *= 3;
                    Enemy->stats.hp += 5;
                }
            }
        }

        // If Slimes have more hp than they should
        while ((Enemy->gimmick.multiply * 20) < Enemy->stats.hp) {
            // Make a new slime
            Enemy->gimmick.multiply += 1;
            Enemy->stats.max_hp += 20;
            printf("A new slime spawns!");
            // If slimes still have more hp than they should, put it equal to
            // their max hp
            if (Enemy->stats.hp > Enemy->stats.max_hp) {
                Enemy->stats.hp = Enemy->stats.max_hp;
            }
        }
    }

    // Enemy calculations
    // If Enemy didn't do any damage
    if (Enemy->stats.temp_atk <= 0) {
        printf("\n");
    }
    // If Enemy did less damage than the Hero's defense then deal one damage
    else if (Enemy->stats.temp_atk < Hero->stats.temp_def) {
        printf(" for 1 damage\n");
        Hero->stats.hp = Hero->stats.hp - 1;
    }
    // Otherwise calculate and print damage normally
    // (Enemy attack - Hero defense)
    else {
        printf(
            " for %d damage\n", (Enemy->stats.temp_atk - Hero->stats.temp_def)
        );
        Hero->stats.hp =
            Hero->stats.hp - Enemy->stats.temp_atk + Hero->stats.temp_def;
    }

    // Check if it is a bunny if so make bunny pictures
    if (Enemy->stats.enemy_type == 1) {
        // If bunny is in a rage print rage bunny
        if (Enemy->buff.frenzy > 0) {
            assets(2);
        }
        // Otherwise it prints regular bunny
        else {
            assets(1);
        }
    }

    // Check if it is a Fire Wolf if so make wolf pictures
    else if (Enemy->stats.enemy_type == 2) {
        // If Fire Wolf is on fire print Fire Wolf(Ignited)
        if (Enemy->debuff.burn > 0) {
            assets(3);
        }
        // Otherwise it prints Fire Wolf(Unignited)
        else {
            assets(4);
        }
    }

    // Check if it is a Slime if so make slime pictures
    else if (Enemy->stats.enemy_type == 3) {
        // If one slime
        if (Enemy->gimmick.multiply == 1) {
            assets(6);
        }
        // If two slime
        else if (Enemy->gimmick.multiply == 2) {
            assets(7);
        }
        // If more slime
        else {
            assets(8);
        }
    }
}
