//Implement singly Linked List with operations to insert, delete, display forward and reverse order list, search element

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void insertNode();
void deleteElement();
void displayForward();
void displayReverse(struct Node* current);
void searchElement();

int main() {
    int choice;
        printf("\n--- SINGLY LINKED LIST OPERATIONS ---\n");
        printf("1. Insert a Node\n");
        printf("2. Delete an Element\n");
        printf("3. Display List (Forward)\n");
        printf("4. Display List (Reverse)\n");
        printf("5. Search for an Element\n");
        printf("6. Exit\n");
        printf("---------------------------------------\n");
        while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insertNode();
                break;
            case 2:
                deleteElement();
                break;
            case 3:
                displayForward();
                break;
            case 4:
                if (head == NULL) {
                    printf("List is empty.\n");
                } else {
                    printf("List in reverse order: [ ");
                    displayReverse(head);
                    printf("]\n");
                }
                break;
            case 5:
                searchElement();
                break;
            case 6:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice! \n");
        }
    }
    return 0;
}

void insertNode() {
    int value, pos, i = 1;
    struct Node *newNode, *temp;

    newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Enter the value to insert: ");
    scanf("%d", &newNode->data);
    printf("Enter the position to insert at (1 for beginning): ");
    scanf("%d", &pos);

    if (pos == 1) { 
        newNode->next = head;
        head = newNode;
        printf("Node inserted at the beginning.\n");
    } else { 
        temp = head;
        
        while (i < pos - 1 && temp != NULL) {
            temp = temp->next;
            i++;
        }

        if (temp == NULL) {
            printf("Invalid position. Position is beyond the list size.\n");
            free(newNode); 
        } else {
            newNode->next = temp->next;
            temp->next = newNode;
            printf("Node inserted at position %d.\n", pos);
        }
    }
}

void deleteElement() {
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    int value;
    printf("Enter the value of the element to delete: ");
    scanf("%d", &value);

    struct Node *temp = head, *prev = NULL;

    if (temp != NULL && temp->data == value) {
        head = temp->next; 
        free(temp);        
        printf(" Element %d deleted successfully.\n", value);
        return;
    }

    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Element %d not found in the list.\n", value);
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf(" Element %d deleted successfully.\n", value);
}

void displayForward() {
    struct Node* temp = head;
    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("List elements (Forward): [ ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("]\n");
}

void displayReverse(struct Node* current) {
    if (current == NULL) {
        return;
    }
    
    displayReverse(current->next);
    
    printf("%d ", current->data);
}

void searchElement() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    
    int value, pos = 1;
    printf("Enter the value to search for: ");
    scanf("%d", &value);

    struct Node* temp = head;
    while (temp != NULL) {
        if (temp->data == value) {
            printf(" Element %d found at position %d.\n", value, pos);
            return;
        }
        temp = temp->next;
        pos++;
    }

    printf("Element %d not found in the list.\n", value);
}
