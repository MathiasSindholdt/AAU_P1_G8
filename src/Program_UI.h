void Clear_Screen();

void inputGrades(struct GradeInput *grades);

void askQuestion(const char *question, int *answer, int min, int max);

void answerQuestionnaire(struct QuestionnaireAnswers *answers);

void saveProfile(const char *fileName, const struct UserProfile *profiles, int numProfiles, int firstExit);

void loadProfiles(const char *fileName, struct UserProfile *profiles, int *numProfiles);

void displayProfiles(const struct UserProfile *profiles, int numProfiles);
