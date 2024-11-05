#include <stdio.h>
#include <stdlib.h>  // Necessary for malloc and free

struct Node {
    int data;
    struct Node* next;
};

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

void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);

    printf("Linked List after insertions at the end:\n");
    printList(head);

    deleteFromEnd(&head);
    printf("Linked List after deletion from the end:\n");
    printList(head);

    deleteFromEnd(&head);
    printf("Linked List after another deletion from the end:\n");
    printList(head);

    deleteFromEnd(&head);
    printf("Linked List after deleting the last element:\n");
    printList(head);

    deleteFromEnd(&head); // Trying to delete from an empty list

    return 0;
}


