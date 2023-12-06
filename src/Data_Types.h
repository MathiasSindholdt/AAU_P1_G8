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
  int requirement_bool;
  Requirements Requirements;
  char tags[30];
}Education;

typedef struct {
    double grade;
}GradeInput;

typedef struct {
    int locationPreference;
    int creativeInterest;       
    int technicalInterest;      
    int teamworkPreference;     
    int itInterest;             
    int jobPriority;            
    int salaryPriority;         
    int independencePreference; 
    int practicalExperienceValue;
    int societyInterest;        
    int scientificInterest;     
    int careFulfillment;        
    int mathFascination;        
    int passedMathA;            
    int languages;              
    int businessEcon;           
}QuestionnaireAnswers;

typedef struct {
    char name[50];
    GradeInput grades;
    QuestionnaireAnswers answers;
}UserProfile;
