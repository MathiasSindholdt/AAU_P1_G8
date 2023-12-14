#include "sorting_reccomendations.h"
#include "Data_Types.h"
#include "Program_File_Handling.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// here knn will be implemented

/*
** this function is an implementaion of knn
** @Param Choice_Vector that contains the user's answers from the questionaire
** @Param Education* that contains the educations loaded from files
*/
int KNN(Choice_Vector user_choices, Education *educations, int length) {
  float sum = 0;

  int edu_choice;
  int usr_choice;

  for (int j = 1; j < length; j++) {
    educations[j].ident = j; // Gives an identifier for more info
    for (int i = 1; i < 16; i++) {
      edu_choice = educations[j].choice_vector.Answer[i]; // assigns answer from choice
                                                 // vector to edu_choice
      usr_choice = user_choices.Answer[i]; // assigns user answer to usr_choice
      sum += pow((edu_choice - usr_choice), 2); // adds (a_1 - b_1)^2 to a running sum
    }
    educations[j].knn = sqrt(sum); // assings the square root of the sum to the knn value in the education struct
    sum = 0;
  }
  educations = edu_Sort(educations, length);
  return 0;
}

int display_results(Education *educations, Choice_Vector Usr) {
  for (int i = 1; i < 4; i++) {
    if (Usr.grade > educations[i].Requirements.avg &&
        (Usr.slvl == educations[i].Requirements.level || Usr.slvl == 'A') &&
        Usr.sgrade >= educations[i].Requirements.grade) {
      printf("%d | %s | %s | %s | %d \n", educations[i].ident, educations[i].Name, educations[i].Info,
             educations[i].Location, i);
    }
  }
  return 0;
}

/*
** this function displays a long education
**@Param Education array that contains all educations which are used to identifiy which long education file to open
*/
int display_Long_edu(Education *educations) {
  LongEducation LongEd;

  printf("Do you want more information on one of these recommendations? y/n \n");
  char RecYN;
  scanf(" %c", &RecYN);
  if (RecYN == 'y') {
    int anw = 0;
    printf("Which one? \n");
    scanf(" %d", &anw);
    anw = educations[anw].ident;
    LongEd = Read_Long_Education_File(anw);
    printf("%s | %s \n %s \n %s \n", LongEd.LName, LongEd.LLoc, LongEd.LInfo,
           LongEd.Link);
    printf("+------------------------------+");
    printf("\n\n\n 1. Return to reccomendations\n 2. Return to main menu \n "
           "q(uit)");
    char choice;
    scanf(" %c", &choice);
    switch (choice) {
    case '1':
      return 1;
    case '2':
      return 2;
    case 'q':
      exit(0);
    }
  } else if (RecYN == 'n') {
    return 2;
  }else {
    printf("invalid input\n");
      }
}

/*
** This function sorts the recommendations based on thier knn value
** @Param education array is the array which needs to be sorted
*/
Education *edu_Sort(Education *arr, int length) {
  Education *temp = malloc(length * sizeof(Education));
  temp = arr;
  int i = 0, j = 0;
  Education tmp;

  do {
    for (j = 0; j < length; j++) {
      if (temp[i].knn < temp[j].knn) {
        // swap
        tmp = temp[j];
        temp[j] = temp[i];
        temp[i] = tmp;
      }
    }
    i++;
  } while (i < length);
  return temp;
}
