#include <stdio.h>
#include <stdlib.h>
#include "BinarySearchTree.h"
#include "student.h"
#include "book.h"
#include "student.h"
#include "ArrList.h"
void main_manu(BinarySearchTree *booktree, ArrList *list);

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
        printf("Book is not Found by this id : %d", b.key);
    }
    else
    {
        // node is not here
        BinarySearchTree_delete(booktree, delete_node_address);
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
}

void book_section(BinarySearchTree *booktree, ArrList *list)
{
    int a;
    char c;
    do
    {

        printf("\n");
        printf(".........................\n");
        printf("|  book section    |\n");
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
        fflush(stdin);
        printf("Press <a> To continue with book section\n\n");
        printf("OR other key to main menu\n");

        scanf("%c", &c);
    } while (c == 'a');
}
// ----------------------------------------------------------------

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
    int a;
    STUDENT s;
    printf("Enter Book ID\n");
    scanf("%d", &a);
    for (int i = 0; i < ArrList_size(list); ++i)
    {
        s = ArrList_get(list, i);
        if (s.book_id == a)
        {
            printf("\tStdent id\t\tStudent Name\t\t\t Borrow Book ID\t\tMobile number\t\tGender\n");
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
        printf("|  student section    |\n");
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

// ----------------------------------------------------------------
// book issue section  first compelete student section

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
                        s.book_id = a;
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
                printf("You Already Borrow a Book. \t\t first you return pervious one than take new one \n");
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
    int a, flag = 0;
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
                s.book_id = 0;
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
        printf("|  book Issue section    |\n");
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
        printf("Press<4> For To exit\n");
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
        printf("prees <2> for exit this program\n");
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