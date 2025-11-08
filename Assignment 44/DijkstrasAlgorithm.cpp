#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

typedef pair<int, int> Pair_gsk; // (distance, vertex)

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

    void dijkstra_gsk(int src_gsk, int dest_gsk) {
        vector<int> dist_gsk(V_gsk, INT_MAX);
        vector<int> parent_gsk(V_gsk, -1);
        priority_queue<Pair_gsk, vector<Pair_gsk>, greater<Pair_gsk>> pq_gsk;

        dist_gsk[src_gsk] = 0;
        pq_gsk.push({0, src_gsk});

        while (!pq_gsk.empty()) {
            int u_gsk = pq_gsk.top().second;
            int d_gsk = pq_gsk.top().first;
            pq_gsk.pop();

            if (d_gsk > dist_gsk[u_gsk])
                continue;

            for (auto edge_gsk : adj_gsk[u_gsk]) {
                int weight_gsk = edge_gsk.first;
                int v_gsk = edge_gsk.second;

                if (dist_gsk[u_gsk] + weight_gsk < dist_gsk[v_gsk]) {
                    dist_gsk[v_gsk] = dist_gsk[u_gsk] + weight_gsk;
                    parent_gsk[v_gsk] = u_gsk;
                    pq_gsk.push({dist_gsk[v_gsk], v_gsk});
                }
            }
        }

        cout << "\nShortest distance from " << src_gsk << " to " << dest_gsk << " is: " << dist_gsk[dest_gsk] << endl;

        cout << "Path: ";
        vector<int> path_gsk;
        for (int v = dest_gsk; v != -1; v = parent_gsk[v])
            path_gsk.push_back(v);

        for (int i = path_gsk.size() - 1; i >= 0; i--) {
            cout << path_gsk[i];
            if (i != 0) cout << " -> ";
        }
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

    cout << "Enter edges (u v w):\n";
    for (int i = 0; i < edges_gsk; i++) {
        int u_gsk, v_gsk, w_gsk;
        cin >> u_gsk >> v_gsk >> w_gsk;
        g_gsk.addEdge_gsk(u_gsk, v_gsk, w_gsk);
    }

    int src_gsk, dest_gsk;
    cout << "Enter source vertex: ";
    cin >> src_gsk;
    cout << "Enter destination vertex: ";
    cin >> dest_gsk;

    g_gsk.dijkstra_gsk(src_gsk, dest_gsk);
    return 0;
}