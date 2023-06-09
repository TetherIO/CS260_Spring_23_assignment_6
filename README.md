# CS260_Spring_23_assignment_6
Binary search tree

## Requirement 1:
Each function has at least one test associated. The test functions include 'testSearch', 'testInsert', and 'testRemove', which test the functionalities of the tree.

![](https://github.com/TetherIO/CS260_Spring_23_assignment_6/blob/main/simpletests.png)

## Requirement 2:
-Nodes to store values
(BinaryTreeNode struct)
![](https://github.com/TetherIO/CS260_Spring_23_assignment_6/blob/main/nodestruct.png)

-Add Function
(insert & insertHelper)
![](https://github.com/TetherIO/CS260_Spring_23_assignment_6/blob/main/insertfunction.png)

-Remove Function
(remove & removeHelper)
![](https://github.com/TetherIO/CS260_Spring_23_assignment_6/blob/main/removefunction.png)

Tree Traversal
(inorderTraversal, preorderTraversal, postorderTraversal, and breadthFirstTraversal)

## Requirement 3:
The insert function resursively searches for the correct position to insert a value, moving down from the root. I think in the worst case, it wwould be O(n) because the tree isn't balancing so at it's worst case it could end up as a linked list. The find operation could also traverse the entire list dependingon the position of the node. The remove operation involves first finding the node and restructuring the node, but again O(n) in the worst case. The various traversals all visit the nodes once by their very nature.
