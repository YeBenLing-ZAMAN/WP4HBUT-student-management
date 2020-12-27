#include <stdio.h>
#include <stdlib.h>
#include "book_issue_section.h"
void Check_book_storage(BinarySearchTree *booktree)
{
    Book b1, return_book_information;
    printf("Enter book ID (maxmimun six digits)\n");
    scanf("%d", &b1.key);
    return_book_information = BinarySearchTree_find(booktree, b1.key);
    if (return_book_information.key == -1)
    {
        printf("Book is NOT found!!!! \n");
    }
    else
    {
        printf("book key :\t\t%d\n", return_book_information.key);
        printf("Book title :\t\t%s\n", return_book_information.title);
        printf("Book existing_stocks :\t\t%d\n", return_book_information.existing_stocks);
    }
}

void Borrow_Book(BinarySearchTree *booktree, ArrList *list)
{
    int a, i, flag = 0;
    STUDENT s;
    Book b1;
    BinaryTreeNode *book;
    printf("Enter Student ID (maxmimun six digits)\n");
    scanf("%d", &a);
    for (i = 0; i < ArrList_size(list); i++)
    {
        s = ArrList_get(list, i);
        if (s.id == a)
        {
            flag = 1;
            if (s.book_id == 0)
            {
                printf("Enter book key (maxmimun six digits)\n");
                scanf("%d", &b1.key);
                book = BinarySearchTree_find_node(booktree->root, b1.key);
                if (book == NULL)
                {
                    printf("Book is not founded in Libaray\n");
                }
                else
                {
                    if (book->data.existing_stocks > 1)
                    {
                        ArrList_update(list, i, b1.key);
                        book->data.existing_stocks--;
                        printf("Borrow Done\n");
                    }
                    else
                    {
                        printf("Existing_stocks is not sufficient to Borrow this book \n");
                    }
                }
            }
            else
            {
                printf("You Already Borrow a Book. \t--->>first you return pervious one than take new one \n");
            }
        }
    }
    if (flag == 0)
    {
        printf("This Student ID is not founded in resister.\n");
        printf("please resister first on libaray\n");
    }
}

void Return_Book(BinarySearchTree *booktree, ArrList *list)
{
    int a, flag = 0, n=0; 
    STUDENT s;
    Book b1;
    BinaryTreeNode *book;
    printf("Enter Student ID\n");
    scanf("%d", &a);
    for (int i = 0; i < ArrList_size(list); ++i)
    {
        s = ArrList_get(list, i);
        if (s.id == a)
        {
            flag = 1;
            if (s.book_id != 0)
            {
                book = BinarySearchTree_find_node(booktree->root, s.book_id);
                book->data.existing_stocks++;
                ArrList_update(list, i, n);
                printf("Book Successfully retuned\n");
            }
            else
            {
                printf("You haven't any Book due\n");
            }
            printf(" %-9d\t\t", s.book_id);
        }
        if (flag == 0)
        {
            printf("This : %d  student ID is not found\n", a);
        }
    }
}

void booK_issue_section(BinarySearchTree *booktree, ArrList *list)
{
    int a, b;
    do
    {
        printf("\n");
        printf("..........................\n");
        printf("|   Book Issue section   |\n");
        printf("..........................\n\n");

        printf("\t\t\tPress <1> Check Book Exiting Storage\n");
        printf("\t\t\tPress <2> Borrow a Book\n");
        printf("\t\t\tPress <3> Return Book\n");
        printf("\t\t\tPress <4> Back to Main Menu\n");
        printf("Enter your chosen :\n");
        scanf("%d", &a);
        switch (a)
        {
        case 1:
            Check_book_storage(booktree);
            break;
        case 2:
            Borrow_Book(booktree, list);
            break;
        case 3:
            Return_Book(booktree, list);
            break;
        case 4:
            main_manu(booktree, list);
            break;
        default:
            printf("enter correct value\n");
        }
        printf("Press <1> To continue with book_issue_section\n\n");
        printf("OR Press <2> for main menu\n");

        scanf("%d", &b);
    } while (b == 1);
}
