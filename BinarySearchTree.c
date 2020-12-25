#include "BinarySearchTree.h"
#include <stdlib.h>

BinarySearchTree* new_BinarySearchTree(){
    BinarySearchTree* btree = (BinarySearchTree*)malloc(sizeof(BinarySearchTree));
    btree->root = NULL;
    btree->size = 0;
    return btree;
}

void delete_BinarySearchTree(BinarySearchTree* btree){
    delete_BinaryTree(btree->root);
    free(btree);
}

BinaryTreeNode* BinarySearchTree_find_parent_node(BinaryTreeNode* tnode, int key){
    if(tnode->data.key < key){
        if(tnode->right == NULL){
            return tnode;
        }else{
            return BinarySearchTree_find_parent_node(tnode->right, key);
        }
    }else if(tnode->data.key > key){
        if(tnode->left == NULL){
            return tnode;
        }else{
            return BinarySearchTree_find_parent_node(tnode->left, key);
        }
    }else{
        return tnode;
    }
}

BinaryTreeNode* BinarySearchTree_add(BinarySearchTree* btree, Book elem){
    BinaryTreeNode* node = new_BinaryTreeNode(elem, NULL, NULL);
    if(btree->size == 0){ 
        btree->root = node;
        btree->size = 1;
    }else{
        BinaryTreeNode* p = BinarySearchTree_find_parent_node(btree->root, elem.key); //..
        if(p->data.key > elem.key){
            p->left = node;
            node->parent = p;
            btree->size += 1;
        }else if(p->data.key < elem.key){
            p->right = node;
            node->parent = p;
            btree->size +=1;
        }else{
            p->data.existing_stocks++;
        }
    }
    return node;
}

BinaryTreeNode* BinarySearchTree_find_node(BinaryTreeNode* tnode, int key){
    if(tnode == NULL){
        return NULL;
    }else if( tnode->data.key < key){
        return BinarySearchTree_find_node(tnode->right, key);
    }else if( tnode->data.key > key){
        return BinarySearchTree_find_node(tnode->left, key);
    }else{ // tnode->data.key == key
        return tnode;
    }
}

Book BinarySearchTree_find(BinarySearchTree* btree, int key){
    Book b;
    BinaryTreeNode* node = BinarySearchTree_find_node(btree->root, key);
    if(node != NULL){
        return node->data;
    }else{
        b.key = -1;
        return b;
    }
}

Book BinarySearchTree_find_for_delete(BinarySearchTree* btree, int key){
    Book b;
    BinaryTreeNode* node = BinarySearchTree_find_node(btree->root, key);
    if(node != NULL){
        BinarySearchTree_delete(btree, node);
        b.key = 1;
        return b;
    }else{
        b.key = -1;
        return b;
    }
}

BinaryTreeNode* BinarySearchTree_find_min_node(BinaryTreeNode* tnode){
    if(tnode->left == NULL){
        return tnode;
    }else{
        return BinarySearchTree_find_min_node(tnode->left);
    }
}

Book BinarySearchTree_find_min(BinarySearchTree* btree){
    Book a;
    if(btree->size == 0){
        a.key = -1;
        return a;
    }
    BinaryTreeNode* node = BinarySearchTree_find_min_node(btree->root);
    return node->data;
}

BinaryTreeNode* BinarySearchTree_find_max_node(BinaryTreeNode* tnode){
    if(tnode->right == NULL){
        return tnode;
    }else{
        return BinarySearchTree_find_max_node(tnode->right);
    }
}

Book BinarySearchTree_find_max(BinarySearchTree* btree){
    Book a;
    if(btree->size == 0){
        a.key = -1;
        return a;
    }
    BinaryTreeNode* node = BinarySearchTree_find_max_node(btree->root);
    return node->data;
}

void BinarySearchTree_delete(BinarySearchTree* btree, BinaryTreeNode* node){
    BinaryTreeNode* p = node->parent;
    //if node is a leaf
    if(node->left == NULL && node->right == NULL){
        if(p->left == node){
            p->left = NULL;
        }else{
            p->right = NULL;
        }
        free(node);
        btree->size -= 1;

    // if the node does not have a right child
    }else if(node->right == NULL){
        if(p->left == node){
            p->left = node->left;
        }else{
            p->right = node->left;
        }
        node->left->parent = p;
        free(node);
        btree->size -= 1;

       //if the node does not have a left child
    }else if(node->left == NULL){
        if(p->left == node){
            p->left = node->right;
        }else{
            p->right = node->right;
        }
        node->right->parent = p;
        free(node);
        btree->size -= 1;

    // if the node has both children
    }else{
        BinaryTreeNode* min_node = BinarySearchTree_find_min_node(node->right);
        node->data = min_node->data;
        BinarySearchTree_delete(btree, min_node);
    }
}

