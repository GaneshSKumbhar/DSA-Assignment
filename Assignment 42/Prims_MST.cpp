#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

typedef pair<int, int> Pair_gsk; // (weight, vertex)

class Graph_gsk {
    int V_gsk;
    vector<vector<Pair_gsk>> adj_gsk; // Adjacency list

public:
    Graph_gsk(int vertices_gsk) {
        V_gsk = vertices_gsk;
        adj_gsk.resize(V_gsk);
    }

    void addEdge_gsk(int u_gsk, int v_gsk, int w_gsk) {
        adj_gsk[u_gsk].push_back({w_gsk, v_gsk});
        adj_gsk[v_gsk].push_back({w_gsk, u_gsk}); // Undirected graph
    }

    void primMST_gsk() {
        vector<int> key_gsk(V_gsk, INT_MAX);
        vector<int> parent_gsk(V_gsk, -1);
        vector<bool> inMST_gsk(V_gsk, false);

        priority_queue<Pair_gsk, vector<Pair_gsk>, greater<Pair_gsk>> pq_gsk;

        int start_gsk = 0;
        key_gsk[start_gsk] = 0;
        pq_gsk.push({0, start_gsk});

        while (!pq_gsk.empty()) {
            int u_gsk = pq_gsk.top().second;
            pq_gsk.pop();

            if (inMST_gsk[u_gsk])
                continue;

            inMST_gsk[u_gsk] = true;

            // ✅ Fixed: Replaced structured binding with pair access
            for (auto edge_gsk : adj_gsk[u_gsk]) {
                int weight_gsk = edge_gsk.first;
                int v_gsk = edge_gsk.second;

                if (!inMST_gsk[v_gsk] && weight_gsk < key_gsk[v_gsk]) {
                    key_gsk[v_gsk] = weight_gsk;
                    pq_gsk.push({key_gsk[v_gsk], v_gsk});
                    parent_gsk[v_gsk] = u_gsk;
                }
            }
        }

        cout << "\nEdges in the Minimum Spanning Tree (MST):\n";
        int totalWeight_gsk = 0;
        for (int i = 1; i < V_gsk; i++) {
            if (parent_gsk[i] == -1) {
                cout << "Vertex " << i << " is not reachable from the start vertex.\n";
                continue;
            }
            cout << parent_gsk[i] << " - " << i << "  (Weight: " << key_gsk[i] << ")\n";
            totalWeight_gsk += key_gsk[i];
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

    g_gsk.primMST_gsk();
    return 0;
}
