// Q1. Graph representation using adjacency matrix & list
#include <bits/stdc++.h>
using namespace std;

class Graph {
    int n;
    vector<vector<int>> adjMat;
    vector<vector<int>> adjList;
    bool directed;
public:
    Graph(int n, bool directed=false) {
        this->n = n;
        this->directed = directed;
        adjMat.assign(n, vector<int>(n, 0));
        adjList.assign(n, {});
    }

    void addEdge(int u, int v) {
        adjMat[u][v] = 1;
        adjList[u].push_back(v);
        if (!directed) {
            adjMat[v][u] = 1;
            adjList[v].push_back(u);
        }
    }

    void displayAdjMatrix() {
        cout << "\nAdjacency Matrix:\n";
        for (auto &row : adjMat) {
            for (int val : row) cout << val << " ";
            cout << "\n";
        }
    }

    void displayAdjList() {
        cout << "\nAdjacency List:\n";
        for (int i = 0; i < n; i++) {
            cout << i << " -> ";
            for (int v : adjList[i]) cout << v << " ";
            cout << "\n";
        }
    }

    int degree(int v) {
        return adjList[v].size();
    }

    vector<int> adjacentVertices(int v) {
        return adjList[v];
    }

    int countEdges() {
        int edges = 0;
        for (int i = 0; i < n; i++)
            edges += adjList[i].size();
        if (!directed) edges /= 2;
        return edges;
    }
};

int main() {
    Graph g(5, false);
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    g.displayAdjMatrix();
    g.displayAdjList();

    cout << "\nDegree of vertex 1: " << g.degree(1);
    cout << "\nAdjacent vertices of 1: ";
    for (int v : g.adjacentVertices(1)) cout << v << " ";
    cout << "\nNumber of edges: " << g.countEdges() << "\n";
    return 0;
}
