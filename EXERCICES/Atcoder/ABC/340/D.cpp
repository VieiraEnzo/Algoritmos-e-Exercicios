#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;

struct Dykstra
{
    ll INF = 1e18;

    int n;
    vector<ll> dist;
    vector<vector<pair<int,int>>> g;

    Dykstra(int n) : n(n), dist(n+1,INF), g(n+1) {}

    void addEdge(ll v, ll u, ll p){
        g[v].push_back({u,p});
    }

    void dykstra(ll v){

        //preparing structures
        priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, 
        greater<pair<ll,ll>>> fila;

        //setting up
        fila.push({0,v});
        
        while (!fila.empty())
        {      
            ll vert = fila.top().second;
            ll price = fila.top().first;
            fila.pop();

            if(dist[vert] != INF) continue;

            dist[vert] = price;

            for(auto viz : g[vert]){
                ll nxt = viz.first;
                ll cost = viz.second;
                fila.push({price + cost, nxt});
            }
        }

    }

};





int main(){
    fastio;
    int n; cin >> n;

    Dykstra prob(n);

    for(int i = 1; i < n; i++){
        int a, b, x; cin >> a >> b >> x;
        prob.addEdge(i,i+1,a);
        prob.addEdge(i, x, b);
    }

    prob.dykstra(1);


    cout << prob.dist[n] << endl;
    

}