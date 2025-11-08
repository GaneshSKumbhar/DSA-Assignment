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