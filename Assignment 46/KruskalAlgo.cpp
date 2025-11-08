#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Graph_gsk {
    int V_gsk;
    vector<vector<int>> adj_gsk;

    int findParent_gsk(int vertex_gsk, vector<int>& parent_gsk) {
        if (parent_gsk[vertex_gsk] != vertex_gsk)
            parent_gsk[vertex_gsk] = findParent_gsk(parent_gsk[vertex_gsk], parent_gsk);
        return parent_gsk[vertex_gsk];
    }

    void unionSets_gsk(int u_gsk, int v_gsk, vector<int>& parent_gsk, vector<int>& rank_gsk) {
        int rootU_gsk = findParent_gsk(u_gsk, parent_gsk);
        int rootV_gsk = findParent_gsk(v_gsk, parent_gsk);

        if (rootU_gsk != rootV_gsk) {
            if (rank_gsk[rootU_gsk] < rank_gsk[rootV_gsk])
                parent_gsk[rootU_gsk] = rootV_gsk;
            else if (rank_gsk[rootU_gsk] > rank_gsk[rootV_gsk])
                parent_gsk[rootV_gsk] = rootU_gsk;
            else {
                parent_gsk[rootV_gsk] = rootU_gsk;
                rank_gsk[rootU_gsk]++;
            }
        }
    }

public:
    Graph_gsk(int vertices_gsk) {
        V_gsk = vertices_gsk;
        adj_gsk.resize(V_gsk, vector<int>(V_gsk, 0));
    }

    void addEdge_gsk(int u_gsk, int v_gsk, int w_gsk) {
        adj_gsk[u_gsk][v_gsk] = w_gsk;
        adj_gsk[v_gsk][u_gsk] = w_gsk; // Undirected graph
    }

    void kruskalMST_gsk() {
        vector<pair<int, pair<int, int>>> edges_gsk;

        // Convert adjacency matrix to edge list
        for (int i = 0; i < V_gsk; i++) {
            for (int j = i + 1; j < V_gsk; j++) {
                if (adj_gsk[i][j] != 0)
                    edges_gsk.push_back({adj_gsk[i][j], {i, j}});
            }
        }

        sort(edges_gsk.begin(), edges_gsk.end());

        vector<int> parent_gsk(V_gsk), rank_gsk(V_gsk, 0);
        for (int i = 0; i < V_gsk; i++)
            parent_gsk[i] = i;

        cout << "\nEdges in the Minimum Spanning Tree (MST):\n";
        int totalWeight_gsk = 0;

        for (auto edge_gsk : edges_gsk) {
            int weight_gsk = edge_gsk.first;
            int u_gsk = edge_gsk.second.first;
            int v_gsk = edge_gsk.second.second;

            int rootU_gsk = findParent_gsk(u_gsk, parent_gsk);
            int rootV_gsk = findParent_gsk(v_gsk, parent_gsk);

            if (rootU_gsk != rootV_gsk) {
                cout << u_gsk << " - " << v_gsk << "  (Weight: " << weight_gsk << ")\n";
                totalWeight_gsk += weight_gsk;
                unionSets_gsk(rootU_gsk, rootV_gsk, parent_gsk, rank_gsk);
            }
        }

        cout << "Total Minimum Cost of MST: " << totalWeight_gsk << endl;
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