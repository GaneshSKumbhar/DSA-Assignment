#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge_gsk {
    int src_gsk, dest_gsk, weight_gsk;
};

class Graph_gsk {
    int V_gsk;
    vector<Edge_gsk> edges_gsk;

public:
    Graph_gsk(int vertices_gsk) {
        V_gsk = vertices_gsk;
    }

    void addEdge_gsk(int u_gsk, int v_gsk, int w_gsk) {
        edges_gsk.push_back({u_gsk, v_gsk, w_gsk});
    }

    int findParent_gsk(int vertex_gsk, vector<int>& parent_gsk) { // Pass parent_gsk by reference
        if (parent_gsk[vertex_gsk] == vertex_gsk)
            return vertex_gsk;
        return parent_gsk[vertex_gsk] = findParent_gsk(parent_gsk[vertex_gsk], parent_gsk); // Corrected recursive call
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

    void kruskalMST_gsk() {
        sort(edges_gsk.begin(), edges_gsk.end(), [](Edge_gsk a, Edge_gsk b) {
            return a.weight_gsk < b.weight_gsk;
        });

        vector<int> parent_gsk(V_gsk);
        vector<int> rank_gsk(V_gsk, 0);
        for (int i = 0; i < V_gsk; i++)
            parent_gsk[i] = i;

        vector<Edge_gsk> result_gsk;
        int totalWeight_gsk = 0;

        for (auto edge_gsk : edges_gsk) {
            int rootU_gsk = findParent_gsk(edge_gsk.src_gsk, parent_gsk);
            int rootV_gsk = findParent_gsk(edge_gsk.dest_gsk, parent_gsk);

            if (rootU_gsk != rootV_gsk) {
                result_gsk.push_back(edge_gsk);
                totalWeight_gsk += edge_gsk.weight_gsk;
                unionSets_gsk(rootU_gsk, rootV_gsk, parent_gsk, rank_gsk);
            }
        }

        cout << "\nEdges in the Minimum Spanning Tree (MST):\n";
        for (auto edge_gsk : result_gsk)
            cout << edge_gsk.src_gsk + 1 << " - " << edge_gsk.dest_gsk + 1 << "  (Weight: " << edge_gsk.weight_gsk << ")\n";

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
        g_gsk.addEdge_gsk(u_gsk - 1, v_gsk - 1, w_gsk);
    }

    g_gsk.kruskalMST_gsk();
    return 0;
}