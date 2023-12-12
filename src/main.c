#include "Data_Types.h"
#include "Program_File_Handling.h"
#include "Program_UI.h"
#include "sorting_reccomendations.h"
#include <stdio.h>
#include <stdlib.h>

Choice_Vector User_Choices;
int main() {
  while (1) {

    // printf("1");
    while (1) {
      // printf("2");
      Clear_Screen();
      printf("Guidelines for the Product, Developed by Group 8:\n");
      printf(
          "Our product's primary objective is to assist students in selecting "
          "a suitable higher education option based on their questionnaire "
          "responses.\n");
      printf(
          "Students will receive three tailored recommendations derived from "
          "their answers.\n");
      printf("For those seeking comprehensive information about all available "
             "higher education choices, including additional details, the full "
             "list will be accessible for selection.\n");
      printf(
          "An exit option will also be provided for students who wish to quit "
          "the program.\n");
      printf("Additionally, students can save their choice profile and revisit "
             "the questionnaire to generate three new recommendations based on "
             "altered responses.\n");
      printf("\n+------------------------------+");
      // FILE *test = fopen("data/user/usr_data.txt", "r");
      if (/*test == NULL*/ 0) {
        // fclose(test);
        printf(
            "\n\n\n 1. Answer questionaire \n 2. Show full list \n q(uit) \n");
        char choice;
        scanf("%c", &choice);
        if (choice == '1') {
          User_Choices = answerQuestionnaire(User_Choices);
          break;
        }
        switch (choice) {
        case '2':
          full_list(75);
          break;
        case 'q':
          exit(0);
        }
      } else {
        // fclose(test);
        printf("\n\n\n 1. Answer questionaire (this wil overwrite stored "
               "profile) \n 2. Use existing profile \n 3. Show full list \n "
               "q(uit) \n");
        char choice;
        scanf("%c", &choice);
        switch (choice) {

        case '3':
          full_list(76);
          break;
        case 'q':
          exit(0);
        }
        if (choice == '2') {
          User_Choices = Read_User_Data();
          break;
        } else if (choice == '1') {
          User_Choices = answerQuestionnaire(User_Choices);
          break;
        }
      }
    }

    Education ed[76];
    for (int i = 1; i < 76; i++) {
      ed[i] = Read_Education_File(i - 1);
    }
    Save_User_Choices(User_Choices);

    // Choice_Vector usr = Read_User_Data();
    //  display_results(ed, usr);
    KNN(User_Choices, ed, sizeof(ed) / sizeof(ed[0]));

    // display_results(ed, User_Choices);
    // KNN(usr, ed, sizeof(ed) / sizeof(ed[0]));
    // test(ed);
    int bool = 1;
    while (bool) {
      display_results(ed, User_Choices);
      if (display_Long_edu(ed) == 1) {
        // display_results(ed, User_Choices);
      } else {
        bool = 0;
      }
    }
  }
}
