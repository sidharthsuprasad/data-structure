#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

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

void deleteAfter(struct Node* prevNode) {
    if (prevNode == NULL || prevNode->next == NULL) {
        printf("No node to delete after the given node.\n");
        return;
    }

    struct Node* temp = prevNode->next;
    prevNode->next = temp->next;
    free(temp);
}

void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    head->data = 10;
    head->next = NULL;

    struct Node* second = (struct Node*)malloc(sizeof(struct Node));
    second->data = 20;
    second->next = NULL;
    head->next = second;

    struct Node* third = (struct Node*)malloc(sizeof(struct Node));
    third->data = 30;
    third->next = NULL;
    second->next = third;

    printf("Initial Linked List:\n");
    printList(head);

    // Insertion after a specific node (in this case, after the first node)
    insertAfter(head, 15);
    printf("Linked List after inserting 15 after the first node:\n");
    printList(head);

    // Deletion after a specific node (in this case, after the first node)
    deleteAfter(head);
    printf("Linked List after deleting the node after the first node:\n");
    printList(head);

    // Deleting after the last node (to show handling of that case)
    deleteAfter(second); // This should print a message since there's no node to delete

    return 0;
}

