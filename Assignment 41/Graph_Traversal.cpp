#include <iostream>
#include <queue>
using namespace std;

#define MAX 20

class Graph_gsk {
    int adjMatrix_gsk[MAX][MAX];
    int numVertices_gsk;

public:
    Graph_gsk(int vertices_gsk) {
        numVertices_gsk = vertices_gsk;
        for (int i = 0; i < numVertices_gsk; i++)
            for (int j = 0; j < numVertices_gsk; j++)
                adjMatrix_gsk[i][j] = 0;
    }

    void addEdge_gsk(int u_gsk, int v_gsk) {
        adjMatrix_gsk[u_gsk][v_gsk] = 1;
        adjMatrix_gsk[v_gsk][u_gsk] = 1; // For undirected graph
    }

    void displayMatrix_gsk() {
        cout << "\nAdjacency Matrix:\n";
        for (int i = 0; i < numVertices_gsk; i++) {
            for (int j = 0; j < numVertices_gsk; j++)
                cout << adjMatrix_gsk[i][j] << " ";
            cout << endl;
        }
    }

    void BFS_gsk(int start_gsk) {
        bool visited_gsk[MAX] = {false};
        queue<int> q_gsk;

        visited_gsk[start_gsk] = true;
        q_gsk.push(start_gsk);

        cout << "\nBFS Traversal starting from vertex " << start_gsk << ": ";

        while (!q_gsk.empty()) {
            int u_gsk = q_gsk.front();
            q_gsk.pop();
            cout << u_gsk << " ";

            for (int v_gsk = 0; v_gsk < numVertices_gsk; v_gsk++) {
                if (adjMatrix_gsk[u_gsk][v_gsk] == 1 && !visited_gsk[v_gsk]) {
                    visited_gsk[v_gsk] = true;
                    q_gsk.push(v_gsk);
                }
            }
        }
        cout << endl;
    }

    void DFSUtil_gsk(int vertex_gsk, bool visited_gsk[]) {
        visited_gsk[vertex_gsk] = true;
        cout << vertex_gsk << " ";

        for (int v_gsk = 0; v_gsk < numVertices_gsk; v_gsk++) {
            if (adjMatrix_gsk[vertex_gsk][v_gsk] == 1 && !visited_gsk[v_gsk]) {
                DFSUtil_gsk(v_gsk, visited_gsk);
            }
        }
    }

    void DFS_gsk(int start_gsk) {
        bool visited_gsk[MAX] = {false};
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

    cout << "Enter edges (u v): \n";
    for (int i = 0; i < edges_gsk; i++) {
        int u_gsk, v_gsk;
        cin >> u_gsk >> v_gsk;
        g_gsk.addEdge_gsk(u_gsk, v_gsk);
    }

    g_gsk.displayMatrix_gsk();

    int start_gsk;
    cout << "\nEnter starting vertex for BFS and DFS: ";
    cin >> start_gsk;

    g_gsk.BFS_gsk(start_gsk);
    g_gsk.DFS_gsk(start_gsk);

    return 0;
}   