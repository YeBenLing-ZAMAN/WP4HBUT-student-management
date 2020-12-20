#ifndef BinaryTree_h
#define BinaryTree_h

#include"book.h"

typedef struct BinaryTreeNode{
    struct BinaryTreeNode* parent;
    Book data;
    struct BinaryTreeNode* left;
    struct BinaryTreeNode* right;
}BinaryTreeNode;

BinaryTreeNode* new_BinaryTreeNode(Book elem, BinaryTreeNode* l, BinaryTreeNode* r);


#endif