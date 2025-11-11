// Q3. Depth First Search (DFS)
#include <bits/stdc++.h>
using namespace std;

class Graph {
    int n;
    vector<vector<int>> adj;
public:
    Graph(int n) { this->n = n; adj.assign(n, {}); }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void DFSUtil(int node, vector<bool>& visited) {
        visited[node] = true;
        cout << node << " ";
        for (int v : adj[node])
            if (!visited[v])
                DFSUtil(v, visited);
    }

    void DFS(int start) {
        vector<bool> visited(n, false);
        cout << "DFS starting from " << start << ": ";
        DFSUtil(start, visited);
        cout << "\n";
    }
};

int main() {
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.DFS(0);
    return 0;
}
