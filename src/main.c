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
        Read_Education_File(i, *ed);
    }
    Choice_Vector usr;
    display_results(ed);
    KNN(usr, ed);
    display_results(ed);
}
