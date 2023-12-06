#include "sorting_reccomendations.h"
#include "Data_Types.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
// here knn will be implemented


/*
** this function is an implementaion of knn
** @Param Choice_Vector that contains the user's answers from the questionaire
** @Param Education* that contains the educations loaded from files
*/
int KNN(Choice_Vector user_choices, Education* educations, int length) {
    float sum = 0;

    int edu_choice;
    int usr_choice;

    for (int j = 0; j < 4; j++) {
        for (int i = 0; i < 14; i++) {
            edu_choice = educations[j].choice_vector.Answer[i]; // assigns answer from choice vector to edu_choice
            usr_choice =  user_choices.Answer[i]; // assigns user answer to usr_choice
            sum += pow((edu_choice - usr_choice), 2); // adds (a_1 - b_1)^2 to a running sum
            }
        educations[j].knn = sqrt(sum); // assings the square root of the sum to the knn value in the education struct
        sum = 0;
    }
    educations = edu_Sort(educations, length);
    return 0;
}

int display_results(Education *educations){
    for (int i = 0; i < 3; i++) {
        printf("%s | %s | %s | %f \n",educations[i].Name,educations[i].Info,educations[i].Location, educations[i].knn);
    }
   return 0;
}

//Make length dynamic

/*
** This function sorts the recommendations based on thier knn value
** @Param education array is the array which needs to be sorted
*/
Education* edu_Sort(Education *arr, int length)
{
    Education *temp = malloc(sizeof(arr)/sizeof(arr[0]));
    temp = arr;
    int i = 0 , j = 0;
    Education tmp;

    printf("\n%d\n",length);
    do
    {
        for(j = 0; j < length; j++){
          if(temp[i].knn < temp[j].knn){
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
