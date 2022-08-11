// An adjacency list represents a graph as an array of linked lists.
// The index of the array represents a vertex and each element in its linked list represents the other vertices
// that form an edge with the vertex.

#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int n;
    vector<list<int>> adj;

public:
    Graph(int n);
    void addEdge(int u, int v);
    void printGraph();
};

// Constructor for graph
Graph::Graph(int n)
{
    this->n = n;
    adj.resize(n);
}

// Add edge to graph
void Graph::addEdge(int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

// Print the graph
void Graph::printGraph()
{
    for (int d = 0; d < n; ++d)
    {
        cout << "\n Vertex "
             << d << ":";
        for (auto x : adj[d])
            cout << "-> " << x;
        printf("\n");
    }
}

int main()
{
    int n = 4;
    class Graph graph(n);

    // Add edges
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(0, 3);
    graph.addEdge(1, 2);

    graph.printGraph();
}