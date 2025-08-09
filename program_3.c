#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void reverseTraversal(struct Node* head) {
    if (head == NULL) 
        return;
    reverseTraversal(head->next);  
    printf("%d ", head->data);    
}

void displayList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    insertEnd(&head, 5);
    insertEnd(&head, 21);
    insertEnd(&head, 33);
    insertEnd(&head, 42);

    printf("Linked List in normal form: ");
    displayList(head);

    printf("Linked List in reverse order: ");
    reverseTraversal(head);

    return 0;
}
