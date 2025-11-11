// Q2. Breadth First Search (BFS)
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

    void BFS(int start) {
        vector<bool> visited(n, false);
        queue<int> q;
        visited[start] = true;
        q.push(start);

        cout << "BFS starting from " << start << ": ";
        while (!q.empty()) {
            int node = q.front(); q.pop();
            cout << node << " ";
            for (int v : adj[node])
                if (!visited[v]) {
                    visited[v] = true;
                    q.push(v);
                }
        }
        cout << "\n";
    }
};

int main() {
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.BFS(0);
    return 0;
}
