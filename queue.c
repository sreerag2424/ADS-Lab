#include <stdio.h>
#include <stdlib.h> 

#define MAX_SIZE 5 

int queue[MAX_SIZE];
int front = -1; 
int rear = -1;  

int isFull() {
    return (rear == MAX_SIZE - 1);
}

int isEmpty() {
    return (front == -1 || front > rear);
}

void enqueue(int value) {
    if (isFull()) {
        printf("Error: Queue Overflow! Cannot enqueue.\n");
    } else {
        if (front == -1) { 
            front = 0;
        }
        rear++; 
        queue[rear] = value; 
        printf("%d enqueued to queue.\n", value);
    }
}

void dequeue() {
    if (isEmpty()) {
        printf("Error: Queue Underflow! Cannot dequeue.\n");
    } else {
        printf("%d dequeued from queue.\n", queue[front]);
        front++; 
        
        if (front > rear) {
            front = -1;
            rear = -1;
        }
    }
}

void peek() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
    } else {
        printf("Front element is: %d\n", queue[front]);
    }
}

void displayQueue() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue (front to rear): ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, value;
    printf("\n--- QUEUE OPERATIONS (MAX_SIZE = %d) ---\n", MAX_SIZE);

    while (1) { 
        printf("\n1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peek();
                break;
            case 4:
                displayQueue();
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
