#include <stdio.h>
#include "BinarySearchTree.h"
#include "index.c"
#include"student.h"
#include"book.h"

void book_insert_record(BinarySearchTree *booktree,BinaryTreeNode *bt){
    Book b1;
    static int forfirst= 0;
    printf("Enter  book title (Space not allowed)\n");
    scanf("%s",b1.title );
    printf("Enter book key (maxmimun six digits)\n");
    scanf("%s", b1.key);  
    printf("Enter book Author name (space not allowed)\n)");
    scanf("%s", b1.author);
    
    if(forfirst==0)
    bt=BinarySearchTree_add(booktree,b1);  // laoahi kinto ekta requirment dichilo....
    else
    BinarySearchTree_add(booktree,b1);

    forfirst++;
}


void book_section(BinarySearchTree *booktree,BinaryTreeNode *bt)
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
        //printf("\t\t\tPress <2> To see record\n");
        //printf("\t\t\tPress <3> To delete record\n");
        //printf("\t\t\tPress <4> To search book\n");
        printf("\t\t\tPress <5> Back to Main Menu\n");
        scanf("%d", &a);
        switch (a)
        {
        case 1:
            book_insert_record(booktree,bt);
            break;
        // case 2:
        //     book_see_record();
        //     break;
        // case 3:
        //     book_delete_record();
        //     break;
        // case 4:
        //     printf("Enter book name\n");
        //     scanf("%s", name);
        //     booksearch(name);
        //     break;
        case 5:
            main_manu();
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



void student_section()
{
    int a;
    char c, nam[20];
    //STUDENT *S;
    do
    {
        char name[20];

        printf("\n");
        printf(".........................\n");
        printf("|  student section    |\n");
        printf(".........................\n\n");

        printf("\t\t\tPress <1> To see record\n");
        printf("\t\t\tPress <2> To insert record\n");
        printf("\t\t\tPress <3> To delete record\n");
        printf("\t\t\tPress <4> To search Student\n");
        printf("\t\t\tPress <5> Back to main menu\n");
        scanf("%d", &a);
        switch (a)
        {
        case 1:
            //see_record();
            break;
        case 2:
            //insert_record();
            break;
        // case 3:
        //     printf("Enter student ID\n");
        //     scanf("%s", nam);
        //     delete_record(nam);
        //     break;
        // case 4:
        //     printf("Enter name of student\n");
        //     scanf("%s", name);
        //     search(name);
        //     break;
        // case 5:
            main_manu();
            break;
        default:
            printf("enter correct value\n");
        }
        fflush(stdin);
        printf("Press <a> To continue with student section\n");
        scanf("%c", &c);
    } while (c == 'a');
}


void main_manu(BinarySearchTree *booktree,BinaryTreeNode *bt,BinarySearchTree *studenttree,BinaryTreeNode *st){
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
            student_section();
            break;
        case 2:
            book_section(booktree,bt);
            break;
        case 3:
            //
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

    char option, do_again; int count=0;
    Book a,store_return_value;
    BinarySearchTree *booktree = new_BinarySearchTree();
    BinaryTreeNode *bt;
    BinarySearchTree *studenttree = new_BinarySearchTree();
    BinaryTreeNode *st;
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
    main_manu(booktree,bt,studenttree,st);

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