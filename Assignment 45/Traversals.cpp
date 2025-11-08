#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph_gsk {
    int V_gsk;
    vector<vector<int>> adj_gsk; // Adjacency list

public:
    Graph_gsk(int vertices_gsk) {
        V_gsk = vertices_gsk;
        adj_gsk.resize(V_gsk);
    }

    void addEdge_gsk(int u_gsk, int v_gsk) {
        adj_gsk[u_gsk].push_back(v_gsk);
        adj_gsk[v_gsk].push_back(u_gsk); // Undirected graph
    }

    void BFS_gsk(int start_gsk) {
        vector<bool> visited_gsk(V_gsk, false);
        queue<int> q_gsk;

        visited_gsk[start_gsk] = true;
        q_gsk.push(start_gsk);

        cout << "\nBFS Traversal starting from vertex " << start_gsk << ": ";

        while (!q_gsk.empty()) {
            int u_gsk = q_gsk.front();
            q_gsk.pop();
            cout << u_gsk << " ";

            for (int v_gsk : adj_gsk[u_gsk]) {
                if (!visited_gsk[v_gsk]) {
                    visited_gsk[v_gsk] = true;
                    q_gsk.push(v_gsk);
                }
            }
        }
        cout << endl;
    }

    void DFSUtil_gsk(int v_gsk, vector<bool>& visited_gsk) {
        visited_gsk[v_gsk] = true;
        cout << v_gsk << " ";

        for (int u_gsk : adj_gsk[v_gsk]) {
            if (!visited_gsk[u_gsk]) {
                DFSUtil_gsk(u_gsk, visited_gsk);
            }
        }
    }

    void DFS_gsk(int start_gsk) {
        vector<bool> visited_gsk(V_gsk, false);
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

    cout << "Enter edges (u v):\n";
    for (int i = 0; i < edges_gsk; i++) {
        int u_gsk, v_gsk;
        cin >> u_gsk >> v_gsk;
        g_gsk.addEdge_gsk(u_gsk, v_gsk);
    }

    int start_gsk;
    cout << "Enter starting vertex for traversals: ";
    cin >> start_gsk;

    g_gsk.BFS_gsk(start_gsk);
    g_gsk.DFS_gsk(start_gsk);

    return 0;
}
