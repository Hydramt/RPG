#include <stdio.h>
#include <string.h>
#include "RPG_Subfunctions.h"
#include "quest.h"

void initQuest(Quest QuestLog[Max_Quest]) {

    QuestLog[0] = (Quest){1,"Slay Fire Wolf", "Slay the Fire Wolf in the Cave.", Quest_Not_Started, 300};
}

// Start a Quest 
void acceptQuest(int questId, Quest QuestLog[Max_Quest]) {
    for (int i = 0; i < Max_Quest; i++) {
        if (QuestLog[i].id == questId) {
            if (QuestLog[i].state == Quest_Not_Started) {
                QuestLog[i].state = Quest_Active;
                printf("\n[Quest Accepted] %s: %s\n", QuestLog[i].title, QuestLog[i].description);
            } else {
                printf("\nYou have already started or finished this quest!\n");
            }
            return;
        }
    }
    printf("\nQuest ID not found.\n");
}

// Finish the quest and reciving the reward

void completeQuest(int questId, int* playerGold, Quest QuestLog[Max_Quest]) {
    for (int i = 0; i < 3; i++) {
        if (QuestLog[i].id == questId) {
            if (QuestLog[i].state == Quest_Active) {
                QuestLog[i].state = Quest_Completed;
                *playerGold += QuestLog[i].GoldReward;
                printf("\n[Quest Completed] %s!\n", QuestLog[i].title);
                printf("Earned %d gold. Total gold: %d\n", QuestLog[i].GoldReward, *playerGold);
            } else {
                printf("\nYou cannot complete a quest that isn't active.\n");
            }
            return;
        }
    }
}
