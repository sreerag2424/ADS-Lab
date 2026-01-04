//Graph using adjacency matrix 

#include <stdio.h>

int a[10][10], visited[10], n;

/* DFS Traversal */
void DFS(int v) {
    printf("%d ", v);
    visited[v] = 1;
    for (int i = 0; i < n; i++) {
        if (a[v][i] == 1 && !visited[i])
            DFS(i);
    }
}

/* BFS Traversal */
void BFS(int v) {
    int queue[10], front = 0, rear = 0;
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    queue[rear++] = v;
    visited[v] = 1;

    while (front < rear) {
        v = queue[front++];
        printf("%d ", v);

        for (int i = 0; i < n; i++) {
            if (a[v][i] == 1 && !visited[i]) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
}

/* Topological Sort */
void topologicalSort() {
    int indeg[10] = {0}, stack[10], top = -1;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (a[j][i] == 1)
                indeg[i]++;

    for (int i = 0; i < n; i++)
        if (indeg[i] == 0)
            stack[++top] = i;

    printf("Topological Order: ");
    while (top != -1) {
        int v = stack[top--];
        printf("%d ", v);

        for (int i = 0; i < n; i++) {
            if (a[v][i] == 1) {
                indeg[i]--;
                if (indeg[i] == 0)
                    stack[++top] = i;
            }
        }
    }
}

int main() {
    int start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    printf("\nDFS Traversal: ");
    DFS(start);

    printf("\nBFS Traversal: ");
    BFS(start);

    printf("\n");
    topologicalSort();

    return 0;
}
