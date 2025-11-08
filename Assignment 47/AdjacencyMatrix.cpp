#include <iostream>
#include <vector>
#include <climits>
using namespace std;

#define INF INT_MAX

class Graph_gsk {
    int V_gsk;
    vector<vector<int>> adj_gsk; // Adjacency matrix

public:
    Graph_gsk(int vertices_gsk) {
        V_gsk = vertices_gsk;
        adj_gsk.resize(V_gsk, vector<int>(V_gsk, 0));
    }

    void addEdge_gsk(int u_gsk, int v_gsk, int w_gsk) {
        adj_gsk[u_gsk][v_gsk] = w_gsk;
        adj_gsk[v_gsk][u_gsk] = w_gsk; // Undirected graph
    }

    int minDistance_gsk(vector<int>& dist_gsk, vector<bool>& visited_gsk) {
        int min_gsk = INF, minIndex_gsk = -1;
        for (int v_gsk = 0; v_gsk < V_gsk; v_gsk++) {
            if (!visited_gsk[v_gsk] && dist_gsk[v_gsk] <= min_gsk) {
                min_gsk = dist_gsk[v_gsk];
                minIndex_gsk = v_gsk;
            }
        }
        return minIndex_gsk;
    }

    void dijkstra_gsk(int src_gsk) {
        vector<int> dist_gsk(V_gsk, INF);
        vector<bool> visited_gsk(V_gsk, false);

        dist_gsk[src_gsk] = 0;

        for (int count_gsk = 0; count_gsk < V_gsk - 1; count_gsk++) {
            int u_gsk = minDistance_gsk(dist_gsk, visited_gsk);
            if (u_gsk == -1) break; // No reachable vertex left
            visited_gsk[u_gsk] = true;

            for (int v_gsk = 0; v_gsk < V_gsk; v_gsk++) {
                if (!visited_gsk[v_gsk] && adj_gsk[u_gsk][v_gsk] &&
                    dist_gsk[u_gsk] != INF &&
                    dist_gsk[u_gsk] + adj_gsk[u_gsk][v_gsk] < dist_gsk[v_gsk]) {
                    dist_gsk[v_gsk] = dist_gsk[u_gsk] + adj_gsk[u_gsk][v_gsk];
                }
            }
        }

        cout << "\nShortest distances from source vertex " << src_gsk << ":\n";
        for (int i = 0; i < V_gsk; i++) {
            cout << "Vertex " << i << " : ";
            if (dist_gsk[i] == INF)
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
