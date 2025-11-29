#include <stdio.h>
#include <stdlib.h> 

#define MAX_SIZE 5 
int stack[MAX_SIZE];
int top = -1; 

int isFull() {
    return (top == MAX_SIZE - 1);
}

int isEmpty() {
    return (top == -1);
}

void push(int value) {
    if (isFull()) {
        printf("Error: Stack Overflow! Cannot push.\n");
    } else {
        top++; 
        stack[top] = value; 
        printf("%d pushed to stack.\n", value);
    }
}

void pop() {
    if (isEmpty()) {
        printf("Error: Stack Underflow! Cannot pop.\n");
    } else {
        printf("%d popped from stack.\n", stack[top]);
        top--; 
    }
}

void peek() {
    if (isEmpty()) {
        printf("Stack is empty.\n");
    } else {
        printf("Top element is: %d\n", stack[top]);
    }
}

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

int main() {
    int choice, value;
    printf("\n--- STACK OPERATIONS (MAX_SIZE = %d) ---\n", MAX_SIZE);
    
    while (1) { 
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
