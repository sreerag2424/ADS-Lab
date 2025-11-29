//Implement Circular Queue with operations Add, Delete, Display using Arrays

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5 

int cqueue[MAX_SIZE];
int front = -1;
int rear = -1;

void enqueue(int value);
void dequeue();
void display();

int main() {
    int choice, value;

    printf("\n--- CIRCULAR QUEUE OPERATIONS USING ARRAY ---\n");
    while (1) {
        printf("\n1. Enqueue (Add)\n2. Dequeue (Delete)\n3. Display Queue\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to add: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

void enqueue(int value) {
    
    if ((rear + 1) % MAX_SIZE == front) {
        printf("Queue Overflow! Cannot add element.\n");
        return;
    }
    
    
    if (front == -1) {
        front = 0;
    }

   
    rear = (rear + 1) % MAX_SIZE;
    cqueue[rear] = value;
    printf("%d added to the queue.\n", value);
}

void dequeue() {
    
    if (front == -1) {
        printf("Queue Underflow! Cannot delete from empty queue.\n");
        return;
    }

    printf("%d deleted from the queue.\n", cqueue[front]);

 
    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        
        front = (front + 1) % MAX_SIZE;
    }
}


void display() {
    
    if (front == -1) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements are: [ ");
    int i = front;
    while(1) {
        printf("%d ", cqueue[i]);
        if (i == rear) {
            break;
        }
        i = (i + 1) % MAX_SIZE;
    }
    printf("]\n");
}
