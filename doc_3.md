#Question 2: Implementation of reverse traversal algorithm in the linked list.
Singly linked list is a kind of data structure constructed in such a way that every element (called a node) has certain data and a pointer to the next  node in the list. In an ordinary singly linked list we can only go forward node to node at a time, so printing elements in reverse order is not direct.
In order to resolve this issue I used recursion to do so.

##(a) Data structure defination
I defined a structure called as Node to represent each element in the linked list.
Each Node has two components:

data – To store the integer values.

next – A pointer that points to the next node in the list.

In C language, it looks like this:
struct Node {
    int data;
    struct Node* next;
};
And in this case we have struct Node* next which enables the current node to connect with the subsequent node in a chain of linked list.

##(b) Description of the Functions Implemented
The program include number functions, each with a clear purpose:

1. createNode(int data)
Create a new node with the specified data.
Sets the next pointer to NULL.
Returns the address of new node.

2. insertEnd(struct Node head, int data)
Add new node at the end of the linked list.
If the list is blank, the new node is the head.
Otherwise it stops at the final node and connects new one to it.

3. displayList(struct Node head)
Prints the linked list in the normal forward order.
Transverses the list beginning with head until it reaches NULL.

4. reverseTraversal(struct Node head)*
This is the main function for reverse traversal.
It works on the basis of recursion:
Firstly, it calls itself into the list until the last node is reached.
At this stage, when each recursive call returns, then the data on the node is printed.
This gives the output in reverse order.

##(c) Reverse Traversal Algorithm
Algorithm ReverseTraversal(head):
    1. If head is NULL:
           return  
    2. Call ReverseTraversal(head.next)  
    3. Print head.data  

##(d) An Overview of How the main() Method Is Organized
In the main() function, I showed the program running as follows:
-Built an empty linked list (head = NULL).
-Inserted four nodes: 5, 21, 33, 42 using insertEnd().
-Printed the list in normal order using displayList().
-Printed the list in reverse order using reverseTraversal()

##(e) Output of a Complete Run of the Program
Linked List in normal form: 5 21 33 42 
Linked List in reverse order: 42 33 21 5 

##Conclusion
The program successfully executes reverse traversal of singly linked list using recursion.  It does not replace the original list, but correctly prints out the items inverted. The result is adequate and correct and confirms the algorithm behaves as it should.




