#ifndef Data_Type_H
#define Data_Type_H

typedef struct  {
    double grade;
    int Answer[16];
    char slvl;
    int sgrade;
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
  double knn;
  int ident;
}Education;

typedef struct{
  char LName[70];
  char LLoc[200];
  char LInfo[3000];
  char Link[600];
}LongEducation;

#endif
