//6. Write a function to remove a node from the end of a singly linked list in C.
// Hint: To remove the last node from a singly linked list, first check if the list is empty or has
// only one node.
// If there’s only one node, free that node and set the head to NULL.
// Otherwise, traverse the list to reach the node just before the last node (second-to-last node).
// Once there, free the last node and set the second-to-last node’s next pointer to NULL to
// remove it, Use pythontutor.com to check your code.
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
void deleteLast(struct Node** head) {
    // Check if the list is empty
    if (*head == NULL) {
        return; // List is empty, nothing to remove
    }

    // If the list has only one node
    if ((*head)->next == NULL) {
        free(*head); 
        *head = NULL; 
        return;
    }

    // Find the second-to-last node
    struct Node* current = *head;
    while (current->next->next != NULL) {
        current = current->next;
    }

    // After reaching the second-to-last node, remove the last node
    free(current->next); 
    current->next = NULL;
}
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
    printf("%d -> ", current->data);
    current = current->next;
    }
    printf("NULL\n");
}
int main() {
    struct Node* head = createNode(10);
    head->next = createNode(20);
    head->next->next = createNode(30);
    printf("Original List: ");
    printList(head);
    deleteLast(&head);
    printf("List after removing last node: ");
    printList(head);
    return 0;
}
