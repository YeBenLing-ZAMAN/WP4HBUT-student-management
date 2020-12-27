#include <stdio.h>
#include <stdlib.h>
#include "student_section.h"
void student_register_record(ArrList *list)
{
    STUDENT s1;
    int x;
    do
    {
        printf("Enter student ID (maxmimun six digits)\n");
        scanf("%d", &s1.id);
        printf("Enter student Name (Space not allowed)\n");
        scanf("%s", &s1.name);
        s1.book_id = 000000; // 0 means this student is the new member of library -> he don't take any book
        printf("Enter your gender (1 for male, 0 for female)\n");
        scanf("%d", &s1.gender);
        printf("Enter your mobile numeber\n");
        scanf("%d", &s1.mobile_number);
        ArrList_insert(list, 0, s1); // it's always insert 0 index/it's work like a stacks
        printf("\n");
        printf("If you want to continue student insertion press <1> otherwise press <3>\n");
        scanf("%d", &x);
    } while (x == 1);
}

void see_students_record(ArrList *list)
{
    STUDENT b;
    printf("\tStdent id\t\tStudent Name\t\t\t Borrow Book ID\t\tMobile number\t\tGender\n");
    printf("-----------------------------------------------------------------------------------------------------\n");

    for (int i = 0; i < ArrList_size(list); ++i)
    {
        b = ArrList_get(list, i);
        printf("\t%-10d\t\t", b.id);
        printf("%-20s\t\t", b.name);
        printf(" %-9d\t\t", b.book_id);
        printf("%-9d\t\t", b.mobile_number);
        if (b.gender == 1)
            printf("male");
        else
            printf("female");
        printf("\n");
    }
    printf("\n");
}

void delete_student_record(ArrList *list)
{
    int a, flag = -1;
    STUDENT b;
    printf("Enter Student ID : ");
    scanf("%d", &a);
    for (int i = 0; i < ArrList_size(list); ++i)
    {
        b = ArrList_get(list, i);
        if (b.id == a)
        {
            flag = i;
        }
    }
    if (flag != -1)
    {
        ArrList_erase(list, flag);
        printf("deletion sucessful\n");
    }
    else
    {
        printf("ID id not Found\n");
    }
}

void search_student(ArrList *list)
{
    int a;
    STUDENT b;
    printf("Enter Student ID (maximum six digits)\n");
    scanf("%d", &a);
    for (int i = 0; i < ArrList_size(list); ++i)
    {
        b = ArrList_get(list, i);
        if (b.id == a)
        {
            printf("\tStdent id\t\tStudent Name\t\t\t Borrow Book ID\t\tMobile number\t\tGender\n");
            printf("-----------------------------------------------------------------------------------------------------\n");
            printf("\t%-10d\t\t", b.id);
            printf("%-20s\t\t", b.name);
            printf(" %-9d\t\t", b.book_id);
            printf("%-9d\t\t", b.mobile_number);
            if (b.gender == 1)
                printf("male");
            else
                printf("female");
            printf("\n");
        }
    }
}

void search_student_by_book_ID(ArrList *list)
{
    int a,flag=0;
    STUDENT s;
    printf("Enter Book ID\n");
    scanf("%d", &a);
    for (int i = 0; i < ArrList_size(list); ++i)
    {
        s = ArrList_get(list, i);
        if (s.book_id == a)
        {
            flag=1;
            printf("\tStudent id\t\tStudent Name\t\t\t Borrow Book ID\t\tMobile number\t\tGender\n");
            printf("-----------------------------------------------------------------------------------------------------\n");
            printf("\t%-10d\t\t", s.book_id);
            printf("%-20s\t\t", s.id);
            printf(" %-9d\t\t", s.name);
            printf("%-9d\t\t", s.mobile_number);
            if (s.gender == 1)
                printf("male");
            else
                printf("female");
            printf("\n");
        }
        if (flag==0)
        {
            printf("This book is not borrow by anyone \n");
        }
        
    }

}

void delete_all_student(ArrList *list)
{
    ArrList_clear(list); // clear all the student information from the array list
}

void student_section(BinarySearchTree *booktree, ArrList *list)
{
    int a, b;
    do
    {

        printf("\n");
        printf(".........................\n");
        printf("|    student section    |\n");
        printf(".........................\n\n");

        printf("\t\t\tPress <1> To insert Student Record\n");
        printf("\t\t\tPress <2> To See All Students Record\n");
        printf("\t\t\tPress <3> To delete record(By Student ID)\n");
        printf("\t\t\tPress <4> To search Student(By Student ID)\n");
        printf("\t\t\tPress <5> To search_student(By Book Borrow ID)\n");
        printf("\t\t\tPress <6> To DELETE ALL student Record\n");
        printf("\t\t\tPress <7> Back to main menu\n");
        printf("Enter your chosen :\n");
        scanf("%d", &a);
        switch (a)
        {
        case 1:
            student_register_record(list);
            ArrList_shrink_to_fit(list);
            break;
        case 2:
            see_students_record(list);
            break;
        case 3:
            delete_student_record(list);
            break;
        case 4:
            search_student(list);
            break;
        case 5:
            search_student_by_book_ID(list);
        case 6:
            delete_all_student(list);
            printf("successfully !! delete all the students information\n");
        case 7:
            main_manu(booktree, list);
            break;
        default:
            printf("Please Enter correct value\n");
        }
        printf("\n");
        printf("Press <1> To continue with student section\n");
        printf("OR Press <3> to move main menu\n");
        scanf("%d", &b);
    } while (b == 1);
}
