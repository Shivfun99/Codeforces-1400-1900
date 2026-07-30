#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf=1e18;

vector<ll >dijkstra(int n,int src,vector<vector<pair<int,int>>>&adj)
{
vector<ll>dist(n+1,inf);
//dis , node
priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>>pq;

dist[src]=0;
pq.push({0,src});
while(!pq.empty()){
    auto cur=pq.top(); pq.pop();
    ll d=cur.first;
    int u=cur.second;

    //ignore old
    if(d>dist[u]) continue;

    //relax all
    for(auto edge:adj[u]){
        int v=edge.first;
        int wt=edge.second;

        if(dist[u]+wt<dist[v]){
            dist[v]=dist[u]+wt;
            pq.push({dist[v],v});
        }
    }
}
return dist;
}


int main(){


    int n,m; cin>>n>>m;
    vector<vector<pair<int,int>>>adj(n+1);
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
        vector<ll>dist=dijkstra(n,1,adj);
        for(int i=1;i<=n;i++){
            cout<<"dist from 1 to "<<i<<"=="<<dist[i]<<endl;
        }
    
}