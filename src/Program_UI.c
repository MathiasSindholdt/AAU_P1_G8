#include "Program_UI.h"
#include "Data_Types.h"
#include "Program_File_Handling.h"
#include "Program_UI.h"
#include "sorting_reccomendations.h"
#include <stdio.h>
#include <stdlib.h>

/* typedef struct { */
/*     double grade; */
/* }GradeInput; */

/* typedef struct { */
/*     int locationPreference;     // Example: 1 for Aalborg, 2 for Aarhus, 3
 * for Copenhagen */
/*     int creativeInterest;       // Humanistic and creative field */
/*     int technicalInterest;      // Technical and scientific disciplines */
/*     int teamworkPreference;     // Thriving in a learning environment with
 * other students */
/*     int itInterest;             // Interest in IT */
/*     int jobPriority;            // Priority on securing a job quickly */
/*     int salaryPriority;         // Priority on salary */
/*     int independencePreference; // Preference for working independently */
/*     int practicalExperienceValue;// Value placed on practical experience and
 * application of theory */
/*     int societyInterest;        // Fascination with society-related problems
 * and solutions */
/*     int scientificInterest;     // Fascination with contributing to
 * scientific discoveries */
/*     int careFulfillment;        // Fulfillment in working closely with
 * individuals and ensuring well-being */
/*     int mathFascination;        // Fascination with mathematics */
/*     int passedMathA;            // Yes (1) or No (0) for passing mathematics
 * A */
/*     int languages;              // Have interest in cultures and languages */
/*     int businessEcon;           // Have interest in economics and business */
/* }QuestionnaireAnswers; */

/* typedef struct { */
/*     char name[50]; */
/*     GradeInput grades; */
/*     QuestionnaireAnswers answers; */
/* }UserProfile; */

// Function to input and edit grades
// @Returns double that represents the user's grade
double input_Grades() {
  double grades;
  printf("Enter your grade: ");
  scanf("%lf", &grades); // note that if the user uses , this will only read the
                         // first part of the number i.e. only the x in x,y
  return grades;
}

void Clear_Screen() { printf("\e[1;1H\e[2J"); }

/*
** this function handles the question functionallity of the questionnaire.
** @Param a string that contains the question
** @Param int pointer that represents the answer
** @Param int minimal value user can input
** @Param int Max value user can input
 */
void ask_Question(char *question, int *answer, int min, int max) {
  int input;
  while (1) {
    Clear_Screen();
    printf("%s", question);
    if (scanf("%d", &input) == 1) {
      // Check if the input is within the specified range
      if (input >= min && input <= max) {
        *answer = input;
        break; // Valid input, exit the loop
      } else {
        printf("Invalid input. Please enter a number between %d and %d.\n", min,
               max);
      }
    } else {
      printf("Invalid input. Please enter a valid integer.\n");
      // Clear the input buffer to prevent an infinite loop
      while (getchar() != '\n')
        ;
    }
  }
}
 /*
 ** this function handles the questionanire part of the program
 ** @Param Choice vector that represents the user
 ** @Returns a modified choice vector
  */
Choice_Vector Questionnaire(Choice_Vector usr) {
  /* askQuestion("Have you passed mathematics A? (Yes: 1, No: 0): ",
   * &answers->passedMathA, 0, 1); */

  /* askQuestion("Select your preferred location (1: Aalborg, 2: Aarhus, 3:
   * Copenhagen): ", &answers->locationPreference, 1, 3); */

  /* printf("Answer the following questions on a scale of 1 to 5:\n"); */

  /* askQuestion("I am interested in the humanistic and creative field: ",
   * &answers->creativeInterest, 1, 5); */
  /* askQuestion("I prefer technical and scientific disciplines: ",
   * &answers->technicalInterest, 1, 5); */
  /* askQuestion("I thrive best in a learning environment where I have the
   * opportunity to work with other students: ", &answers->teamworkPreference,
   * 1, 5); */
  /* askQuestion("I am interested in IT: ", &answers->itInterest, 1, 5); */
  /* askQuestion("I prefer to work independently and autonomously while
   * studying: ", &answers->independencePreference, 1, 5); */
  /* askQuestion("I value practical experience and the application of theory in
   * real situations highly: ", &answers->practicalExperienceValue, 1, 5); */
  /* askQuestion("I am fascinated by society-related problems and solutions: ",
   * &answers->societyInterest, 1, 5); */
  /* askQuestion("I am fascinated by the opportunity to contribute to scientific
   * discoveries and progress: ", &answers->scientificInterest, 1, 5); */
  /* askQuestion("I am interested in economics and business: ",
   * &answers->businessEcon, 1, 5); */
  /* askQuestion("I am fascinated by mathematics: ", &answers->mathFascination,
   * 1, 5); */
  /* askQuestion("I find fulfillment in working closely with individuals,
   * providing care, and ensuring their well-being: ",
   * &answers->careFulfillment, 1, 5); */
  /* askQuestion("I have interest in cultures and languages: ",
   * &answers->languages, 1, 5); */
  /* askQuestion("It is predominantly important for me to secure a job quickly:
   * ", &answers->jobPriority, 1, 5); */
  /* askQuestion("Salary is predominantly important to me: ",
   * &answers->salaryPriority, 1, 5); */
  usr.grade = input_Grades();
  ask_Question(Read_Question(0), &usr.Answer[0], 0, 1);
  ask_Question(Read_Question(1), &usr.Answer[1], 1, 3);

  for (int i = 2; i < 16; i++) {
    ask_Question(Read_Question(i), &usr.Answer[i], 1, 5);
  }

  if (usr.Answer[0] == 1) {
    usr.slvl = 'A';
    Clear_Screen();
    printf("what grade did you get in mathematics\n");
    scanf("%d", &usr.sgrade);
  } else if (usr.Answer[0] == 0) {
    usr.slvl = 'B';
    Clear_Screen();
    printf("what grade did you get in mathematics");
    scanf("%d", &usr.sgrade);
  }
  return usr;
}
// Function to save user profiles
/* void saveProfile(const char *fileName, UserProfile *profiles) { */
/*     FILE *file = fopen("profiles.txt", "w"); */

/*     if (file != NULL) { */
/*         fprintf(file, "%.2lf, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d,
 * %d, %d, %d, %d~", */
/*                 profiles->grades.grade, profiles->answers.passedMathA, */
/*                 profiles->answers.locationPreference,
 * profiles->answers.creativeInterest, */
/*                 profiles->answers.technicalInterest,
 * profiles->answers.teamworkPreference, */
/*                 profiles->answers.itInterest,
 * profiles->answers.independencePreference,
 * profiles->answers.practicalExperienceValue, */
/*                 profiles->answers.societyInterest,
 * profiles->answers.scientificInterest, profiles->answers.businessEcon, */
/*                 profiles->answers.mathFascination,
 * profiles->answers.careFulfillment, profiles->answers.languages, */
/*                 profiles->answers.jobPriority,
 * profiles->answers.salaryPriority); */
/*         fclose(file); */
/*         printf("Profile has been saved.\n"); */
/*     } else { */
/*         printf("Error: Unable to save profile.\n"); */
/*     } */
/* } */

/* void loadProfiles(const char *fileName, UserProfile *profiles, int
 * *numProfiles) { */
/*     FILE *file = fopen(fileName, "r"); */
/*     if (file != NULL) { */
/*         fscanf(file, "%d", numProfiles); */

/*         for (int i = 0; i < *numProfiles && i < 25; i++) { */
/*             fscanf(file, "%lf, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d,
 * %d, %d, %d, %d, %d, %d", */
/*                    &profiles[i].grades.grade,
 * &profiles[i].answers.passedMathA, */
/*                    &profiles[i].answers.locationPreference,
 * &profiles[i].answers.creativeInterest, */
/*                    &profiles[i].answers.technicalInterest,
 * &profiles[i].answers.teamworkPreference, */
/*                    &profiles[i].answers.itInterest,
 * &profiles[i].answers.jobPriority, */
/*                    &profiles[i].answers.salaryPriority,
 * &profiles[i].answers.independencePreference, */
/*                    &profiles[i].answers.practicalExperienceValue,
 * &profiles[i].answers.societyInterest, */
/*                    &profiles[i].answers.scientificInterest,
 * &profiles[i].answers.businessEcon, */
/*                    &profiles[i].answers.mathFascination,
 * &profiles[i].answers.careFulfillment, */
/*                    &profiles[i].answers.languages); */
/*         } */
/*         fclose(file); */
/*     } */
/* } */


/*
** this functions displays the full list of educations.
** @Param int that represents the number of educations.
 */
void full_list(int number_of_educations) {
  while (1) {
    Clear_Screen();
    Education educations[number_of_educations];
    for (int i = 1; i < number_of_educations; i++) {
      educations[i] = Read_Education_File(i-1);
    }

    for (int i = 1; i < number_of_educations; i++) {
      printf("%s | %s | %s \n", educations[i].Name, educations[i].Info,
             educations[i].Location);
    }

    int code = display_Long_edu(educations);
    if (code == 2) {
      break;
    }
  }
}
