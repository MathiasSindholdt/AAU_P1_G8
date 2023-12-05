#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct GradeInput {
    double grade;
};

struct QuestionnaireAnswers {
    int locationPreference;     // Example: 1 for Aalborg, 2 for Aarhus, 3 for Copenhagen
    int creativeInterest;       // Humanistic and creative field
    int technicalInterest;      // Technical and scientific disciplines
    int teamworkPreference;     // Thriving in a learning environment with other students
    int itInterest;             // Interest in IT
    int jobPriority;            // Priority on securing a job quickly
    int salaryPriority;         // Priority on salary
    int independencePreference; // Preference for working independently
    int practicalExperienceValue;// Value placed on practical experience and application of theory
    int societyInterest;        // Fascination with society-related problems and solutions
    int scientificInterest;     // Fascination with contributing to scientific discoveries
    int careFulfillment;        // Fulfillment in working closely with individuals and ensuring well-being
    int mathFascination;        // Fascination with mathematics
    int passedMathA;            // Yes (1) or No (0) for passing mathematics A
    int languages;              // Have interest in cultures and languages
    int businessEcon;           // Have interest in economics and business
};

struct UserProfile {
    char name[50];
    struct GradeInput grades;
    struct QuestionnaireAnswers answers;
};

// Function to input and edit grades
void inputGrades(struct GradeInput *grades) {
    printf("Enter your grade: ");
    scanf("%lf", &grades->grade);
}

void askQuestion(const char *question, int *answer, int min, int max) {
    int input;
    while (1) {
        printf("%s", question);
        if (scanf("%d", &input) == 1) {
            // Check if the input is within the specified range
            if (input >= min && input <= max) {
                *answer = input;
                break; // Valid input, exit the loop
            } else {
                printf("Invalid input. Please enter a number between %d and %d.\n", min, max);
            }
        } else {
            printf("Invalid input. Please enter a valid integer.\n");
            // Clear the input buffer to prevent an infinite loop
            while (getchar() != '\n');
        }
    }
}

void answerQuestionnaire(struct QuestionnaireAnswers *answers) {
    askQuestion("Have you passed mathematics A? (Yes: 1, No: 0): ", &answers->passedMathA, 0, 1);

    askQuestion("Select your preferred location (1: Aalborg, 2: Aarhus, 3: Copenhagen): ", &answers->locationPreference, 1, 3);

    printf("Answer the following questions on a scale of 1 to 5:\n");

    askQuestion("I am interested in the humanistic and creative field: ", &answers->creativeInterest, 1, 5);
    askQuestion("I prefer technical and scientific disciplines: ", &answers->technicalInterest, 1, 5);
    askQuestion("I thrive best in a learning environment where I have the opportunity to work with other students: ", &answers->teamworkPreference, 1, 5);
    askQuestion("I am interested in IT: ", &answers->itInterest, 1, 5);
    askQuestion("I prefer to work independently and autonomously while studying: ", &answers->independencePreference, 1, 5);
    askQuestion("I value practical experience and the application of theory in real situations highly: ", &answers->practicalExperienceValue, 1, 5);
    askQuestion("I am fascinated by society-related problems and solutions: ", &answers->societyInterest, 1, 5);
    askQuestion("I am fascinated by the opportunity to contribute to scientific discoveries and progress: ", &answers->scientificInterest, 1, 5);
    askQuestion("I am interested in economics and business: ", &answers->businessEcon, 1, 5);
    askQuestion("I am fascinated by mathematics: ", &answers->mathFascination, 1, 5);
    askQuestion("I find fulfillment in working closely with individuals, providing care, and ensuring their well-being: ", &answers->careFulfillment, 1, 5);
    askQuestion("I have interest in cultures and languages: ", &answers->languages, 1, 5);
    askQuestion("It is predominantly important for me to secure a job quickly: ", &answers->jobPriority, 1, 5);
    askQuestion("Salary is predominantly important to me: ", &answers->salaryPriority, 1, 5);
}


// Function to save user profiles
void saveProfile(const char *fileName, const struct UserProfile *profiles, int numProfiles, int firstExit) {
    FILE *file;

    if (firstExit) {
        file = fopen(fileName, "w");  // Use "w" to overwrite the file
    } else {
        file = fopen(fileName, "a");  // Use "a" to append to the file
    }
    if (file != NULL) {
        fprintf(file, "%d\n", numProfiles);

        for (int i = 0; i < numProfiles; i++) {
            fprintf(file, "%s\n", profiles[i].name);
            fprintf(file, "%.2f\n", profiles[i].grades.grade);
            fprintf(file, "%d\n", profiles[i].answers.passedMathA);
            fprintf(file, "%d\n", profiles[i].answers.creativeInterest);
            fprintf(file, "%d\n", profiles[i].answers.locationPreference);
            fprintf(file, "%d\n", profiles[i].answers.technicalInterest);
            fprintf(file, "%d\n", profiles[i].answers.teamworkPreference);
            fprintf(file, "%d\n", profiles[i].answers.itInterest);
            fprintf(file, "%d\n", profiles[i].answers.independencePreference);
            fprintf(file, "%d\n", profiles[i].answers.practicalExperienceValue);
            fprintf(file, "%d\n", profiles[i].answers.societyInterest);
            fprintf(file, "%d\n", profiles[i].answers.scientificInterest);
            fprintf(file, "%d\n", profiles[i].answers.businessEcon);
            fprintf(file, "%d\n", profiles[i].answers.mathFascination);
            fprintf(file, "%d\n", profiles[i].answers.careFulfillment);
            fprintf(file, "%d\n", profiles[i].answers.languages);
            fprintf(file, "%d\n", profiles[i].answers.jobPriority);
            fprintf(file, "%d\n", profiles[i].answers.salaryPriority);
        }
        fclose(file);
    }
}

void loadProfiles(const char *fileName, struct UserProfile *profiles, int *numProfiles) {
    FILE *file = fopen(fileName, "r");
    if (file != NULL) {
        fscanf(file, "%d", numProfiles);

        for (int i = 0; i < *numProfiles && i < 25; i++) {
            fscanf(file, "%s", profiles[i].name);
            fscanf(file, "%f", &profiles[i].grades.grade);
            fscanf(file, "%d", &profiles[i].answers.passedMathA);
            fscanf(file, "%d", &profiles[i].answers.locationPreference);
            fscanf(file, "%d", &profiles[i].answers.creativeInterest);
            fscanf(file, "%d", &profiles[i].answers.technicalInterest);
            fscanf(file, "%d", &profiles[i].answers.teamworkPreference);
            fscanf(file, "%d", &profiles[i].answers.itInterest);
            fscanf(file, "%d", &profiles[i].answers.independencePreference);
            fscanf(file, "%d", &profiles[i].answers.practicalExperienceValue);
            fscanf(file, "%d", &profiles[i].answers.societyInterest);
            fscanf(file, "%d", &profiles[i].answers.scientificInterest);
            fscanf(file, "%d", &profiles[i].answers.businessEcon);
            fscanf(file, "%d", &profiles[i].answers.mathFascination);
            fscanf(file, "%d", &profiles[i].answers.careFulfillment);
            fscanf(file, "%d", &profiles[i].answers.languages);
            fscanf(file, "%d", &profiles[i].answers.jobPriority);
            fscanf(file, "%d", &profiles[i].answers.salaryPriority);
        }
        fclose(file);
    }
}

// Function to display user profiles
void displayProfiles(const struct UserProfile *profiles, int numProfiles) {
    printf("\n----- User Profiles -----\n");

    // Prompt the user for a profile name
    char searchName[50];
    printf("Enter the name of the profile to display: ");
    scanf("%s", searchName);

    int found = 0;

    for (int i = 0; i < numProfiles; i++) {
        if (strcmp(profiles[i].name, searchName) == 0) {
            printf("Profile Name: %s\n", profiles[i].name);
            printf("Grade: %.2f\n", profiles[i].grades.grade);

            printf("Passed Mathematics A: %s\n", profiles[i].answers.passedMathA ? "Yes" : "No");
            printf("Location Preference: %d\n", profiles[i].answers.locationPreference);
            printf("Creative Interest: %d\n", profiles[i].answers.creativeInterest);
            printf("Technical Interest: %d\n", profiles[i].answers.technicalInterest);
            printf("Teamwork Preference: %d\n", profiles[i].answers.teamworkPreference);
            printf("IT Interest: %d\n", profiles[i].answers.itInterest);
            printf("Job Priority: %d\n", profiles[i].answers.jobPriority);
            printf("Salary Priority: %d\n", profiles[i].answers.salaryPriority);
            printf("Independence Preference: %d\n", profiles[i].answers.independencePreference);
            printf("Practical Experience Value: %d\n", profiles[i].answers.practicalExperienceValue);
            printf("Society Interest: %d\n", profiles[i].answers.societyInterest);
            printf("Scientific Interest: %d\n", profiles[i].answers.scientificInterest);
            printf("Care Fulfillment: %d\n", profiles[i].answers.careFulfillment);
            printf("Economics and Business: %d\n", profiles[i].answers.businessEcon);
            printf("Care Fulfillment: %d\n", profiles[i].answers.languages);
            printf("Math Fascination: %d\n", profiles[i].answers.mathFascination);
            printf("\n");

            found = 1;
            break;  // Stop searching once the profile is found
        }
    }
    if (!found) {
        printf("Profile not found.\n");
    }
}