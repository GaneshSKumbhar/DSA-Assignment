# Graph Representation using Adjacency List with BFS and DFS Traversals

## Theory

A **Graph** is a collection of vertices (nodes) connected by edges.  
It can be:
- **Directed** or **Undirected**
- **Weighted** or **Unweighted**

To store graphs efficiently, we often use an **Adjacency List**, where each vertex maintains a list of its connected vertices.  
This structure uses less memory compared to an adjacency matrix, especially for sparse graphs.

Two major graph traversal algorithms are used here:
- **Breadth-First Search (BFS):** Traverses level by level using a queue.
- **Depth-First Search (DFS):** Traverses as deep as possible using recursion or a stack.

---

## Objectives

1. Accept a graph from the user and represent it using an **Adjacency List**.  
2. Perform **Breadth-First Search (BFS)** traversal.  
3. Perform **Depth-First Search (DFS)** traversal.

---

## Algorithm

### BFS Algorithm
1. Start from the given source vertex.  
2. Mark the vertex as visited and enqueue it.  
3. While the queue is not empty:  
   - Dequeue a vertex.  
   - Visit all its unvisited adjacent vertices and enqueue them.

### DFS Algorithm
1. Start from the given source vertex.  
2. Mark the vertex as visited.  
3. Recursively visit all adjacent unvisited vertices.

---

## Source Code

```cpp
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph_gsk {
    int V_gsk;
    vector<vector<int>> adj_gsk; // Adjacency list

public:
    Graph_gsk(int vertices_gsk) {
        V_gsk = vertices_gsk;
        adj_gsk.resize(V_gsk);
    }

    void addEdge_gsk(int u_gsk, int v_gsk) {
        adj_gsk[u_gsk].push_back(v_gsk);
        adj_gsk[v_gsk].push_back(u_gsk); // Undirected graph
    }

    void BFS_gsk(int start_gsk) {
        vector<bool> visited_gsk(V_gsk, false);
        queue<int> q_gsk;

        visited_gsk[start_gsk] = true;
        q_gsk.push(start_gsk);

        cout << "\nBFS Traversal starting from vertex " << start_gsk << ": ";

        while (!q_gsk.empty()) {
            int u_gsk = q_gsk.front();
            q_gsk.pop();
            cout << u_gsk << " ";

            for (int v_gsk : adj_gsk[u_gsk]) {
                if (!visited_gsk[v_gsk]) {
                    visited_gsk[v_gsk] = true;
                    q_gsk.push(v_gsk);
                }
            }
        }
        cout << endl;
    }

    void DFSUtil_gsk(int v_gsk, vector<bool>& visited_gsk) {
        visited_gsk[v_gsk] = true;
        cout << v_gsk << " ";

        for (int u_gsk : adj_gsk[v_gsk]) {
            if (!visited_gsk[u_gsk]) {
                DFSUtil_gsk(u_gsk, visited_gsk);
            }
        }
    }

    void DFS_gsk(int start_gsk) {
        vector<bool> visited_gsk(V_gsk, false);
        cout << "\nDFS Traversal starting from vertex " << start_gsk << ": ";
        DFSUtil_gsk(start_gsk, visited_gsk);
        cout << endl;
    }
};

int main() {
    int vertices_gsk, edges_gsk;
    cout << "Enter number of vertices: ";
    cin >> vertices_gsk;

    Graph_gsk g_gsk(vertices_gsk);

    cout << "Enter number of edges: ";
    cin >> edges_gsk;

    cout << "Enter edges (u v):\n";
    for (int i = 0; i < edges_gsk; i++) {
        int u_gsk, v_gsk;
        cin >> u_gsk >> v_gsk;
        g_gsk.addEdge_gsk(u_gsk, v_gsk);
    }

    int start_gsk;
    cout << "Enter starting vertex for traversals: ";
    cin >> start_gsk;

    g_gsk.BFS_gsk(start_gsk);
    g_gsk.DFS_gsk(start_gsk);

    return 0;
}
```
---

## Sample Output

```
Enter number of vertices: 5
Enter number of edges: 6
Enter edges (u v):
0 1
0 2
1 3
1 4
2 4
3 4
Enter starting vertex for traversals: 0

BFS Traversal starting from vertex 0: 0 1 2 3 4
DFS Traversal starting from vertex 0: 0 1 3 4 2
```
