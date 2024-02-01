#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
vector<int> dist;
vector<int> vis;
vector<vector<pair<int,int>>> g;

void dj(int x){
    memset(&dist, 1e9, sizeof(dist));
    memset(&vis, 0, sizeof(vis));
    priority_queue<pair<int,int>> fila;
    dist[x] = 0;
    fila.push({0,x});
    while(!fila.empty()){
        int u = fila.top().second;
        fila.pop();
        if(vis[u]) continue;
        vis[u] =1;
        for(pair<int,int> a : g[u]){
            if(a.first + dist[u] > dist[a.second]){
                dist[a.second] = a.first + dist[u];
                fila.push({dist[a.second], a.second});
            }
        }
    }
}



int main(){
    fastio;
    int n,m; cin >>n >> m;
    g.resize(n);
    dist.resize(n);
    vis.resize(n);
    for(int i =0; i<m; i++){
        int temp1,temp2,temp3;
        cin >> temp1 >> temp2 >> temp3;
        g[temp1].push_back(make_pair(temp3,temp2));
        g[temp2].push_back(make_pair(temp3,temp1));
    }
}