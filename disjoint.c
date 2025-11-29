//Implement Disjoint Set and assossiated opertaions (Create,Union,Find)

#include <stdio.h>
#include <stdlib.h> // For malloc() and free()

void createSet(int parent[], int size[], int n) {
    for (int i = 0; i < n; i++) {
        parent[i] = i; // Initially, each element is its own parent
        size[i] = 1;   // The size of each set is 1
    }
}

 */
int find(int parent[], int i) {
    // Base case: If 'i' is the parent of itself, it's the root
    if (parent[i] == i)
        return i;

    // Path Compression:
    // Recursively find the root and make every node on the
    // path point directly to the root.
    parent[i] = find(parent, parent[i]);
    return parent[i];
}

void unionSets(int parent[], int size[], int x, int y) {
    // Find the representatives (roots) of the sets
    int rootX = find(parent, x);
    int rootY = find(parent, y);

    // If they are already in the same set, do nothing
    if (rootX == rootY) {
        printf("Elements %d and %d are already in the same set.\n", x, y);
        return;
    }

    // Union by Size:
    // Attach the smaller tree to the root of the larger tree.
    if (size[rootX] < size[rootY]) {
        parent[rootX] = rootY;       // Make rootY the parent of rootX
        size[rootY] += size[rootX];  // Update the size of the new set
    } else {
        parent[rootY] = rootX;       // Make rootX the parent of rootY
        size[rootX] += size[rootY];  // Update the size of the new set
    }
    
    printf("Union of %d and %d successful.\n", x, y);
}

int main() {
    int n;
    printf("--- Disjoint Set Union (Union-Find) ---\n");
    printf("Enter the total number of elements (e.g., 10 for elements 0-9): ");
    
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input. Number of elements must be a positive integer.\n");
        return 1;
    }

    // Allocate memory for parent and size arrays
    int *parent = (int *)malloc(n * sizeof(int));
    int *size = (int *)malloc(n * sizeof(int));

    if (parent == NULL || size == NULL) {
        printf("Error: Memory allocation failed!\n");
        return 1;
    }

    // --- 1. Create Operation ---
    createSet(parent, size, n);
    printf("Created %d disjoint sets for elements 0 to %d.\n", n, n - 1);

    int choice, x, y;

    while (1) {
        printf("\n----------------------------------\n");
        printf("Select an operation:\n");
        printf("  1. Union(x, y)\n");
        printf("  2. Find(x)\n");
        printf("  3. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter 1, 2, or 3.\n");
            // Clear the input buffer
            while (getchar() != '\n');
            continue;
        }

        if (choice == 3) {
            break; // Exit the loop
        }
        
        // Input validation function
        auto int validate_input = (int val) -> int {
            if (val < 0 || val >= n) {
                printf("Error: Element must be between 0 and %d.\n", n - 1);
                return 0; // 0 for false (invalid)
            }
            return 1; // 1 for true (valid)
        };


        switch (choice) {
            case 1: // --- 2. Union Operation ---
                printf("Enter two elements (x y) to union: ");
                if (scanf("%d %d", &x, &y) != 2) {
                    printf("Invalid input. Please enter two space-separated numbers.\n");
                    while (getchar() != '\n'); // Clear buffer
                    continue;
                }
                
                // Validate inputs
                if (validate_input(x) && validate_input(y)) {
                    unionSets(parent, size, x, y);
                }
                break;

            case 2: // --- 3. Find Operation ---
                printf("Enter element (x) to find its representative: ");
                if (scanf("%d", &x) != 1) {
                    printf("Invalid input. Please enter one number.\n");
                    while (getchar() != '\n'); // Clear buffer
                    continue;
                }

                // Validate input
                if (validate_input(x)) {
                    int rep = find(parent, x);
                    printf("The representative of %d is: %d\n", x, rep);
                }
                break;

            default:
                printf("Invalid choice. Please enter 1, 2, or 3.\n");
                break;
        }
    }

    // Clean up allocated memory
    free(parent);
    free(size);

    printf("Exiting program. Goodbye!\n");
    return 0;
}
