#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1e18;

struct Edge
{
    int u;
    int v;
    int wt;
};

int main()
{
    int n, m;
    cin >> n >> m;

    vector<Edge> edges;

    for(int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        edges.push_back({u, v, w});
    }

    int src = 1;

    vector<ll> dist(n + 1, INF);
    dist[src] = 0;

    // Relax all edges V-1 times
    for(int i = 1; i <= n - 1; i++)
    {
        for(auto edge : edges)
        {
            int u = edge.u;
            int v = edge.v;
            int wt = edge.wt;

            if(dist[u] != INF && dist[u] + wt < dist[v])
            {
                dist[v] = dist[u] + wt;
            }
        }
    }

    // Check for negative cycle
    bool negativeCycle = false;

    for(auto edge : edges)
    {
        int u = edge.u;
        int v = edge.v;
        int wt = edge.wt;

        if(dist[u] != INF && dist[u] + wt < dist[v])
        {
            negativeCycle = true;
            break;
        }
    }

    if(negativeCycle)
    {
        cout << "Negative Cycle Exists\n";
    }
    else
    {
        for(int i = 1; i <= n; i++)
        {
            if(dist[i] == INF)
                cout << "INF ";
            else
                cout << dist[i] << " ";
        }
    }
}