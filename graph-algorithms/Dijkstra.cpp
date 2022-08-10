#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int u, v, w; // Start vertex, End vertex, Weight of edge
};

struct Graph
{
    int V, E;          // No of vertices, edges
    struct Edge *edge; // Array of edges
};

// Create new graph with V vertices and E edges
struct Graph *createGraph(int V, int E)
{
    struct Graph *graph = new Graph;
    graph->V = V;
    graph->E = E;

    graph->edge = new Edge[E];
    return graph;
}

// Printing the solution
void printArr(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void Dijkstra(struct Graph *graph, int s)
{
    priority_queue<int, vector<int>, greater<int>> g;

    int V = graph->V;
    int E = graph->E;
    int dist[V];    // Stores distance from source for each vertex
    int prev[V];    // Stores predecessor of each node
    int visited[V]; // Stores if node is visited

    // Initialize distance and predecessor arrays
    for (int i = 0; i < V; i++)
    {
        dist[i] = INT_MAX; // Set distance to infinity
        prev[i] = -1;
        visited[i] = 0; // Set all to not visited
    }

    // Set source distance to zero
    dist[s] = 0;

    // Relaxing edges
    for (int i = 0; i < V - 1; i++)
    { // Iterate V-1 times
        for (int j = 0; j < E; j++)
        { // Iterate through all edges
            int u = graph->edge[j].u;
            int v = graph->edge[j].v;
            int w = graph->edge[j].w;

            int tempDistance = dist[u] + w;
            if (dist[u] != INT_MAX && tempDistance < dist[v])
            {
                dist[v] = tempDistance;
                prev[v] = u;
            }
        }
    }

    // Check for negetive cycles
    for (int j = 0; j < E; j++)
    { // Iterate through all edges
        int u = graph->edge[j].u;
        int v = graph->edge[j].v;
        int w = graph->edge[j].w;

        if (dist[u] != INT_MAX && dist[u] + w < dist[v])
        {
            cout << "Negetive cycle exists" << endl;
            return;
        }
    }

    // Print the distance and predecessor array
    printArr(dist, V);
    printArr(prev, V);
}

int main()
{
    // Create a graph
    int V = 4; // Total vertices
    int E = 5; // Total edges

    // Array of edges for graph
    struct Graph *graph = createGraph(V, E);

    // edge 0 --> 1
    graph->edge[0].u = 0;
    graph->edge[0].v = 1;
    graph->edge[0].w = 5;

    // edge 0 --> 2
    graph->edge[1].u = 0;
    graph->edge[1].v = 2;
    graph->edge[1].w = 4;

    // edge 1 --> 3
    graph->edge[2].u = 1;
    graph->edge[2].v = 3;
    graph->edge[2].w = 3;

    // edge 2 --> 1
    graph->edge[3].u = 2;
    graph->edge[3].v = 1;
    graph->edge[3].w = 6;

    // edge 3 --> 2
    graph->edge[4].u = 3;
    graph->edge[4].v = 2;
    graph->edge[4].w = 2;

    BellmanFord(graph, 0); // 0 is the source vertex

    return 0;
}