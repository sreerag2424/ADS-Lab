//Implement Doubly Linked List and Perform Insert Elements at front, back,intermediate positions, Delete Elements front, back, intermediate positions, Display through forward and backward links

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* head = NULL;

void insertFront();
void insertBack();
void insertIntermediate();
void deleteFront();
void deleteBack();
void deleteIntermediate();
void displayForward();
void displayBackward();

int main() {
    int choice;
    
        printf("\n--- DOUBLY LINKED LIST OPERATIONS ---\n");
        printf("--- Insert ---\n");
        printf("1. At Front\n2. At Back\n3. At Intermediate Position\n");
        printf("--- Delete ---\n");
        printf("4. From Front\n5. From Back\n6. From Intermediate Position\n");
        printf("--- Display ---\n");
        printf("7. Display Forward\n8. Display Backward\n");
        printf("9. Exit\n");
        printf("---------------------------------------\n");
        while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insertFront(); break;
            case 2: insertBack(); break;
            case 3: insertIntermediate(); break;
            case 4: deleteFront(); break;
            case 5: deleteBack(); break;
            case 6: deleteIntermediate(); break;
            case 7: displayForward(); break;
            case 8: displayBackward(); break;
            case 9: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertFront() {
    int value;
    printf("Enter value to insert at front: ");
    scanf("%d", &value);
    struct Node* newNode = createNode(value);

    if (head == NULL) { 
        head = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    printf("%d inserted at the front.\n", value);
}

void insertBack() {
    int value;
    printf("Enter value to insert at back: ");
    scanf("%d", &value);
    struct Node* newNode = createNode(value);

    if (head == NULL) { 
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != NULL) { 
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
    printf("%d inserted at the back.\n", value);
}

void insertIntermediate() {
    int value, pos, i = 1;
    printf("Enter position to insert at: ");
    scanf("%d", &pos);

    if (pos < 1) {
        printf("Invalid position!\n");
        return;
    }
    if (pos == 1) {
        insertFront();
        return;
    }

    printf("Enter value to insert: ");
    scanf("%d", &value);
    struct Node* newNode = createNode(value);
    struct Node* temp = head;

    while (i < pos - 1 && temp != NULL) {
        temp = temp->next;
        i++;
    }

    if (temp == NULL) {
        printf("Position out of bounds.\n");
        free(newNode);
    } else {
        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next != NULL) {
            temp->next->prev = newNode;
        }
        temp->next = newNode;
        printf("%d inserted at position %d.\n", value, pos);
    }
}

void deleteFront() {
    if (head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }
    struct Node* temp = head;
    int deletedValue = temp->data;

    head = head->next;
    if (head != NULL) {
        head->prev = NULL;
    }
    free(temp);
    printf("%d deleted from the front.\n", deletedValue);
}

void deleteBack() {
    if (head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    int deletedValue = temp->data;
    if (temp->prev != NULL) {
        temp->prev->next = NULL;
    } else { 
        head = NULL;
    }
    free(temp);
    printf("%d deleted from the back.\n", deletedValue);
}

void deleteIntermediate() {
    if (head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }
    int pos, i = 1;
    printf("Enter position to delete: ");
    scanf("%d", &pos);

    if (pos < 1) {
        printf("Invalid position!\n");
        return;
    }
    if (pos == 1) {
        deleteFront();
        return;
    }
    
    struct Node* temp = head;
    while (i < pos && temp != NULL) {
        temp = temp->next;
        i++;
    }

    if (temp == NULL) {
        printf("Position out of bounds.\n");
    } else {
        int deletedValue = temp->data;
        temp->prev->next = temp->next;
        if (temp->next != NULL) {
            temp->next->prev = temp->prev;
        }
        free(temp);
        printf("Element at position %d (value: %d) deleted.\n", pos, deletedValue);
    }
}

void displayForward() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    printf("List (Forward): [ ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("]\n");
}

void displayBackward() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    while (temp->next != NULL) { 
        temp = temp->next;
    }

    printf("List (Backward): [ ");
    while (temp != NULL) { 
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("]\n");
}
