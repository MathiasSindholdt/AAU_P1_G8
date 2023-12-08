#include <stdio.h>
#include <stdlib.h>
#include "Data_Types.h"
#include "Program_UI.h"
#include "Program_File_Handling.h"
#include "sorting_reccomendations.h"

Choice_Vector User_Choices;


int main() {
    Clear_Screen();
    answerQuestionnaire(User_Choices);
    Education ed[4];
	for (int i=0; i<4; i++) {
        ed[i] = Read_Education_File(i);
    }
    Choice_Vector usr = Read_User_Data();
    //display_results(ed, usr);
    KNN(User_Choices, ed, sizeof(ed)/sizeof(ed[0]));

    display_results(ed, User_Choices);
	for (int i=0; i<4; i++) {
        ed[i] = Read_Education_File(i);
    }

    KNN(usr, ed, sizeof(ed)/sizeof(ed[0]));
    display_results(ed, usr);
}
