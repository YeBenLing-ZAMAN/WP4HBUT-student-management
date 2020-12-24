#ifndef BinarySearchTree_h
#define BinarySearchTree_h

#include "BinaryTree.h"
#include "book.h"

typedef struct{
    BinaryTreeNode* root;
    int size;
}BinarySearchTree;

BinarySearchTree* new_BinarySearchTree();
void delete_BinarySearchTree(BinarySearchTree* btree);
BinaryTreeNode* BinarySearchTree_add(BinarySearchTree* btree, Book elem);
Book BinarySearchTree_find(BinarySearchTree* btree, int key);
Book BinarySearchTree_find_min(BinarySearchTree* btree);
Book BinarySearchTree_find_max(BinarySearchTree* btree);
Book BinarySearchTree_find_for_delete(BinarySearchTree* btree, int key);
void BinarySearchTree_delete(BinarySearchTree* btree, BinaryTreeNode* node);
#endif
