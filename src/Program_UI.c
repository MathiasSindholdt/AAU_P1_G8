#include "Program_UI.h"
#include "Data_Types.h"
#include "Program_File_Handling.h"
#include "Program_UI.h"
#include "sorting_reccomendations.h"
#include <stdio.h>
#include <stdlib.h>

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
