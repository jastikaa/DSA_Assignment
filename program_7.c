#include <stdio.h>
#include <limits.h>

#define V 7
#define INF INT_MAX

int findMin(int dist[], int visited[]) {
    int min = INF;
    int minIndex = -1;

    for (int i = 0; i < V; i++) {
        if (visited[i] == 0 && dist[i] < min) {
            min = dist[i];
            minIndex = i;
        }
    }

    return minIndex;
}

void dijkstra(int graph[V][V], int start) {
    int dist[V];
    int visited[V];

    for (int i = 0; i < V; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }

    dist[start] = 0;

    for (int i = 0; i < V - 1; i++) {
        int u = findMin(dist, visited);
        visited[u] = 1;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] != 0 && visited[v] == 0 && dist[u] != INF) {
                int newDist = dist[u] + graph[u][v];
                if (newDist < dist[v]) {
                    dist[v] = newDist;
                }
            }
        }
    }

    printf("Shortest distances from vertex %d:\n", start);
    for (int i = 0; i < V; i++) {
        printf("To vertex %d: %d\n", i, dist[i]);
    }
}

int main() {
    int graph[V][V] = {
        {0, 7, 9, 0, 0, 0, 0},
        {0, 0, 10, 15, 11, 0, 0},
        {0, 0, 0, 0, 0, 2, 0},
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 0},
        {4, 23, 25, 6, 7, 8, 0}
    };

    dijkstra(graph, 6);
    return 0;
}