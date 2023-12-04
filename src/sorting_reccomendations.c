#include "sorting_reccomendations.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
// here knn will be implemented

/*
** this function is an implementaion of knn
** @Param Choice_Vector that contains the user's answers from the questionaire
** @Param Education* that contains the educations loaded from files
*/
int KNN(Choice_Vector user_choices, Education* educations) {
    float sum = 0;
    int edu_choice;
    int usr_choice;
    for (int j = 0; j < 4; j++) {
        for (int i = 0; i < 14; i++) {
            edu_choice = educations[j].choice_vector.Answer[i]; // assigns answer from choice vector to edu_choice
            usr_choice =  user_choices.Answer[i]; // assigns user answer to usr_choice
            sum += pow((edu_choice - usr_choice), 2); // adds (a_1 - b_1)^2 to a running sum
            printf("%d $$ %d \n",edu_choice,usr_choice);
            }
        printf("############### %f\n",sum);
        educations[j].knn = sqrt(sum); // assings the square root of the sum to the knn value in the education struct
        sum = 0;
        printf("############### %f\n",educations[j].knn);

    }
    mergeSort(educations, 0, 13);

    return 0;
}

int display_results(Education *educations){
    for (int i = 0; i < 4; i++) {
        printf("%s | %s | %s | %f \n",educations[i].Name,educations[i].Info,educations[i].Location, educations[i].knn);
    }
   return 0;
}



void mergeSort(Education arr[], int l, int r)
{
    if (l < r) {
        int m = l + (r - l) / 2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

void merge(Education arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // Create temp arrays
    int L[n1], R[n2];

    // Copy data to temp arrays L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i].knn;
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j].knn;

    // Merge the temp arrays back into arr[l..r
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k].knn = L[i];
            i++;
        }
        else {
            arr[k].knn = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[],
    // if there are any
    while (i < n1) {
        arr[k].knn = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[],
    // if there are any
    while (j < n2) {
        arr[k].knn = R[j];
        j++;
        k++;
    }
}
