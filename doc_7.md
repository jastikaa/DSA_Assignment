# Question 8: Dijkstra’s algorithm implementation to find the shortest path
## (a) Data structure defination
#define V7: The number of vertices in graph is defined to hold 7.
#define INF INT MAX: Defines INF to the highest integer value, i.e. infinity (used in case of inaccessible vertices).

- graph[V][V]: An array with dimension n (vertices) X n (vertices) to represent a graph in 2D. When graph[i][j] = 0, the graph does not have the direct edge between the vertex system i and j. Otherwise, value depicts the edge weight.
- dist[V]: An array where the shortest distance from the starting vertex to all other vertices is stored.
- visited[V]: An array to keep track of the vertices processed by the algorithm.

## (b) Description of the Functions Implemented
1. findMin(int dist[], int visited[])
Purpose: Visits the vertex holding the minimum distance value that has not yet been visited.
Logic: Performs a loop through all the vertices, trying to find the unvisited minimum dist[] vertex. Returns its index.

2. ddijkstra(int graph[][V], int start)
Purpose: Carries out the algorithm of Dijkstra to determine the shortest path between the starting vertex and the rest of the vertices.
Steps: 
- sets distances to all INF and visited[] to 0.
- starts with initializing the distance of the start vertex with value 0.
- repeats V-1 times:
- starts with taking the closest unexplored vertex.
- marks it as visited.
- places new values in the neighbors' distances when a shorter path is found.
- displays the shortest distance between the start vertex and the remaining vertices.

## (c) An Overview of How the main() Method Is Organized
- Adjacency matrix graph of a weighted directed graph is an adjacency matrix graph with an attached edge weight.
- It called the dijkstra(graph, 6) where vertex 6 is used as the source.
-All vertices display the shortest path results.

## (d) Output of a Complete Run of the Program
Shortest distances from vertex 6:
To vertex 0: 4
To vertex 1: 11
To vertex 2: 13
To vertex 3: 6
To vertex 4: 7
To vertex 5: 8
To vertex 6: 0

## Conclusion
This program has been able to implement Dijkstra Algorithm through adjacency matrix. It really computes shortest paths from a specified source to all the other vertices and thus it has many practical applications in navigating systems, routing and network optimization.

