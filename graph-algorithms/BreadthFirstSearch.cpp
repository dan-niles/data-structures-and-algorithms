// Breadth-First Traversal (or Search) for a graph is similar to Breadth-First Traversal of a tree.
// The only catch here is, that, unlike trees, graphs may contain cycles, so we may come to the same node again.
// To avoid processing a node more than once, we use a boolean visited array.
// For simplicity, it is assumed that all vertices are reachable from the starting vertex.
// BFS uses a queue data structure for traversal.

#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int n; // No. of vertices
    vector<list<int>> adj;

public:
    Graph(int n);
    void addEdge(int v, int w);
    void BFS(int s);
};

Graph::Graph(int n)
{
    this->n = n;
    adj.resize(n);
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
}

void Graph::BFS(int s)
{
    // Mark all the vertices as not visited
    vector<bool> visited;
    visited.resize(n, false);

    // Create a queue for BFS
    list<int> queue;

    // Mark the current node as visited and enqueue it
    visited[s] = true;
    queue.push_back(s);

    while (!queue.empty())
    {
        // Dequeue a vertex from queue and print it
        s = queue.front();
        cout << s << " ";
        queue.pop_front();

        // Get all adjacent vertices of the dequeued
        // vertex s. If a adjacent has not been visited,
        // then mark it visited and enqueue it
        for (auto adjecent : adj[s])
        {
            if (!visited[adjecent])
            {
                visited[adjecent] = true;
                queue.push_back(adjecent);
            }
        }
    }
}

int main()
{
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "Breadth First Traversal (starting from vertex 2)" << endl;
    g.BFS(2);

    return 0;
}