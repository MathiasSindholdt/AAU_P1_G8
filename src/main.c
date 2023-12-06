#include <stdio.h>
#include <stdlib.h>
#include "Data_Types.h"
#include "Program_UI.h"
#include "Program_File_Handling.h"
#include "sorting_reccomendations.h"

Choice_Vector User_Choices;


int main() {
    Education ed[4];
	for (int i=0; i<4; i++) {
        ed[i] = Read_Education_File(i);
    }
    Choice_Vector usr = {1,2,3,4,5,6,7,8,9,0,1,2,3,4};
    display_results(ed);
    KNN(usr, ed, sizeof(ed)/sizeof(ed[0]));
    display_results(ed);
}
