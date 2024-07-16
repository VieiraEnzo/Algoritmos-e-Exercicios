#include <bits/stdc++.h>

using namespace std;

#ifdef local
    #include "/home/enzo/Documents/Prog/OBItraining/debug.h"
    #define pr(...) debug(#__VA_ARGS__, __VA_ARGS__)
    #define prs(...) debug_nameless(__VA_ARGS__)
#else
    #define pr(...) 69
    #define prs(...) 69
#endif

#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

struct Dykstra
{
    int INF = 1e9;

    int n;
    vector<int> dist;
    vector<vector<pair<int,int>>> g;

    Dykstra(int n) : n(n), dist(n+1,INF), g(n+1) {}

    void addEdge(int v, int u, int p){
        g[v].push_back({u,p});
    }

    void clear(){
        fill(dist.begin(), dist.end(), INF);
    }

    void dykstra(int v, int x){

        //preparing structures
        priority_queue<pair<int,int>, vector<pair<int,int>>, 
        greater<pair<int,int>>> fila;

        //setting up
        fila.push({x,v});
        
        while (!fila.empty())
        {      
            int vert = fila.top().second;
            int price = fila.top().first;
            fila.pop();

            if(dist[vert] != INF) continue;

            dist[vert] = price;

            for(auto viz : g[vert]){
                int nxt = viz.first;
                int cost = viz.second;
                fila.push({price + cost + x, nxt});
            }
        }

    }

};


int main(){
    fastio;
    int n, m, q; cin >> n >> m >> q;
    Dykstra dj(n);
    
    for(int i = 0; i < m; i++){
        int u, v, w; cin >> u >> v >> w;
        dj.addEdge(u,v,w);
    }

    while(q--){
        dj.clear();
        int u, v, x; cin >> u >> v >> x;
        dj.dykstra(u, x);
        if(dj.dist[v] == dj.INF) cout << -1 << "\n";
        else cout << dj.dist[v] << "\n";
    }

}