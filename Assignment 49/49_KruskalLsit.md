# Kruskal’s Algorithm using Adjacency List

## Theory

A **graph** is a data structure consisting of vertices (nodes) and edges connecting them.  
A **Minimum Spanning Tree (MST)** of a connected, undirected, and weighted graph is a subset of edges that connects all vertices together with the **minimum possible total edge weight** and **without any cycles**.

**Kruskal’s Algorithm** is a **greedy algorithm** used to find the MST by always picking the smallest-weight edge that does not form a cycle.

---

## Objectives

1. To represent a user-defined weighted graph using an **Adjacency List**.  
2. To implement **Kruskal’s Algorithm** to find the **Minimum Spanning Tree (MST)**.  
3. To display the edges included in the MST and the **total minimum cost**.

---

## Algorithm

### Kruskal’s Algorithm

1. Start.
2. Create an adjacency list for the graph.
3. Store all edges along with their weights in a list or vector.
4. Sort all edges in **non-decreasing order of weights**.
5. Initialize a **Disjoint Set (Union-Find)** to keep track of connected components.
6. Iterate through sorted edges:
   - If the edge connects two **different sets**, include it in the MST.
   - Otherwise, discard it (to avoid cycles).
7. Repeat until MST contains `(V - 1)` edges.
8. Display the MST edges and their total cost.

---

## Source Code

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Graph_gsk {
    int V_gsk;
    vector<pair<int, pair<int, int>>> edges_gsk; // {weight, {u, v}}

public:
    Graph_gsk(int vertices_gsk) {
        V_gsk = vertices_gsk;
    }

    void addEdge_gsk(int u_gsk, int v_gsk, int w_gsk) {
        edges_gsk.push_back({w_gsk, {u_gsk, v_gsk}});
    }

    int findParent_gsk(int node_gsk, vector<int> &parent_gsk) {
        if (parent_gsk[node_gsk] == node_gsk)
            return node_gsk;
        return parent_gsk[node_gsk] = findParent_gsk(parent_gsk[node_gsk], parent_gsk);
    }

    void unionSet_gsk(int u_gsk, int v_gsk, vector<int> &parent_gsk, vector<int> &rank_gsk) {
        int rootU_gsk = findParent_gsk(u_gsk, parent_gsk);
        int rootV_gsk = findParent_gsk(v_gsk, parent_gsk);

        if (rootU_gsk != rootV_gsk) {
            if (rank_gsk[rootU_gsk] < rank_gsk[rootV_gsk])
                parent_gsk[rootU_gsk] = rootV_gsk;
            else if (rank_gsk[rootV_gsk] < rank_gsk[rootU_gsk])
                parent_gsk[rootV_gsk] = rootU_gsk;
            else {
                parent_gsk[rootV_gsk] = rootU_gsk;
                rank_gsk[rootU_gsk]++;
            }
        }
    }

    void kruskalMST_gsk() {
        sort(edges_gsk.begin(), edges_gsk.end());
        vector<int> parent_gsk(V_gsk), rank_gsk(V_gsk, 0);

        for (int i = 0; i < V_gsk; i++)
            parent_gsk[i] = i;

        int totalWeight_gsk = 0;

        cout << "\nEdges in the Minimum Spanning Tree:\n";
        for (auto edge : edges_gsk) {
            int weight_gsk = edge.first;
            int u_gsk = edge.second.first;
            int v_gsk = edge.second.second;

            int rootU_gsk = findParent_gsk(u_gsk, parent_gsk);
            int rootV_gsk = findParent_gsk(v_gsk, parent_gsk);

            if (rootU_gsk != rootV_gsk) {
                cout << u_gsk << " - " << v_gsk << " : " << weight_gsk << endl;
                totalWeight_gsk += weight_gsk;
                unionSet_gsk(rootU_gsk, rootV_gsk, parent_gsk, rank_gsk);
            }
        }

        cout << "\nTotal Minimum Cost of Spanning Tree = " << totalWeight_gsk << endl;
    }
};

int main() {
    int vertices_gsk, edges_gsk;
    cout << "Enter number of vertices: ";
    cin >> vertices_gsk;

    Graph_gsk g_gsk(vertices_gsk);

    cout << "Enter number of edges: ";
    cin >> edges_gsk;

    cout << "Enter edges (u v w):\n";
    for (int i = 0; i < edges_gsk; i++) {
        int u_gsk, v_gsk, w_gsk;
        cin >> u_gsk >> v_gsk >> w_gsk;
        g_gsk.addEdge_gsk(u_gsk, v_gsk, w_gsk);
    }

    g_gsk.kruskalMST_gsk();

    return 0;
}
```
---

## Sample Output

```
Enter number of vertices: 5
Enter number of edges: 7
Enter edges (u v w):
0 1 10
0 2 6
0 3 5
1 3 15
2 3 4
1 4 7
3 4 9

Edges in the Minimum Spanning Tree:
2 - 3 : 4
0 - 3 : 5
1 - 4 : 7
0 - 1 : 10

Total Minimum Cost of Spanning Tree = 26
```