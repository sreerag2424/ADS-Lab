#include <stdio.h>
#define N 10   // Universal set size

void printBit(int a[]) {
    for(int i=0;i<N;i++)
        printf("%d ",a[i]);
    printf("\n");
}

int main() {
    int A[N]={0}, B[N]={0}, U[N], I[N], D[N];
    int n, x;

    // Input Set A
    printf("Enter number of elements in Set A: ");
    scanf("%d",&n);
    printf("Enter elements: ");
    for(int i=0;i<n;i++) {
        scanf("%d",&x);
        A[x]=1;          // Convert to bit string
    }

    // Input Set B
    printf("Enter number of elements in Set B: ");
    scanf("%d",&n);
    printf("Enter elements: ");
    for(int i=0;i<n;i++) {
        scanf("%d",&x);
        B[x]=1;          // Convert to bit string
    }

    // Set operations
    for(int i=0;i<N;i++) {
        U[i]=A[i] | B[i];     // Union
        I[i]=A[i] & B[i];     // Intersection
        D[i]=A[i] & ~B[i];    // Difference
    }

    // Output
    printf("\nBit String A: "); printBit(A);
    printf("Bit String B: "); printBit(B);
    printf("Union: "); printBit(U);
    printf("Intersection: "); printBit(I);
    printf("Difference (A-B): "); printBit(D);

    return 0;
}
