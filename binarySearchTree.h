#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include <queue>

// as in past project, struct is used; defines node for BST
struct BinaryTreeNode {
    int value;
    BinaryTreeNode *left;
    BinaryTreeNode *right;
};

class BinarySearchTree {
public:
    BinarySearchTree();
    void insert(int value);
    bool find(int value);
    void remove(int value);
    void inorderTraversal();
    void preorderTraversal();
    void postorderTraversal();
    void breadthFirstTraversal();

private:
    // helper functions that are used to support 'public' methods
    BinaryTreeNode *root;
    BinaryTreeNode *insertHelper(BinaryTreeNode *node, int value);
    bool findHelper(BinaryTreeNode *node, int value);
    void removeHelper(BinaryTreeNode *&node, int value);
    BinaryTreeNode *findMin(BinaryTreeNode *node);
    void inorderTraversalHelper(BinaryTreeNode *node);
    void preorderTraversalHelper(BinaryTreeNode *node);
    void postorderTraversalHelper(BinaryTreeNode *node);
};

#endif
