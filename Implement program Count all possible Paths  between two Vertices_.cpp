#include <iostream>
#include <vector>
using namespace std;

class Graph {
    int V; // Number of vertices
    vector<vector<int>> adj; // Adjacency list
    int countPathsUtil(int u, int d, vector<bool> &visited);

public:
    Graph(int V);
    void addEdge(int u, int v);
    int countPaths(int s, int d);
};

Graph::Graph(int V) {
    this->V = V;
    adj.resize(V);
}

void Graph::addEdge(int u, int v) {
    adj[u].push_back(v);
}

int Graph::countPathsUtil(int u, int d, vector<bool> &visited) {
    if (u == d) return 1;

    visited[u] = true;
    int count = 0;

    for (int v : adj[u]) {
        if (!visited[v]) {
            count += countPathsUtil(v, d, visited);
        }
    }

    visited[u] = false; // Backtrack
    return count;
}

int Graph::countPaths(int s, int d) {
    vector<bool> visited(V, false);
    return countPathsUtil(s, d, visited);
}

int main() {
    Graph g(5); // 5 vertices: A, B, C, D, E (0 to 4)
    g.addEdge(0, 1); // A -> B
    g.addEdge(0, 2); // A -> C
    g.addEdge(0, 3); // A -> D
    g.addEdge(1, 3); // B -> D
    g.addEdge(1, 4); // B -> E
    g.addEdge(2, 4); // C -> E
    g.addEdge(3, 4); // D -> E

    cout << "Total paths between A and E: " << g.countPaths(0, 4) << endl;
    cout << "Total paths between A and C: " << g.countPaths(0, 2) << endl;

    return 0;
}
