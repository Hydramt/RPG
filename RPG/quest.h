#ifndef QUEST_H
#define QUEST_H

#define Max_Quest 3

// Quest status
typedef enum {
    Quest_Not_Started,
    Quest_Active,
    Quest_Completed
} Queststate;

// Information stored for each quest
typedef struct {
    int id;
    char title[50];
    char description[150];
    Queststate state;
    int GoldReward;
} Quest;

// Quest functions
void initQuest(Quest QuestLog[Max_Quest]);

void acceptQuest(int questId, Quest QuestLog[Max_Quest]);

void completeQuest(int questId, int* playerGold, Quest QuestLog[Max_Quest]);

#endif