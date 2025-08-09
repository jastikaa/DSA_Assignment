#include<stdio.h>
#include<stdlib.h>

#define MAX 10

int adjMatrix[MAX][MAX];
int visited[MAX];
int queue[MAX], front = -1, rear = -1;

void addEdge(int u, int v) {
    adjMatrix[u][v] = 1;
    adjMatrix[v][u] = 1; 
}
void BFS(int start, int vertices) {
    for (int i = 0; i < vertices; i++)
        visited[i] = 0;
    front = rear = -1;
    queue[++rear] = start;
    visited[start] = 1;

    printf("BFS Traversal: ");
    while (front != rear) {
        int current = queue[++front];
        printf("%d ", current);

        for (int i = 0; i < vertices; i++) {
            if (adjMatrix[current][i] == 1 && visited[i] == 0) {
                queue[++rear] = i;
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

void DFS_Recursive(int vertex, int vertices) {
    visited[vertex] = 1;
    printf("%d ", vertex);

    for (int i = 0; i < vertices; i++) {
        if (adjMatrix[vertex][i] == 1 && visited[i] == 0) {
            DFS_Recursive(i, vertices);
        }
    }
}

void DFS(int start, int vertices) {
    for (int i = 0; i < vertices; i++)
        visited[i] = 0;

    printf("DFS Traversal: ");
    DFS_Recursive(start, vertices);
    printf("\n");
}

int main() {
    int vertices = 5; 

    for (int i = 0; i < vertices; i++)
        for (int j = 0; j < vertices; j++)
            adjMatrix[i][j] = 0;
    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 3);
    addEdge(1, 4);
    addEdge(2, 4);
    
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++)
            printf("%d ", adjMatrix[i][j]);
        printf("\n");
    }
    BFS(0, vertices);
    DFS(0, vertices);

    return 0;
}
