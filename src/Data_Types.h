typedef struct  {
    double avg; // always saved in the [0] index
    char level;
    int grade;
}Subject;

typedef struct  {
    int Answer[20];
}Choice_Vector;

typedef struct  {
    Subject subjects[4];
}Requirements;


typedef struct{
  char Name[70];
  char Info[200];
  char Location[25];
  Choice_Vector choice_vector;
  Requirements req;
  char tags[30];
}Education;
