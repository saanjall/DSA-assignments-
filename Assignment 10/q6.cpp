// Q6. Dijkstra’s Shortest Path Algorithm
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 5;
    vector<vector<pair<int,int>>> adj(n);

    auto addEdge = [&](int u, int v, int w){
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    };

    addEdge(0,1,10);
    addEdge(0,4,5);
    addEdge(1,2,1);
    addEdge(4,1,3);
    addEdge(4,2,9);
    addEdge(4,3,2);
    addEdge(2,3,4);

    int src = 0;
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    pq.push({0, src});

    while(!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();
        if (d > dist[u]) continue;
        for (auto [v, w] : adj[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    cout << "Shortest distances from " << src << ":\n";
    for (int i = 0; i < n; i++)
        cout << i << " : " << dist[i] << "\n";

    return 0;
}
