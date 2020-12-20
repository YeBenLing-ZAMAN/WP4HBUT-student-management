#include<stdio.h>
#include "BinarySearchTree.h"

int main(){
    ADT a;
    BinarySearchTree* btree = new_BinarySearchTree();
    BinaryTreeNode* n;

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


    a= BinarySearchTree_find(btree, 12);
    printf("%d",a.key);

    return 0;

}