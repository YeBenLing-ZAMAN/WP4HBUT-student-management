#ifndef book_section_h
#define book_section_h
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
void book_section(BinarySearchTree *booktree, ArrList *list);
void book_insert_record(BinarySearchTree *booktree);
void book_searching(BinarySearchTree *booktree);
void delete_book_record(BinarySearchTree *booktree);
void see_all_book_records(BinarySearchTree *booktree);
void delete_all_book(BinarySearchTree *booktree);

#endif