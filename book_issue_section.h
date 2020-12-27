#ifndef book_issue_section_h
#define book_issue_section_h
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
void Check_book_storage(BinarySearchTree *booktree);
void Borrow_Book(BinarySearchTree *booktree, ArrList *list);
void Return_Book(BinarySearchTree *booktree, ArrList *list);
void booK_issue_section(BinarySearchTree *booktree, ArrList *list);
#endif