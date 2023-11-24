#include "Program_File_Handling.h"
#include <stdio.h>
#include <stdlib.h>

int length_of_choices = 20;

int Save_User_Choices(Choice_Vector choices){
    int length_of_choices = sizeof(choices.Answer)/sizeof(choices.Answer[0]);
    FILE* user_data =fopen("user_data.csv","w");
    for (int i=0; i<length_of_choices; i++) {
        fprintf(user_data,"%d,",choices.Answer[i]);

    }
    fclose(user_data);
    return 0;
}

int Save_User_Grades(Subject subjects[10]){
    FILE* user_grades =fopen("user_grades.csv","w");
    fprintf(user_grades,"(%lf)",subjects[0].avg);
    for (int i=0; i<length_of_choices; i++) {
        fprintf(user_grades,"(%c,%d),",subjects[i].level,subjects[i].grade);
    }
    fclose(user_grades);
    return 0;
}

Subject* Read_User_Grades_From_File(){
    Subject subjects[10];
    FILE* user_grades =fopen("user_grades.csv","r");
    fscanf(user_grades,"(%lf)",&subjects[0].avg);
    for (int i=0; i<length_of_choices; i++) {
        fscanf(user_grades,"(%c,%d),", &subjects[i].level, &subjects[i].grade);
    }
    fclose(user_grades);
    return 0;
}

Choice_Vector Read_User_Data(){
    Choice_Vector choices;
    FILE* user_data =fopen("user_data.csv","r");
    for (int i=0; i<length_of_choices; i++) {
        fscanf(user_data,"%d,",&choices.Answer[i]);

    }
    fclose(user_data);
    return choices;
}

int Read_Education_File();

int Read_Deep_Education_File();
