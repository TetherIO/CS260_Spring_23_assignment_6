#include <iostream>
#include "binarySearchTree.h"

//  function for testing search
void testSearch(BinarySearchTree& bst, int value) {
    std::cout << "Searching for " << value << " ... ";
    if (bst.find(value)) {
        std::cout << "Found" << std::endl;
    } else {
        std::cout << "Not Found" << std::endl;
    }
}

//  function for testing insert
void testInsert(BinarySearchTree& bst, int value) {
    std::cout << "Inserting " << value << std::endl;
    bst.insert(value);
}

//  function for testing remove
void testRemove(BinarySearchTree& bst, int value) {
    std::cout << "Removing " << value << std::endl;
    bst.remove(value);
}

int main() {
    BinarySearchTree bst;

    // Inserting and testing the insert function
    testInsert(bst, 42);
    testInsert(bst, 0);
    testInsert(bst, 32);
    testInsert(bst, 16);
    testInsert(bst, -5);
    testInsert(bst, -6);
    testInsert(bst, -4);
    testInsert(bst, 64);
    testInsert(bst, 64);

    // find function
    testSearch(bst, -6);
    testSearch(bst, -7);
    testSearch(bst, 99);

    // remove
    testRemove(bst, -6);  // "Removing -6"
    testSearch(bst, -6);  // Searching for -6 ... Not Found

    // traversal
    std::cout << "In-order traversal: "; // -5 -4 0 16 32 42 64 64
    bst.inorderTraversal();
    std::cout << "Pre-order traversal: "; // 42 0 -5 -4 32 16 64 64
    bst.preorderTraversal();
    std::cout << "Post-order traversal: "; // -4 -5 16 32 0 64 64 42
    bst.postorderTraversal();
    std::cout << "Breadth-first traversal: "; // 42 0 64 -5 32 64 -4 16
    bst.breadthFirstTraversal();

    return 0;

}
