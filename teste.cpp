#include<bits/stdc++.h>
using namespace std;

int n, m, k;
vector<int> vis;
vector<vector<pair<int,int>>> grafo;

void dfs(int v, int time){
    vis[v] = 1;
    for(auto viz : grafo[v]){
        if(!vis[viz.first] && time >= viz.second){
            dfs(viz.first, time);
        }
    }
}

int check(int time){

    for(int i = 1; i <= n; i++) vis[i] = 0;
    dfs(1, time);
    int ans = 0;
    for(int i = 1; i <= n; i++) if(vis[i]) ans++; 
    
    return ans;
}

int bb(){
    int l = 0, r = 8765;
    while (l < r)
    {
        int mid = (l+r)/2;
        if(check(mid) < k){
            l = mid + 1;
        }else{
            r = mid;
        }
    }
    return l;
    
}

int main(){
    cin >> n >> m >> k;
    vis.resize(n + 1);
    grafo.resize(n + 1);
    for(int i = 0; i < m; i++){
        int u, v, p; cin >> u >> v >> p;
        grafo[u].push_back({v,p});
        grafo[v].push_back({u,p});
    }

    int ans = bb();
    cout << ans << "\n";
}