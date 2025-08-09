#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertAfter(struct Node* prevNode, int data) {
    if (prevNode == NULL) {
        printf("The given previous node cannot be NULL\n");
        return;
    }
    struct Node* newNode = createNode(data);
    newNode ->next = prevNode ->next;  
    newNode->prev = prevNode;        
    prevNode->next = newNode;        
    if (newNode->next != NULL) {
        newNode->next->prev = newNode; 
    }
}

// Delete a given node
void deleteNode(struct Node** head, struct Node* delNode) {
    if (*head == NULL || delNode == NULL)
        return;

    if (*head == delNode)
        *head = delNode->next;  

    if (delNode->next != NULL)
        delNode->next->prev = delNode->prev;  

    if (delNode->prev != NULL)
        delNode->prev->next = delNode->next;  

    free(delNode);
}

// Display list forward
void displayForward(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main(){
    struct Node* head = createNode(6);
    struct Node* second = createNode(9);
    struct Node* third = createNode(12);

    head->next = second;
    second->prev = head;
    second->next = third;
    third->prev = second;

    printf("Original list is: ");
    displayForward(head);

    insertAfter(second, 10);
    printf("insert 10 after 9 then result is: ");
    displayForward(head);

    deleteNode(&head, third);
    printf("After deleting 12 the result is: ");
    displayForward(head);

    return 0;
}
