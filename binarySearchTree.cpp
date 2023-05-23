// Code modified from instructors Winter 2023 CS260 GitHub repository


#include <iostream>
#include "binarySearchTree.h"

using std::cout;
using std::endl;

// initializes empty BST
BinarySearchTree::BinarySearchTree() {
    root = nullptr;
}

// insert value into BST
void BinarySearchTree::insert(int value) {
    root = insertHelper(root, value);
}

// find value in BST
bool BinarySearchTree::find(int value) {
    return findHelper(root, value);
}

// remove value from BST
void BinarySearchTree::remove(int value) {
    removeHelper(root, value);
}

// print value in order traversal
void BinarySearchTree::inorderTraversal() {
    inorderTraversalHelper(root);
    cout << endl; // Adding a newline for better formatting
}

// print values in pre-order traversal
void BinarySearchTree::preorderTraversal() {
    preorderTraversalHelper(root);
    cout << endl; // Adding a newline for better formatting
}

// print values in post-order traversal
void BinarySearchTree::postorderTraversal() {
    postorderTraversalHelper(root);
    cout << endl; // Adding a newline for better formatting
}

// print values in breadth-first, visit all nodes at current depth and move on
void BinarySearchTree::breadthFirstTraversal() {
    if (root == nullptr) return;

    // create empty queue that'll store pointers
    std::queue<BinaryTreeNode *> nodes;
    nodes.push(root); // root is going to be start
    // initiates loop
    while (!nodes.empty()) {
        BinaryTreeNode *current = nodes.front();
        nodes.pop();

        cout << current->value << " ";
        // If left child exists, add to queue
        if (current->left != nullptr) {
            nodes.push(current->left);
        }
        // If right child exists, add to queue
        if (current->right != nullptr) {
            nodes.push(current->right);
        }
    }

    cout << endl; // Adding a newline for better formatting
}

// function to insert a new node in the Binary Search Tree
BinaryTreeNode *BinarySearchTree::insertHelper(BinaryTreeNode *node, int value) {
    // If the tree/subtree is empty, create and return a new node
    if (node == nullptr) {
        node = new BinaryTreeNode;
        node->value = value;
        node->left = nullptr;
        node->right = nullptr;
    } else if (value <=
               node->value) {
        node->left = insertHelper(node->left, value);
    } else { // Otherwise, insert it in the right subtree
        node->right = insertHelper(node->right, value);
    }

    return node;
}

//function to find a value in the Binary Search Tree
bool BinarySearchTree::findHelper(BinaryTreeNode *node, int value) {
    if (node == nullptr) { // If the tree/subtree is empty, the value is not found
        return false;
    } else if (value == node->value) { // If the value equals the node's value, the value is found
        return true;
    } else if (value < node->value) { // If the value is less than the node's value, search in the left subtree
        return findHelper(node->left, value);
    } else { // Otherwise, search in the right subtree
        return findHelper(node->right, value);
    }
}

//function to remove a node from the Binary Search Tree
void BinarySearchTree::removeHelper(BinaryTreeNode *&node, int value) {
    if (node == nullptr) {
        return;
    } else if (value < node->value) { //value is less than the node's value, remove from the left subtree
        removeHelper(node->left, value);
    } else if (value > node->value) { // value is more than the node's value, remove from the right subtree
        removeHelper(node->right, value);
    } else { // If the node is found
        //node has no left child
        if (node->left == nullptr) {
            BinaryTreeNode *temp = node->right;
            delete node;
            node = temp;
        }
            //node has no right child
        else if (node->right == nullptr) {
            BinaryTreeNode *temp = node->left;
            delete node;
            node = temp;
        }
            //node has both children
        else {
            BinaryTreeNode *temp = findMin(node->right);
            node->value = temp->value;
            removeHelper(node->right, temp->value);
        }
    }
}

// Helper function to find the node with minimum value in a given tree/subtree
BinaryTreeNode *BinarySearchTree::findMin(BinaryTreeNode *node) {
    // Keep going left until reaching the node with no left child (the node with the minimum value)
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}


void BinarySearchTree::inorderTraversalHelper(BinaryTreeNode *node) {
    // Visit the left subtree, the node itself, then its right subtree
    if (node != nullptr) {
        inorderTraversalHelper(node->left);
        cout << node->value << " ";
        inorderTraversalHelper(node->right);
    }
}


void BinarySearchTree::preorderTraversalHelper(BinaryTreeNode *node) {
    // Visit the node itself, then its left subtree, then its right subtree
    if (node != nullptr) {
        cout << node->value << " ";
        preorderTraversalHelper(node->left);
        preorderTraversalHelper(node->right);
    }
}


void BinarySearchTree::postorderTraversalHelper(BinaryTreeNode *node) {
    // Visit the node's left subtree, then its right subtree, then the node itself
    if (node != nullptr) {
        postorderTraversalHelper(node->left);
        postorderTraversalHelper(node->right);
        cout << node->value << " ";
    }
}
