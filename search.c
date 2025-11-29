//Search an element with in an array using function

#include <stdio.h>

int linearSearch(int arr[], int size, int key) {
    
    for (int i = 0; i < size; i++) {
       
        if (arr[i] == key) {
            return i; 
        }
    }
    return -1;
}

int main() {
    int myArray[50];
    int arraySize, i, elementToFind;

    printf("Enter the number of elements in the array (up to 50): ");
    scanf("%d", &arraySize);

    if (arraySize <= 0 || arraySize > 50) {
        printf("Invalid array size. Please run the program again.\n");
        return 1; 
    }

    printf("Enter %d integers for the array:\n", arraySize);
    for (i = 0; i < arraySize; i++) {
        scanf("%d", &myArray[i]);
    }

    printf("\nEnter the element you want to search for: ");
    scanf("%d", &elementToFind);

    int result = linearSearch(myArray, arraySize, elementToFind);

    if (result != -1) {
        printf("\n✅ Element %d found at index %d.\n", elementToFind, result);
    } else {
        printf("\n❌ Element %d not found in the array.\n", elementToFind);
    }

    return 0;
}
