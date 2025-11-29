#include <stdio.h>
#include <stdlib.h> // For exit()

#define MAX_SIZE 5 // Define the maximum size of the stack

int stack[MAX_SIZE];
int top = -1; // -1 means the stack is empty

// --- Stack Operations ---

// Check if the stack is full
int isFull() {
    return (top == MAX_SIZE - 1);
}

// Check if the stack is empty
int isEmpty() {
    return (top == -1);
}

// Add an element to the top (push)
void push(int value) {
    if (isFull()) {
        printf("Error: Stack Overflow! Cannot push.\n");
    } else {
        top++; // Increment top
        stack[top] = value; // Add the value
        printf("%d pushed to stack.\n", value);
    }
}

// Remove an element from the top (pop)
void pop() {
    if (isEmpty()) {
        printf("Error: Stack Underflow! Cannot pop.\n");
    } else {
        printf("%d popped from stack.\n", stack[top]);
        top--; // Decrement top
    }
}

// View the top element
void peek() {
    if (isEmpty()) {
        printf("Stack is empty.\n");
    } else {
        printf("Top element is: %d\n", stack[top]);
    }
}

// Display all elements in the stack
void displayStack() {
    if (isEmpty()) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack (top to bottom): ");
        for (int i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

// --- Main Function with Menu ---
int main() {
    int choice, value;
    printf("\n--- STACK OPERATIONS (MAX_SIZE = %d) ---\n", MAX_SIZE);
    
    while (1) { // Infinite loop for menu
        printf("\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                displayStack();
                break;
            case 5:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
