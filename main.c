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

void main_manu(BinarySearchTree *booktree, ArrList *list)
{
    int n, b;
    do
    {
        printf("\n");
        printf(".........................\n");
        printf("|  LIBRARY MANAGEMENT    |\n");
        printf("|                        |\n");
        printf("|           for operater |\n");
        printf(".........................\n\n");
        printf("\nPress<1> For Student section\n");
        printf("Press<2> For Book section\n");
        printf("Press<3> For Book issue section\n");
        printf("Press<4> For To exit this program\n");
        printf("Enter your chosen :\n");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            student_section(booktree, list);
            break;
        case 2:
            book_section(booktree, list);
            break;
        case 3:
            booK_issue_section(booktree, list);
            break;
        case 4:
            exit(0);
        default:
            printf("please enter correct choice\n");
        }
        printf("\n");
        printf("\n");
        printf("Press <1> To continue with main menu\n");
        scanf("%d", &b);
    } while (b == 1);
}

int main()
{

    BinarySearchTree *booktree = new_BinarySearchTree();
    ArrList *list;
    list = new_ArrList();
    printf("\t\t\t###########################################################################");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t############      Library management System Project in C       ############");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t############                         (BST and ArrList implementation)######");
    printf("\n\t\t\t###########################################################################");
    printf("\n\t\t\t---------------------------------------------------------------------------\n");
    printf("\n\t\t\t----------------------------------------------------------------------------");
    printf("\n");
    printf("\n");
    main_manu(booktree, list);

    getchar();

    del_ArrList(list);
    delete_BinarySearchTree(booktree);
    exit(0);

    return 0;
}