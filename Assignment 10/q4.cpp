// Q4. Kruskal’s MST Algorithm
#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, w;
    bool operator<(const Edge& other) const {
        return w < other.w;
    }
};

struct DSU {
    vector<int> parent, rank;
    DSU(int n) {
        parent.resize(n);
        rank.assign(n, 0);
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int x) {
        return (parent[x] == x) ? x : parent[x] = find(parent[x]);
    }
    bool unite(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) return false;
        if (rank[a] < rank[b]) swap(a, b);
        parent[b] = a;
        if (rank[a] == rank[b]) rank[a]++;
        return true;
    }
};

int main() {
    int n = 4; // vertices
    vector<Edge> edges = {
        {0,1,10}, {0,2,6}, {0,3,5}, {1,3,15}, {2,3,4}
    };

    sort(edges.begin(), edges.end());
    DSU dsu(n);

    int totalWeight = 0;
    cout << "Edges in MST:\n";
    for (auto &e : edges) {
        if (dsu.unite(e.u, e.v)) {
            cout << e.u << " - " << e.v << " : " << e.w << "\n";
            totalWeight += e.w;
        }
    }
    cout << "Total weight: " << totalWeight << "\n";
    return 0;
}
