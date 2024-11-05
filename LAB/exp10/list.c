#include <stdio.h>
#include <stdlib.h>  // Include this header for malloc and free

struct Node {
    int data;
    struct Node* next;
};

// Function to insert a node at the beginning
void insertAtBeginning(struct Node** head, int newData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = *head;
    *head = newNode;
}

// Function to insert a node at the end
void insertAtEnd(struct Node** head, int newData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head;

    newNode->data = newData;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    while (last->next != NULL) {
        last = last->next;
    }
    last->next = newNode;
}

// Function to insert a node after a given node
void insertAfter(struct Node* prevNode, int newData) {
    if (prevNode == NULL) {
        printf("The given previous node cannot be NULL.\n");
        return;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = prevNode->next;
    prevNode->next = newNode;
}

// Function to delete a node from the beginning
void deleteFromBeginning(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty, nothing to delete.\n");
        return;
    }

    struct Node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

// Function to delete a node from the end
void deleteFromEnd(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty, nothing to delete.\n");
        return;
    }

    struct Node* temp = *head;

    if (temp->next == NULL) {
        free(temp);
        *head = NULL;
        return;
    }

    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

// Function to delete a node after a given node
void deleteAfter(struct Node* prevNode) {
    if (prevNode == NULL || prevNode->next == NULL) {
        printf("No node to delete after the given node.\n");
        return;
    }

    struct Node* temp = prevNode->next;
    prevNode->next = temp->next;
    free(temp);
}

// Function to print the linked list
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    struct Node* head = NULL;

    // Inserting nodes at the beginning
    insertAtBeginning(&head, 20);
    insertAtBeginning(&head, 10);
    printf("Linked List after inserting at the beginning:\n");
    printList(head);

    // Inserting nodes at the end
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);
    printf("Linked List after inserting at the end:\n");
    printList(head);

    // Inserting after a specific node (after the first node)
    insertAfter(head, 25);
    printf("Linked List after inserting 25 after the first node:\n");
    printList(head);

    // Deleting from the beginning
    deleteFromBeginning(&head);
    printf("Linked List after deleting from the beginning:\n");
    printList(head);

    // Deleting from the end
    deleteFromEnd(&head);
    printf("Linked List after deleting from the end:\n");
    printList(head);

    // Deleting after a specific node (after the first node)
    deleteAfter(head);
    printf("Linked List after deleting the node after the first node:\n");
    printList(head);

    // Trying to delete from an empty list
    deleteFromBeginning(&head); // Should delete last element
    deleteFromEnd(&head);       // Should print message since list is empty
    deleteAfter(head);          // Should print message since there's no node to delete

    return 0;
}


