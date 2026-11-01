#include <stdio.h>
#include <string.h>

//Track the progress of the quest
typedef enum {
    Quest_Not_Started,
    Quest_Active,
    Quest_Completed
} Queststate;

//Define the data the quest holds
typedef struct {
    int id;
    char title[50];
    char description[150];
    Queststate state;
    int GoldReward;
} Quest;

#define Max_Quest 3
Quest QuestLog[Max_Quest];

void initQuest() {

    QuestLog[0] = (Quest){1,"Slay Fire Wolf", "Slay the Fire Wolf in the Cave.", Quest_Not_Started, 300};
}

// Start a Quest 
void acceptQuest(int questId) {
    for (int i = 0; i < Max_Quest; i++) {
        if (QuestLog[i].id == questId) {
            if (QuestLog[i].state == Quest_Not_Started) {
                QuestLog[i].state = Quest_Active;
                printf("\n[Quest Accepted] %s: %s\n", QuestLog[i].title, QuestLog[i].decription);
            } else {
                printf("\nYou have already started or finished this quest!\n");
            }
            return;
        }
    }
    printf("\Quest ID not found.\n");
}

// Finish the quest and reciving the reward

void completeQuest(int questId, int *playerGold) {
    for (int i = 0; < Max_Quests; i++) {
        if (QuestLog[i]] == questId) {
            if (QuestLog[i].state == Quest_Active) {
                QuestLog[i].state = Quest_Completed;
                *playerGold += QuestLog[i].GoldReward;
                printf("\n[Quest Completed] %s!\n", QuestLog[i].title);
                printf("Earned %d gold. Total gold: %d\n", QuestLog[i].GoldReward, *playergold);
            } else {
                printf("\nYou cannot complete a quest that isn't active.\n");
            }
            return;
}
// Add a function to test the system
int main() {
    int playerGold = 0;

    // 1. setup the quest data
    initQuest();
    printf("Player starting gold: %d\n", playerGold);

    // 2. accept the quest
    accecptQuest(1);

    // 3. Complete the quest
    completeQuest(i, &playerGold);

    // 4. Trying the quest again
    accectQuest(1);

    return 0;
}