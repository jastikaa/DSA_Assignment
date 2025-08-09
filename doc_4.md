# Question 1:Doubly Linked List with Insert After and Delete Node
## (a) Data structure defination
The primary data structure that I applied in this program is a doubly linked list Doubly linked list is a linked list whose nodes possess three components:
-data: an integer cell in which the integer value of the node is stored.
-prev: a pointer which contains address of the preceding node in the list.
-next: a pointer to memory address of the following node in the list.

The node is a C structure as written below:
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};
The prev pointer  permits to move backwards through the list.
The next pointer permits moving forward in the list.
These taken together make insertion and deletion simple compared to that of a singly linked list.

## (b) Description of the Functions Implemented

1. createNode(int data)
Function: Create a new node with the given data and set both prev and next to NULL.
Returns a pointer to the newly allocated node.
Used to initialize nodes before linking them into the list.

2. insertAfter(struct Node* prevNode, int data)
Function: Insert a new node after the given node (prevNode).
Steps:
Set the new node's prev to the given node.
Set the new node's next to the given node's next node.
Set the next of the given node to the new node.
If the next of the new node is not NULL, set the prev of that node.

3. deleteNode(struct Node** head, struct Node* delNode)
Function: Removes the given node (delNode) from the list.
Steps:
If the node to be removed is the head, point the head pointer to the next node.
Set the next of the previous node (if any).
Set the previous of the next node (if any).
Free the memory of the removed node to avoid memory leaks.

4. displayForward(struct Node* node)
Function: Displays all nodes of the list from head to tail.
Steps: Iterate through using the next pointer and display data of every node.

## (c) An Overview of How the main() Method Is Organized
1. Create the Initial List

Three nodes are created with values 10, 20, and 30.

The prev and next pointers are linked to form the doubly linked list.

2. Display the Original List

The displayForward() function is called to show the list before any changes.

Insert After a Given Node

insertAfter(second, 25) inserts a node with value 25 after the node with value 20.

3. Delete a Specific Node

deleteNode(&head, third) deletes the node containing the value 30.

Display the List After Each Operation

The updated list is displayed after insertion and after deletion.

## (d) Output of a Complete Run of the Program