#ifndef Data_Type_H
#define Data_Type_H
typedef struct  {
    double avg; // always saved in the [0] index
    char level;
    int grade;
}Subject;

typedef struct  {
    double grade;
    int Answer[14];
    char requirelvl;
    int requiregrade;
}Choice_Vector;

typedef struct  {
    Subject subjects;
}Requirements;


typedef struct{
  char Name[70];
  char Info[200];
  char Location[25];
  Choice_Vector choice_vector;
  int requirement_bool;
  Requirements Requirements;
  char tags[30];
  float knn;
}Education;
#endif
