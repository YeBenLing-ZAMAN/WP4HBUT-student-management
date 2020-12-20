#include <stdio.h>
#include "BinarySearchTree.h"

int main()
{

    char option,for_add_more_book;
    Book a;
    BinarySearchTree *btree = new_BinarySearchTree();
    BinaryTreeNode *n;
    printf("\t\t\t###########################################################################");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t############      Library management System Project in C       ############");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t###########################################################################");
    printf("\n\t\t\t---------------------------------------------------------------------------\n");
    printf("\n\t\t\t----------------------------------------------------------------------------");
    printf("\n\t\t\t 1.insert a new book in libary Gallery with book details ");
    printf("\n\t\t\t 2.Remove a book for this Gallery");
    printf("\n\t\t\t 3.Want to borrow a book from libary");
    printf("\n\t\t\t 4.return borrowing book");
    printf("\n\t\t\t 5.show borrow records");

    printf("Enter your choice: ");
    scanf("%c", &option);
    switch (option)
    {
    case '1':   /*for insert new Book*/
        do
        {
            printf("\n\t\t\tinsert a new book in libary Gallery with book details ");
            printf("\n\t\t\tEnter your Book name ID:");
            scanf("%d", &a.key); //a.key = 12232322;
            printf("\n\t\t\tEnter your Book Title:");
            scanf("%c", &a.title); //a.tille = zaman_ programming book;
            printf("\n\t\t\tEnter your Book Author:");
            scanf("%d", &a.key); //a.author = mamun bhai;
            BinarySearchTree_add(btree, a);
            printf("\n\t\t\t---------------------------------------------------------------------------\n");
            printf("\nDo you want to add more book press 1");
            printf("\nOr not prss: 2   ");
            scanf("%s", &for_add_more_book);
        } while (for_add_more_book=='1');

        break;
    case '2':
        /* code */
        break;
    case '3':
        /* code */
        break;
    case '4':
        /* code */
        break;
    case '5':
        /* code */
        break;

    default:
        break;
    }

    a.key = 10;
    BinarySearchTree_add(btree, a);
    a.key = 5;
    BinarySearchTree_add(btree, a);
    a.key = 15;
    BinarySearchTree_add(btree, a);
    a.key = 12;
    BinarySearchTree_add(btree, a);
    a.key = 1;
    BinarySearchTree_add(btree, a);
    a.key = 30;
    BinarySearchTree_add(btree, a);

    // BinarySearchTree_delete(btree, n);

    // delete_BinarySearchTree(btree);

    a = BinarySearchTree_find(btree, 12);
    printf("%d", a.key);

    return 0;
}