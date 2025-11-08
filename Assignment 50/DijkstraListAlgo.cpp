#include <iostream>
#include <vector>
#include <queue>
#include <climits>
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

    void dijkstra_gsk(int src_gsk) {
        vector<int> dist_gsk(V_gsk, INT_MAX);
        dist_gsk[src_gsk] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq_gsk;
        pq_gsk.push(make_pair(0, src_gsk)); // (distance, vertex)

        while (!pq_gsk.empty()) {
            int u_gsk = pq_gsk.top().second;
            int currDist_gsk = pq_gsk.top().first;
            pq_gsk.pop();

            if (currDist_gsk > dist_gsk[u_gsk])
                continue;

            for (size_t i = 0; i < adj_gsk[u_gsk].size(); i++) {
                int v_gsk = adj_gsk[u_gsk][i].first;
                int w_gsk = adj_gsk[u_gsk][i].second;

                if (dist_gsk[u_gsk] + w_gsk < dist_gsk[v_gsk]) {
                    dist_gsk[v_gsk] = dist_gsk[u_gsk] + w_gsk;
                    pq_gsk.push(make_pair(dist_gsk[v_gsk], v_gsk));
                }
            }
        }

        cout << "\nShortest distances from source vertex " << src_gsk << ":\n";
        for (int i = 0; i < V_gsk; i++) {
            cout << "Vertex " << i << " : ";
            if (dist_gsk[i] == INT_MAX)
                cout << "Unreachable\n";
            else
                cout << dist_gsk[i] << endl;
        }
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

    int src_gsk;
    cout << "Enter source vertex: ";
    cin >> src_gsk;

    g_gsk.dijkstra_gsk(src_gsk);

    return 0;
}
