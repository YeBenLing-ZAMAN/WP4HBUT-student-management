#include "BinaryTree.h"
#include <stdlib.h>
#include <stdio.h>

BinaryTreeNode* new_BinaryTreeNode(Book elem, BinaryTreeNode* l, BinaryTreeNode* r){
    BinaryTreeNode* node = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
    node->parent = NULL;
    node->data = elem;
    node->left = l;
    node->right = r;

    if(l != NULL){
        l->parent = node;
    }
    if(r != NULL){
        r->parent = node;
    }

    return node;
}

void preorder_traversal(BinaryTreeNode* t){
    if(t == NULL){
        return;
    }
    printf("%d ", t->data.key);
    preorder_traversal(t->left);
    preorder_traversal(t->right);
}

void inorder_traversal(BinaryTreeNode* t){
    if(t == NULL){
        return;
    }
    inorder_traversal(t->left);
    printf("%d ", t->data.key);
    inorder_traversal(t->right);
}

void postorder_traversal(BinaryTreeNode* t){
    if(t == NULL){
        return;
    }
    postorder_traversal(t->left);
    postorder_traversal(t->right);
    printf("%d ", t->data.key);
}

int BinaryTree_depth(BinaryTreeNode* t){
    if(t == NULL){
        return -1;
    }
    int left_depth = BinaryTree_depth(t->left);
    int right_depth = BinaryTree_depth(t->right);

    if(left_depth > right_depth){
        return left_depth + 1;
    }else{
        return right_depth + 1;
    }
}

void delete_BinaryTree(BinaryTreeNode* t){
    if(t == NULL){
        return;
    }
    delete_BinaryTree(t->left);
    delete_BinaryTree(t->right);
    free(t);
}
