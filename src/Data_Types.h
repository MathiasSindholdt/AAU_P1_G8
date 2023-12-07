#ifndef Data_Type_H
#define Data_Type_H

typedef struct  {
    double grade;
    int Answer[15];
    char requirelvl;
    int requiregrade;
}Choice_Vector;

typedef struct  {
    double avg;
    char level;
    int grade;
}Requirements;


typedef struct{
  char Name[70];
  char Info[200];
  char Location[25];
  Choice_Vector choice_vector;
  int requirement_bool;
  Requirements Requirements;
  char tags[30];
  double knn;
}Education;
#endif
