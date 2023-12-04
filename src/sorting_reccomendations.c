#include "sorting_reccomendations.h"
#include "Data_Types.h"
#include <math.h>

// here knn will be implemented


/*
** this function is an implementaion of knn
** @Param Choice_Vector that contains the user's answers from the questionaire
** @Param Education* that contains the educations loaded from files
*/
int KNN(Choice_Vector user_choices, Education* educations) {
    float sum = 0;
    for (int j = 0; j < 75; j++) {
        for (int i = 0; i < 14; i++) {
            sum += powf(educations[j].choice_vector.Answer[i] - user_choices.Answer[i], 2);
            }
        educations[j].knn = sqrtf(sum);
    }

    return 0;
}
