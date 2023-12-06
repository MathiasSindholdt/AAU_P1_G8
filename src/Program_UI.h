#include "Data_Types.h"
void Clear_Screen();

void inputGrades(GradeInput *grades);

void askQuestion(const char *question, int *answer, int min, int max);

void answerQuestionnaire(QuestionnaireAnswers *answers);

void saveProfile(const char *fileName, UserProfile *profiles);

void loadProfiles(const char *fileName, UserProfile *profiles, int *numProfiles);

void displayProfiles(UserProfile *profiles, int numProfiles);
