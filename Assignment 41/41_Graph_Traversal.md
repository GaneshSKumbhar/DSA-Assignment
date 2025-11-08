# Graph Representation and Traversals (BFS & DFS)

## Theory

A **Graph** is a non-linear data structure that represents relationships between entities (called **vertices**) using **edges**.  
Graphs can be represented using:
- **Adjacency Matrix**
- **Adjacency List**

### **Adjacency Matrix**
An **Adjacency Matrix** is a 2D array of size `V × V`, where `V` is the number of vertices.
- If there is an edge between vertex `i` and `j`, `matrix[i][j] = 1`
- Otherwise, `matrix[i][j] = 0`

### **Graph Traversals**
Two common ways to traverse a graph are:
1. **Breadth-First Search (BFS)**  
   - Explores all the neighboring nodes first before moving to the next level.
   - Implemented using a **queue**.
2. **Depth-First Search (DFS)**  
   - Explores as far as possible along each branch before backtracking.
   - Implemented using **recursion** or a **stack**.

---


## Algorithm

### **1. Graph Representation**
1. Input the number of vertices `V`.
2. Create a `V × V` adjacency matrix initialized with zeros.
3. Input the connections (edges) between vertices and update the matrix with `1`.

### **2. BFS Traversal**
1. Start from a source vertex.
2. Mark it as **visited** and enqueue it.
3. While the queue is not empty:
   - Dequeue a vertex `u`.
   - Visit all unvisited adjacent vertices of `u`.
   - Mark them visited and enqueue them.

### **3. DFS Traversal**
1. Start from a source vertex.
2. Mark it as **visited**.
3. Recursively visit all unvisited adjacent vertices.

---

## Source Code

```cpp
#include <iostream>
#include <queue>
using namespace std;

#define MAX 20

class Graph_gsk {
    int adjMatrix_gsk[MAX][MAX];
    int numVertices_gsk;

public:
    Graph_gsk(int vertices_gsk) {
        numVertices_gsk = vertices_gsk;
        for (int i = 0; i < numVertices_gsk; i++)
            for (int j = 0; j < numVertices_gsk; j++)
                adjMatrix_gsk[i][j] = 0;
    }

    void addEdge_gsk(int u_gsk, int v_gsk) {
        adjMatrix_gsk[u_gsk][v_gsk] = 1;
        adjMatrix_gsk[v_gsk][u_gsk] = 1; // For undirected graph
    }

    void displayMatrix_gsk() {
        cout << "\nAdjacency Matrix:\n";
        for (int i = 0; i < numVertices_gsk; i++) {
            for (int j = 0; j < numVertices_gsk; j++)
                cout << adjMatrix_gsk[i][j] << " ";
            cout << endl;
        }
    }

    void BFS_gsk(int start_gsk) {
        bool visited_gsk[MAX] = {false};
        queue<int> q_gsk;

        visited_gsk[start_gsk] = true;
        q_gsk.push(start_gsk);

        cout << "\nBFS Traversal starting from vertex " << start_gsk << ": ";

        while (!q_gsk.empty()) {
            int u_gsk = q_gsk.front();
            q_gsk.pop();
            cout << u_gsk << " ";

            for (int v_gsk = 0; v_gsk < numVertices_gsk; v_gsk++) {
                if (adjMatrix_gsk[u_gsk][v_gsk] == 1 && !visited_gsk[v_gsk]) {
                    visited_gsk[v_gsk] = true;
                    q_gsk.push(v_gsk);
                }
            }
        }
        cout << endl;
    }

    void DFSUtil_gsk(int vertex_gsk, bool visited_gsk[]) {
        visited_gsk[vertex_gsk] = true;
        cout << vertex_gsk << " ";

        for (int v_gsk = 0; v_gsk < numVertices_gsk; v_gsk++) {
            if (adjMatrix_gsk[vertex_gsk][v_gsk] == 1 && !visited_gsk[v_gsk]) {
                DFSUtil_gsk(v_gsk, visited_gsk);
            }
        }
    }

    void DFS_gsk(int start_gsk) {
        bool visited_gsk[MAX] = {false};
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

    cout << "Enter edges (u v): \n";
    for (int i = 0; i < edges_gsk; i++) {
        int u_gsk, v_gsk;
        cin >> u_gsk >> v_gsk;
        g_gsk.addEdge_gsk(u_gsk, v_gsk);
    }

    g_gsk.displayMatrix_gsk();

    int start_gsk;
    cout << "\nEnter starting vertex for BFS and DFS: ";
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
2 3
3 4

Adjacency Matrix:
0 1 1 0 0
1 0 0 1 1
1 0 0 1 0
0 1 1 0 1
0 1 0 1 0

Enter starting vertex for BFS and DFS: 0

BFS Traversal starting from vertex 0: 0 1 2 3 4
DFS Traversal starting from vertex 0: 0 1 3 2 4
```
