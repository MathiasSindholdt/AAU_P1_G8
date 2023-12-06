#include "Program_File_Handling.h"
#include <stdio.h>
#include <stdlib.h>
#include "Data_Types.h"
int length_of_choices = 14; // defines  a default value for the amount of choices the player has i.e. the number of questions

/*
 * Saves the users choice profile to a file named "user_data.csv"
 * @Param choice vector
 */
int Save_User_Choices(Choice_Vector choices){
    int length_of_choices = sizeof(choices.Answer)/sizeof(choices.Answer[0]); // creates an int of the lenght of the array
    FILE* user_data =fopen("user_data.csv","w"); // opens the file "user_data.csv" in write mode
    for (int i=0; i<length_of_choices; i++) { // for loop that goes though all elements of the choice vector
        fprintf(user_data,"%d,",choices.Answer[i]); // prints the user choices into the file
    }
    fclose(user_data); // closes the file
    return 0;
}
/*
* Saves the users grades into the file "user_grades.csv"
* @Param array of subjects
*/
int Save_User_Grades(Subject subjects[10]){
    FILE* user_grades = fopen("user_grades.csv","w"); // opens the file "user_grades.csv" in write mode
    fprintf(user_grades,"(%lf),",subjects[0].avg); // prints the users average into the file
    for (int i=0; i<length_of_choices; i++) { // for loop that goes though all elements of the array
        fprintf(user_grades,"(%c,%d),",subjects[i].level,subjects[i].grade); // prints the users subject level and grade into the file
    }
    fclose(user_grades); // closes the file
    return 0;
}
/*
* reads the users grades from a file named user_grades.csv
*/
Subject* Read_User_Grades(){
    Subject subjects[10];
    FILE* user_grades =fopen("user_grades.csv","r"); // opens the file user_grades.csv in read mode
    if (user_grades==NULL) { //checks if file was opened succesfully
        printf("error opening user_grades.csv"); // prints error if neccesary
        exit(EXIT_FAILURE); // exits the program
    }
    fscanf(user_grades,"(%lf),",&subjects[0].avg); // scans the users average from the file
    for (int i=0; i<10; i++) { // for loop that goes though all the users grades
        fscanf(user_grades,"(%c,%d),", &subjects[i].level, &subjects[i].grade); // scans the users subject level and grade
    }
    fclose(user_grades); // closes the file
    return subjects;
}
/*
* reads the users data, i.e. the users choice profile, from the file user_data.csv
*/
Choice_Vector Read_User_Data(){
    length_of_choices = 14;
    char usr_name[30];
    float grades;
    Choice_Vector choices;
    FILE* user_data =fopen("usr_example.txt","r"); // opens the file user_data.csv in read mode
    if (user_data==NULL) { // checks if the file was opened succesfully
        printf("error opening user_data.csv"); // prints error if neccesary
        exit(EXIT_FAILURE); // exits the program
    }
    for (int i=0; i<length_of_choices; i++) { // loop that goes through all the users answers
        fscanf(user_data,"%d,",&choices.Answer[i]); // scans the answer from the file and places it in an array
    }
    fclose(user_data); // closes the file
    return choices;
}
/*
** reads information about an education from a file
** @Param integer value that represents the education
** @Param a Education type that can be written to to store data in memory
 */
Education Read_Education_File(int num){
    Education Ed;
    char buf[20];
    snprintf(buf, 20, "education%d.txt", num); // prints "education{some integer}.txt" to the buffer
    char *file_name = malloc(sizeof(buf) /sizeof(buf[0])); // creates an array the size of the file name in the buffer
    file_name = buf;

    FILE* Education_file = fopen(file_name,"r"); // opens the file in read mode
    if (Education_file==NULL) { // checks if file was opened succesfully
        printf("error opening education%d.txt", num); // prints error if neccesary
        exit(EXIT_FAILURE); // exits the program
    }
    fscanf(Education_file ,"~%[^~]~,", Ed.Name); // scans the name of the education and assigns it

    fscanf(Education_file, "~%[^~]~,", Ed.Info); // scans general info and assigns it

    fscanf(Education_file, "~%[^~]~,", Ed.Location); // scans the location of the education and assings it
    for (int i = 0; i < length_of_choices; i++) { // loop that goes through all questions
        fscanf(Education_file, "%d,",&Ed.choice_vector.Answer[i]); // scans and asings the integer value of the answer
        printf("%d\n", Ed.choice_vector.Answer[i]);
    }
    fscanf(Education_file, "%d,", &Ed.requirement_bool); // scans integer value to check if the education has specific requirements
    if (Ed.requirement_bool) { // checks if eduction has specific requirements
        fscanf(Education_file, "%lf,", &Ed.Requirements.subjects[0].avg); // scans the required average and assigns it
        for (int i = 0; i < 4; i++) { // goes though the number potential subject requirements
            fscanf(Education_file, "%c,%d", &Ed.Requirements.subjects[i].level, &Ed.Requirements.subjects[i].grade); // scans the level and grade requirements and assigns them
        }
    }
    fscanf(Education_file, "~%[^~]~,",Ed.tags); // scans the education's tags
    fclose(Education_file); // closes the file
    return Ed;
}

int Read_Deep_Education_File();
/*
** reads a questionaire question from a file
** @Param integer that identifies the question
 */
char* Read_Question(int Q_num){
    char buf[20];
    snprintf(buf, 20, "question%d.txt", Q_num); // prints "question{some integer}.txt" to buffer
    char *file_name = malloc(sizeof(buf) /sizeof(buf[0])); // creates array the size of the file name
    file_name = buf;

    FILE* Question = fopen(file_name,"r"); // opens the file in read mode
    if (Question==NULL) { // checks was file is opened succesfully
        printf("error opening question%d.txt.csv", Q_num); // prints error if necessary
        exit(EXIT_FAILURE); // exits the program
    }
    char * bigger_buf = malloc(sizeof(char) * 300);
    fscanf(Question,"~%[^~]~,",bigger_buf); // scans question into buffer
    char * final_Question = malloc(sizeof(bigger_buf)/sizeof(bigger_buf[0])); // creates array the size of the question
    final_Question = bigger_buf;

    return final_Question;

}
