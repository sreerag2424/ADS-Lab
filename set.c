//Implement Set Data Structure and set operations (Union, Intersection, Difference) using Bitstring Representation

#include <stdio.h>
#include <stdlib.h>

#define UNIVERSAL_SET_SIZE 32

void insertElement(unsigned int *set, int element);
void displaySet(const char* setName, unsigned int set);
void performSetOperations(unsigned int setA, unsigned int setB);

int main() {
    unsigned int setA = 0;
    unsigned int setB = 0;
    int choice, value;

    
        printf("\n--- SET OPERATIONS USING BITSTRINGS ---\n");
        printf("1. Insert into Set A\n");
        printf("2. Insert into Set B\n");
        printf("3. Display Both Sets\n");
        printf("4. Show Union, Intersection, and Difference\n");
        printf("5. Exit\n");
        printf("-----------------------------------------\n");
        while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element for Set A (0-%d): ", UNIVERSAL_SET_SIZE - 1);
                scanf("%d", &value);
                insertElement(&setA, value);
                break;
            case 2:
                printf("Enter element for Set B (0-%d): ", UNIVERSAL_SET_SIZE - 1);
                scanf("%d", &value);
                insertElement(&setB, value);
                break;
            case 3:
                displaySet("Set A", setA);
                displaySet("Set B", setB);
                break;
            case 4:
                performSetOperations(setA, setB);
                break;
            case 5:
                printf("Exiting program. Goodbye! 👋\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

void insertElement(unsigned int *set, int element) {
    if (element < 0 || element >= UNIVERSAL_SET_SIZE) {
        printf("Error: Element must be between 0 and %d.\n", UNIVERSAL_SET_SIZE - 1);
        return;
    }
    *set = *set | (1 << element);
    printf("Element %d added.\n", element);
}
void displaySet(const char* setName, unsigned int set) {
    printf("%s = { ", setName);
    int isEmpty = 1;
   
    for (int i = 0; i < UNIVERSAL_SET_SIZE; i++) {
        
        if ((set & (1 << i)) != 0) {
            printf("%d ", i);
            isEmpty = 0;
        }
    }
    if (isEmpty) {
        printf("(empty) ");
    }
    printf("}\n");
}

void performSetOperations(unsigned int setA, unsigned int setB) {
    unsigned int union_set, intersection_set, diff_A_B, diff_B_A;

    union_set = setA | setB;
    
    intersection_set = setA & setB;
    
  
    diff_A_B = setA & (~setB);

    diff_B_A = setB & (~setA);

    printf("\n--- RESULTS ---\n");
    displaySet("Set A           ", setA);
    displaySet("Set B           ", setB);
    printf("-----------------\n");
    displaySet("Union (A U B)   ", union_set);
    displaySet("Intersection (A ∩ B)", intersection_set);
    displaySet("Difference (A - B)", diff_A_B);
    displaySet("Difference (B - A)", diff_B_A);
    printf("-----------------\n");
}
