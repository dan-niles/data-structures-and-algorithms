#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

const int MAX = 1e6 - 1;
int root[MAX];

/*
 * Complete the 'kruskals' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts WEIGHTED_INTEGER_GRAPH g as parameter.
 */

/*
 * For the weighted graph, <name>:
 *
 * 1. The number of nodes is <name>_nodes.
 * 2. The number of edges is <name>_edges.
 * 3. An edge exists between <name>_from[i] and <name>_to[i]. The weight of the
 * edge is <name>_weight[i].
 *
 */

struct Edge
{
    int u, v, wt;
};

// Custom comparator to compare edges
bool compare_edges(Edge e1, Edge e2)
{
    if (e1.wt < e2.wt)
        return true;
    else if (e1.wt > e2.wt)
        return false;
    else if (e1.u + e1.v < e2.u + e2.v)
        return true;
    else
        return false;
}

// Find parent of v
int find_parent(int v)
{
    while (root[v] != v)
    {
        root[v] = root[root[v]];
        v = root[v];
    }

    return v;
}

// Join trees of u and v
void union_edges(int u, int v)
{
    int i = find_parent(u);
    int j = find_parent(v);
    root[i] = root[j]; // Set parent of v as parent of u
}

int kruskals(int g_nodes, vector<int> g_from, vector<int> g_to,
             vector<int> g_weight)
{
    int total_wt = 0;
    int g_edges = g_weight.size(); // No of edges

    // Create seperate edge structures
    vector<Edge> edges;
    for (int i = 0; i < g_edges; i++)
    {
        Edge e = {g_from[i], g_to[i], g_weight[i]};
        edges.push_back(e);
    }

    // Sort edges based on custom criteria
    sort(edges.begin(), edges.end(), compare_edges);

    // Loop though each edge in increasing order
    for (int i = 0; i < g_edges; i++)
    {
        int u = edges[i].u;
        int v = edges[i].v;
        int wt = edges[i].wt;

        // Check if u and v have the same parent node
        if (find_parent(u) != find_parent(v))
        {
            total_wt += wt;
            union_edges(u, v); // Join u and v to same tree
        }
    }

    return total_wt;
}

int main()
{
    for (int i = 0; i < MAX; ++i) // Initialize root array
        root[i] = i;              // i th index contains parent of i th node

    ofstream fout(getenv("OUTPUT_PATH"));

    string g_nodes_edges_temp;
    getline(cin, g_nodes_edges_temp);

    vector<string> g_nodes_edges = split(rtrim(g_nodes_edges_temp));

    int g_nodes = stoi(g_nodes_edges[0]);
    int g_edges = stoi(g_nodes_edges[1]);

    vector<int> g_from(g_edges);
    vector<int> g_to(g_edges);
    vector<int> g_weight(g_edges);

    for (int i = 0; i < g_edges; i++)
    {
        string g_from_to_weight_temp;
        getline(cin, g_from_to_weight_temp);

        vector<string> g_from_to_weight = split(rtrim(g_from_to_weight_temp));

        int g_from_temp = stoi(g_from_to_weight[0]);
        int g_to_temp = stoi(g_from_to_weight[1]);
        int g_weight_temp = stoi(g_from_to_weight[2]);

        g_from[i] = g_from_temp;
        g_to[i] = g_to_temp;
        g_weight[i] = g_weight_temp;
    }

    int res = kruskals(g_nodes, g_from, g_to, g_weight);

    // Write your code here.

    fout << res;

    fout.close();

    return 0;
}

string ltrim(const string &str)
{
    string s(str);

    s.erase(s.begin(),
            find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

    return s;
}

string rtrim(const string &str)
{
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end());

    return s;
}

vector<string> split(const string &str)
{
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos)
    {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
