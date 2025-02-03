#include <stdio.h>
#include <stdlib.h>

// Define the structure 'Node'
struct Node {
    int data;
    struct Node *next;
};

// Function to insert a node at the end of the list
void insertNode(struct Node **head, int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to delete a node by value
void deleteNode(struct Node **head, int data) {
    struct Node *temp = *head;
    struct Node *prev = NULL;

    // If the node to be deleted is the head
    if (temp != NULL && temp->data == data) {
        *head = temp->next;
        free(temp);
        return;
    }

    // Search for the node to be deleted
    while (temp != NULL && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }

    // If the node was not found
    if (temp == NULL) {
        printf("Node with data %d not found\n", data);
        return;
    }

    // Unlink the node from the list
    prev->next = temp->next;
    free(temp);
}

// Function to display the list
void displayList(struct Node *head) {
    struct Node *temp = head;
    printf("List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node *head = NULL;

    // Insert nodes
    insertNode(&head, 10);
    insertNode(&head, 20);
    insertNode(&head, 30);
    insertNode(&head, 40);

    // Display the list
    displayList(head);

    // Delete a node
    deleteNode(&head, 20);
    displayList(head);

    // Free the list (not shown here for brevity)

    return 0;
}