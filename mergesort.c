//Merge two sorted Array and store in a third array

#include <stdio.h>

// Function to print the elements of an array (unchanged)
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    // Declare arrays with a fixed maximum size
    int arr1[100], arr2[100], arr3[200];
    int size1, size2;

    // --- Get Input for the First Array ---
    printf("Enter the number of elements for the first sorted array: ");
    scanf("%d", &size1);
    printf("Enter %d elements for the first array (in sorted order):\n", size1);
    for (int i = 0; i < size1; i++) {
        scanf("%d", &arr1[i]);
    }

    // --- Get Input for the Second Array ---
    printf("\nEnter the number of elements for the second sorted array: ");
    scanf("%d", &size2);
    printf("Enter %d elements for the second array (in sorted order):\n", size2);
    for (int i = 0; i < size2; i++) {
        scanf("%d", &arr2[i]);
    }

    // --- The rest of the logic is the same ---
    int mergedSize = size1 + size2;

    // Pointers (indices) for all three arrays
    int i = 0; // for arr1
    int j = 0; // for arr2
    int k = 0; // for arr3 (merged array)

    // Core Merging Logic
    while (i < size1 && j < size2) {
        if (arr1[i] < arr2[j]) {
            arr3[k++] = arr1[i++];
        } else {
            arr3[k++] = arr2[j++];
        }
    }

    // Store remaining elements from arr1, if any
    while (i < size1) {
        arr3[k++] = arr1[i++];
    }

    // Store remaining elements from arr2, if any
    while (j < size2) {
        arr3[k++] = arr2[j++];
    }

    // --- Print the results ---
    printf("\n--- RESULTS ---\n");
    printf("Array 1: ");
    printArray(arr1, size1);

    printf("Array 2: ");
    printArray(arr2, size2);

    printf("✅ Merged Sorted Array: ");
    printArray(arr3, mergedSize);

    return 0;
}
