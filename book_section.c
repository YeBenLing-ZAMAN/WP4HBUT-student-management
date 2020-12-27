#include <stdio.h>
#include <stdlib.h>
#include "book_section.h"
void book_insert_record(BinarySearchTree *booktree)
{
    int x;
    Book b;
    do
    {
        printf("Enter book ID (maxmimun six digits)\n");
        scanf("%d", &b.key);
        printf("Enter  book title (Space not allowed)\n");
        scanf("%s", &b.title);
        printf("Enter book Author name (space not allowed)\n");
        scanf("%s", &b.author);
        b.existing_stocks = 1;
        BinarySearchTree_add(booktree, b);
        printf("\n");
        printf("If you want to continue book insertion press <1> otherwise press <3>\n");
        scanf("%d", &x);
    } while (x == 1);
}

void book_searching(BinarySearchTree *booktree)
{
    Book b1, return_book_information;
    printf("Enter book key (maxmimun six digits)\n");
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
        printf("Book author :\t\t%s\n", return_book_information.author);
        printf("Book existing_stocks :\t\t%d\n", return_book_information.existing_stocks);
        //printf("Book total :\t\t%d\n", return_book_information.total);
    }
}

void delete_book_record(BinarySearchTree *booktree)
{
    Book b, return_book_information;
    BinaryTreeNode *delete_node_address;
    delete_node_address = NULL;
    printf("Enter Book key (maxmimun six digits)\n");
    scanf("%d", &b.key);

    delete_node_address = BinarySearchTree_find_node(booktree->root, b.key);
    if (delete_node_address == NULL)
    {
        // node address Not founded
        printf("Book is not Found by this id : %d\n", b.key);
    }
    else
    {
        // node is not here
        BinarySearchTree_delete(booktree, delete_node_address);
          printf("Book id : %d is delete suceesfully\n", b.key);
    }
}

void see_all_book_records(BinarySearchTree *booktree)
{
    printf("\n");
    printf("\tBook ID \tBook Title \t\tBook Author\t\tExisting Stocks\n");
    printf("-----------------------------------------------------------------------------------------------------\n");
    preorder_traversal(booktree->root);
}

void delete_all_book(BinarySearchTree *booktree)
{
    delete_BinaryTree(booktree->root);
    printf("Successfully !! delete all the book information\n");
}

void book_section(BinarySearchTree *booktree, ArrList *list)
{
    int a, c;
    do
    {

        printf("\n");
        printf(".........................\n");
        printf("|      Book section     |\n");
        printf(".........................\n\n");

        printf("\t\t\tPress <1> To insert Book in library record\n");
        printf("\t\t\tPress <2> To see all Book records\n");
        printf("\t\t\tPress <3> To see book record/details(By book ID)\n");
        printf("\t\t\tPress <4> To delete Book record (with all Existing stocks)\n");
        printf("\t\t\tPress <5> To DELETE ALL the BOOKS information for program\n");
        printf("\t\t\tPress <6> Back to Main Menu\n");
        printf("Enter your chosen :\n");
        scanf("%d", &a);
        switch (a)
        {
        case 1:
            book_insert_record(booktree);
            break;
        case 2:
            see_all_book_records(booktree);
            break;
        case 3:
            book_searching(booktree);
            break;
        case 4:
            delete_book_record(booktree);
            break;
        case 5:
            delete_all_book(booktree);
            break;
        case 6:
            main_manu(booktree, list);
            break;
        default:
            printf("enter correct value\n");
        }
        printf("Press <1> To continue with book section\n\n");
        printf("press <2> To move main menu\n");

        scanf("%d", &c);
    } while (c == 1);
}