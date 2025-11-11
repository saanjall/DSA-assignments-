// Q5. Prim’s MST Algorithm
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 5;
    vector<vector<pair<int, int>>> adj(n);

    auto addEdge = [&](int u, int v, int w){
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    };

    addEdge(0,1,2);
    addEdge(0,3,6);
    addEdge(1,2,3);
    addEdge(1,3,8);
    addEdge(1,4,5);
    addEdge(2,4,7);
    addEdge(3,4,9);

    vector<int> key(n, INT_MAX);
    vector<bool> inMST(n, false);
    vector<int> parent(n, -1);
    key[0] = 0;

    for (int count = 0; count < n - 1; count++) {
        int u = -1;
        for (int i = 0; i < n; i++)
            if (!inMST[i] && (u == -1 || key[i] < key[u]))
                u = i;

        inMST[u] = true;
        for (auto [v, w] : adj[u])
            if (!inMST[v] && w < key[v]) {
                key[v] = w;
                parent[v] = u;
            }
    }

    cout << "Edges in MST:\n";
    int total = 0;
    for (int i = 1; i < n; i++) {
        cout << parent[i] << " - " << i << " : " << key[i] << "\n";
        total += key[i];
    }
    cout << "Total weight: " << total << "\n";
    return 0;
}
