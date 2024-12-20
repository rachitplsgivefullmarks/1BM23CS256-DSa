#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};


struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}


void addnode(struct Node** head, int newValue) {
    struct Node* newNode = createNode(newValue);
    if (newNode == NULL) return;


    newNode->next = *head;

    if (*head != NULL) {
        (*head)->prev = newNode;
    }

    *head = newNode;
}


void insertLeft(struct Node** head, int newValue, int targetValue) {
    struct Node* temp = *head;


    while (temp != NULL && temp->data != targetValue) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Target node with value %d not found\n", targetValue);
        return;
    }


    struct Node* newNode = createNode(newValue);


    newNode->next = temp;
    newNode->prev = temp->prev;


    if (temp->prev != NULL) {
        temp->prev->next = newNode;
    } else {
        *head = newNode;
    }

    temp->prev = newNode;
}


void deleteNode(struct Node** head, int value) {
    struct Node* temp = *head;


    while (temp != NULL && temp->data != value) {
        temp = temp->next;
    }


    if (temp == NULL) {
        printf("Node with value %d not found\n", value);
        return;
    }


    if (temp == *head) {
        *head = temp->next;
    }

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }


    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }

    free(temp);
}


void displayList(struct Node* head) {
    struct Node* temp = head;
    if (temp == NULL) {
        printf("The list is empty\n");
        return;
    }

    printf("List contents: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}


int main() {
    struct Node* head = NULL;
    int choice, value, targetValue;
     printf("\nMenu:\n");
        printf("1. Add Node\n");
        printf("2. Insert Node to the Left\n");
        printf("3. Delete Node\n");
        printf("4. Display List\n");
        printf("5. Exit\n");

    do {


        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the value: ");
                scanf("%d", &value);
                addnode(&head, value);
                break;

            case 2:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                printf("Enter the target value to insert before: ");
                scanf("%d", &targetValue);
                insertLeft(&head, value, targetValue);
                break;

            case 3:
                printf("Enter the value of the node to delete: ");
                scanf("%d", &value);
                deleteNode(&head, value);
                break;

            case 4:
                displayList(head);
                break;

            case 5:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
