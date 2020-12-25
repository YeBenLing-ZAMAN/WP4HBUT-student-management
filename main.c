#include <stdio.h>
#include <stdlib.h>
#include "BinarySearchTree.h"
//#include "index.c"
#include "student.h"
#include "book.h"
#include "student.h"
#include "ArrList.h"
void main_manu(BinarySearchTree *booktree, BinaryTreeNode *bt, ArrList *list);

void book_insert_record(BinarySearchTree *booktree, BinaryTreeNode *bt)
{
    Book b1;
    static int forfirst = 0;
    printf("Enter  book title (Space not allowed)\n");
    scanf("%s", b1.title);
    printf("Enter book key (maxmimun six digits)\n");
    scanf("%s", b1.key);
    printf("Enter book Author name (space not allowed)\n)");
    scanf("%s", b1.author);

    if (forfirst == 0)
        bt = BinarySearchTree_add(booktree, b1); // laoshi kinto ekta requirment dichilo......
    else
        BinarySearchTree_add(booktree, b1);

    forfirst++;
}

void book_see_record(BinarySearchTree *booktree)
{
    Book b1, return_book_information;
    printf("Enter book key (maxmimun six digits)\n");
    scanf("%s", b1.key);
    return_book_information = BinarySearchTree_find(booktree, b1.key);
    if (return_book_information.key != -1)
    {
        printf("book key :\t\t%d\n", return_book_information.key);
        printf("Book title :\t\t%s\n", return_book_information.title);
        printf("Book author :\t\t%s\n", return_book_information.author);
        printf("Book existing_stocks :\t\t%d\n", return_book_information.existing_stocks);
        printf("Book total :\t\t%d\n", return_book_information.total);
    }
    else
        printf("Book is NOT found!!!! \n");
}

void delete_book_record(BinarySearchTree *booktree)
{
    Book b1, return_book_information;
    printf("Enter book key (maxmimun six digits)\n");
    scanf("%s", b1.key);

    BinaryTreeNode *delete_node_address = BinarySearchTree_find_node(booktree->root, b1.key);
    if (delete_node_address != NULL)
    {
        // node address founded
        BinarySearchTree_delete(booktree, delete_node_address); // laoshi's 1 requirment left
    }
    else
    {
        // node is not here
        printf("There has no same ID book in the library");
    }
}

void book_section(BinarySearchTree *booktree, BinaryTreeNode *bt)
{
    int a;
    char c;
    do
    {

        printf("\n");
        printf(".........................\n");
        printf("|  book section    |\n");
        printf(".........................\n\n");

        printf("\t\t\tPress <1> To insert record\n");
        printf("\t\t\tPress <2> To see book record/details\n");
        printf("\t\t\tPress <3> To delete record\n");
        printf("\t\t\tPress <4> Back to Main Menu\n");
        scanf("%d", &a);
        switch (a)
        {
        case 1:
            book_insert_record(booktree, bt);
            break;
        case 2:
            book_see_record(booktree);
            break;
        case 3:
            delete_book_record(booktree);
            break;
        case 4:
            // main_manu();
            break;
        default:
            printf("enter correct value\n");
        }
        fflush(stdin);
        printf("Press <a> To continue with book section\n\n");
        printf("OR other key to main menu\n");

        scanf("%c", &c);
    } while (c == 'a');
}
// ----------------------------------------------------------------

void student_insert_record(ArrList *list)
{
    STUDENT s1;
    static int first_student = 0;
    printf("Enter student ID (mazmimun six digits)\n");
    scanf("%d", &s1.id);
    printf("Enter student Name (Space not allowed)\n");
    scanf("%s", &s1.name);
    s1.book_id = 000000; // 0 means this student is the new member of library -> he don't take any book
    printf("Enter your gender (1 for male, 0 for female)");
    scanf("%d", &s1.gender);

    ArrList_insert(list, 0, s1); // it's always insert 0 index/it's work like a stacks
}

void student_see_record(ArrList *list)
{
    STUDENT b;
    printf("\tStdent id\t\tStudent Name\t\t\t Borrow Book ID\t\tGender\n");
    printf("-----------------------------------------------------------------------------------------------------\n");

    for (int i = 0; i < ArrList_size(list); ++i)
    {
        b = ArrList_get(list, i);
        printf("\t%-10d\t\t", b.id);
        printf("%-20s\t\t", b.name);
        printf(" %-9d\t\t", b.book_id);
        if (b.gender == 1)
            printf("male");
        else
            printf("female");
        printf("\n");
    }
    printf("\n");
}

void student_section(ArrList *list)
{
    int a;
    char c, nam[20];
    //STUDENT *S;
    do
    {

        printf("\n");
        printf(".........................\n");
        printf("|  student section    |\n");
        printf(".........................\n\n");

        printf("\t\t\tPress <1> To insert Student Record\n");
        printf("\t\t\tPress <2> To see Student Record\n");
        printf("\t\t\tPress <3> To delete record\n");
        printf("\t\t\tPress <4> To search Student\n");
        printf("\t\t\tPress <5> Back to main menu\n");
        scanf("%d", &a);
        switch (a)
        {
        case 1:
            student_insert_record(list);
            ArrList_shrink_to_fit(list);
            break;
        case 2:
            student_see_record(list);
            break;
        case 3:
            delete_student_record(list);
            break;
        // case 4:
        //     printf("Enter name of student\n");
        //     scanf("%s", name);
        //     search(name);
        //     break;
        case 5:
            main_manu();
            break;
        default:
            printf("enter correct value\n");
        }

        printf("Press <a> To continue with student section\n");
        scanf("%c", &c);
    } while (c == 'a');
}

// ----------------------------------------------------------------

// book issue section  first compelete student section

void Check_book_storage(BinarySearchTree *booktree)
{
    Book b1, return_book_information;
    printf("Enter book key (maxmimun six digits)\n");
    scanf("%s", b1.key);
    return_book_information = BinarySearchTree_find(booktree, b1.key);
    if (return_book_information.key != -1)
    {
        printf("book key :\t\t%d\n", return_book_information.key);
        printf("Book title :\t\t%s\n", return_book_information.title);
        printf("Book existing_stocks :\t\t%d\n", return_book_information.existing_stocks);
    }
    else
        printf("Book is NOT found!!!! \n");
}

void Borrow_book(BinarySearchTree *booktree)
{
    //printf("Enter your Student id");
}

void book_issue_section(BinarySearchTree *booktree, BinaryTreeNode *bt)
{
    int a;
    char c;
    do
    {
        printf("\n");
        printf(".........................\n");
        printf("|  book section    |\n");
        printf(".........................\n\n");

        printf("\t\t\tPress <1> Check Book Storage\n");
        printf("\t\t\tPress <2> Borrow a Book\n");
        printf("\t\t\tPress <3> Return Book\n");
        printf("\t\t\tPress <4> Back to Main Menu\n");
        scanf("%d", &a);
        switch (a)
        {
        case 1:
            Check_book_storage(booktree);
            break;
        case 2:
            Borrow_Book(booktree);
            break;
        case 3:
            // Return_Book(booktree);
            break;
        case 4:
            // main_manu();
            break;
        default:
            printf("enter correct value\n");
        }
        fflush(stdin);
        printf("Press <a> To continue with book_issue_section\n\n");
        printf("OR other key to main menu\n");

        scanf("%c", &c);
    } while (c == 'a');
}

void main_manu(BinarySearchTree *booktree, BinaryTreeNode *bt, ArrList *list)
{
    int n;
    char ch;
    do
    {
        printf("\t\t\t.........................\n");
        printf("\t\t\t|  LIBRARY MANAGEMENT    |\n");
        printf("\t\t\t.........................\n");
        printf("\nPress<1> For Student section\n");
        printf("Press<2> For Book section\n");
        printf("Press<3> For Book issue section\n");
        printf("Press<4> For To exit\n");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            student_section(list);
            break;
        case 2:
            book_section(booktree, bt);
            break;
        case 3:
            booK_issue_section(booktree, bt);
            break;
        case 4:
            exit(0);
        default:
            printf("please enter correct choice\n");
        }
        printf("For main menu press any key\n");
        scanf("%c", &ch);
    } while (ch != '-');
}

int main()
{

    char option, do_again;
    int count = 0;
    Book a, store_return_value;
    BinarySearchTree *booktree = new_BinarySearchTree();
    BinaryTreeNode *bt;
    ArrList *list;
    list = new_ArrList();
    BinaryTreeNode *return_node_for_delete;
    printf("\t\t\t###########################################################################");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t############      Library management System Project in C       ############");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t###########################################################################");
    printf("\n\t\t\t---------------------------------------------------------------------------\n");
    printf("\n\t\t\t----------------------------------------------------------------------------");
    // printf("\n\t\t\t 1.insert a new book in libary Gallery with book details ");
    // printf("\n\t\t\t 2.Remove a book for this Gallery");
    // printf("\n\t\t\t 3.Want to borrow a book from libary");
    // printf("\n\t\t\t 4.return borrowing book");
    // printf("\n\t\t\t 5.show borrow records");
    // printf("Enter your choice: ");
    main_manu(booktree, bt, list);

    getchar();

    // scanf("%c", &option);
    // switch (option)
    // {
    // case '1': /*for insert new Book*/
    //     do
    //     {
    //         printf("\n\t\t\tinsert a new book in libary Gallery with book details ");
    //         printf("\n\t\t\tEnter your Book name ID:");
    //         scanf("%d", &a.key); //a.key = 12232322;
    //         printf("\n\t\t\tEnter your Book Title:");
    //         // scanf("%c", &a.title); //a.tille = zaman_ programming book;
    //         gets(a[count].title);
    //         printf("\n\t\t\tEnter your Book Author:");
    //         // scanf("%d", &a.key); //a.author = mamun bhai;
    //         gets(a[])
    //         BinarySearchTree_add(btree, a);
    //         printf("\n\t\t\t---------------------------------------------------------------------------\n");
    //         printf("\nDo you want to add more book press 1");
    //         printf("\nOr not prss: 2 ");
    //         scanf("%c", &do_again);
    //     } while (do_again == '1');
    //     //make a balance btree........... for make a this btree for balance
    //     break;

    // case '2': //Clear inventory: Remove books of one ID from the system.
    //     do
    //     {
    //     printf("\n\t\t\t 2.Remove a book for this Gallery");
    //     printf("\n\t\t\t---------------------------------------------------------------------------\n");
    //     printf("\nEnter Book id:");
    //     scanf("%d", a.key);
    //     store_return_value = BinarySearchTree_find_for_delete(btree, a.key);
    //     if(store_return_value.key==1) printf("\nDelete successfully!!");
    //     else if(store_return_value.key==-1) printf("\nbook is not found");
    //     printf("\n\t\t\t---------------------------------------------------------------------------\n");
    //         printf("\nDo you want to delete more bok press 1");
    //         printf("\nOr not prss: 2   ");
    //         scanf("%s", &do_again);
    //     } while (do_again == '1');
    //     //make a balance btree............for make a this btree for balance
    //     break;
    // case '3':
    //     /* code */
    //     break;
    // case '4':
    //     /* code */
    //     break;
    // case '5':
    //     /* code */
    //     break;

    // default:
    //     break;
    // }

    // a.key = 10;
    // BinarySearchTree_add(btree, a);
    // a.key = 5;
    // BinarySearchTree_add(btree, a);
    // a.key = 15;
    // BinarySearchTree_add(btree, a);
    // a.key = 12;
    // BinarySearchTree_add(btree, a);
    // a.key = 1;
    // BinarySearchTree_add(btree, a);
    // a.key = 30;
    // BinarySearchTree_add(btree, a);

    // // BinarySearchTree_delete(btree, n);

    // // delete_BinarySearchTree(btree);

    // a = BinarySearchTree_find(btree, 12);
    // printf("%d", a.key);
    return 0;
}