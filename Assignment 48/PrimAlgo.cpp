#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

class Graph_gsk {
    int V_gsk;
    vector<vector<pair<int, int>>> adj_gsk; // vertex -> (neighbor, weight)

public:
    Graph_gsk(int vertices_gsk) {
        V_gsk = vertices_gsk;
        adj_gsk.resize(V_gsk);
    }

    void addEdge_gsk(int u_gsk, int v_gsk, int w_gsk) {
        adj_gsk[u_gsk].push_back(make_pair(v_gsk, w_gsk));
        adj_gsk[v_gsk].push_back(make_pair(u_gsk, w_gsk)); // Undirected graph
    }

    void primMST_gsk() {
        vector<int> key_gsk(V_gsk, 1e9);  // Cost to reach each vertex
        vector<int> parent_gsk(V_gsk, -1);
        vector<bool> inMST_gsk(V_gsk, false);

        key_gsk[0] = 0; // Start from vertex 0
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq_gsk;
        pq_gsk.push(make_pair(0, 0)); // (weight, vertex)

        while (!pq_gsk.empty()) {
            int u_gsk = pq_gsk.top().second;
            pq_gsk.pop();

            if (inMST_gsk[u_gsk])
                continue;

            inMST_gsk[u_gsk] = true;

            for (size_t i = 0; i < adj_gsk[u_gsk].size(); i++) {
                int v_gsk = adj_gsk[u_gsk][i].first;
                int w_gsk = adj_gsk[u_gsk][i].second;

                if (!inMST_gsk[v_gsk] && w_gsk < key_gsk[v_gsk]) {
                    key_gsk[v_gsk] = w_gsk;
                    pq_gsk.push(make_pair(key_gsk[v_gsk], v_gsk));
                    parent_gsk[v_gsk] = u_gsk;
                }
            }
        }

        cout << "\nEdges in Minimum Spanning Tree:\n";
        int totalWeight_gsk = 0;
        for (int i = 1; i < V_gsk; i++) {
            cout << parent_gsk[i] << " - " << i << " : " << key_gsk[i] << endl;
            totalWeight_gsk += key_gsk[i];
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

    g_gsk.primMST_gsk();

    return 0;
}
