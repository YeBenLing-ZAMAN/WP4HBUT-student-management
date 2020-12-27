#ifndef student_section_h
#define student_section_h
#include <stdio.h>
#include <stdlib.h>
#include "student_section.h"
#include "book_section.h"
#include "book_issue_section.h"
#include "BinarySearchTree.h"
#include "student.h"
#include "book.h"
#include "student.h"
#include "ArrList.h"

void main_manu(BinarySearchTree *booktree, ArrList *list);
void student_section(BinarySearchTree *booktree, ArrList *list);
void student_register_record(ArrList *list);
void see_students_record(ArrList *list);
void delete_student_record(ArrList *list);
void search_student(ArrList *list);
void search_student_by_book_ID(ArrList *list);
void delete_all_student(ArrList *list);


#endif
