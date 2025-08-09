# Question 5: Implement the Undirected Graph using Adjacency Matrix
An undirected graph is just a set of points (called vertices) connected by lines (called edges) where the connection works both ways.

## (a) Data structure defination
We are working with an undirected graph, so if we have an edge from one node to another, it is also in the reverse direction.

To keep this graph, we keep it in an Adjacency Matrix. This is a 2D array (a table) where:
The columns and rows are the nodes.
If two nodes are connected, we put 1 in that cell.
If they are not connected, we put 0.
As the graph is undirected, the matrix is symmetric (top-right and bottom-left are the same).

Example for 4 vertices:
0 1 2 3
0 0 1 1 0
1 1 0 1 1
2 1 1 0 1
3 0 1 1 0
In this example, vertex 0 has edge to vertex 1 and 2, and so on.

## (b) Description of the Functions Implemented
1. addEdge(int u, int v)
Purpose: Adds an undirected edge between vertices u and v.
Implementation: Makes adjMatrix[u][v]=adjMatrix[v][u]=1.

2. BFS(int start, int vertices)
Purpose:Carries out the Breadth-First Search with a defined initial vertex.
Explores the vertices using a queue level by level.
Visit of nodes was done by Marks to avoid infinite loops.

3. DFS(int start, int vertices)
Purpose: This algorithm implements Depth-First Search of a graph beginning on a specified vertex.
Backtracks but searches down every branch as far as it can go.

4. DFS_Recursive(int vertex, int vertices)
It is a helper function for DFS that handles the recursive traversal.

## (c) An Overview of How the main() Method Is Organized
Number of vertices is given.
Adjacency matrix is set to 0.
Adding Edges
Call addEdge() for each pair of adjacent vertices based on the example graph.
Display Graph
Print adjacency matrix for verifying the graph structure.
Graph Traversal
Call BFS() from vertex 0.
Call DFS() from vertex 0.

## (d) Demonstration with Example Graph
   0
  / \
 1   2
 | \  
 3  4

## (e) Output of a Complete Run of the Program
Adjacency Matrix:
0 1 1 0 0
1 0 0 1 1
1 0 0 0 1
0 1 0 0 0
0 1 1 0 0
BFS Traversal: 0 1 2 3 4
DFS Traversal: 0 1 3 4 2

## Conclusion
This algorithm shows that the undirected graph can be implemented through the adjacency matrix that is easy technique to determine whether a pair of vertices are adjacent. BFS traverses the graph in levels with the help of a queue whereas, DFS explores in depth with the help of recursion.The example illustrates both Directions of traversing the given graph and through this difference between BFS and DFS will be comprehended.