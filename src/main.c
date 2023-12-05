#include <stdio.h>
#include <stdlib.h>
//#include "Data_Types.h"
#include "Program_UI.h"
#include "Program_File_Handling.h"


Choice_Vector User_Choices;


int main() { 
	struct UserProfile profiles[25];
    int numProfiles = 0;
    int firstExit = 1;

    loadProfiles("profiles.txt", profiles, &numProfiles);

    int choice;
    do {
        printf("\n1. Input/Edit Grades\n");
        printf("2. Answer Questionnaire\n");
        printf("3. Save Profile\n");
        printf("4. Display Profiles\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                inputGrades(&profiles[numProfiles].grades);
                break;
            case 2:
                answerQuestionnaire(&profiles[numProfiles].answers);
                break;
            case 3:
                printf("Enter a name for the profile: ");
                scanf("%s", profiles[numProfiles].name);
                numProfiles++;
                break;
            case 4:
                displayProfiles(profiles, numProfiles);
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid input. Please enter a valid integer.\n");
                while (getchar() != '\n');
        }
    } while (choice != 5);

    saveProfile("profiles.txt", profiles, numProfiles, firstExit);
    firstExit = 0;
}
