#ifndef student_h
#define student_h

//The information of students details 
typedef struct{
    int id;
    char name[20];
    int book_id;
    int gender; //1 for male, 0 for female
    int mobile_number;
    
} STUDENT;

#endif