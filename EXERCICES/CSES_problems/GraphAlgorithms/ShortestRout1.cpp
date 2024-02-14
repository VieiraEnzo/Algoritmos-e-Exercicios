#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;
const ll inf = 1e9;
ll maxn = 1e5 + 5;
vector<vector<pair<ll,ll>>> g(maxn);
vector<ll> dist(maxn, inf);

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

        if(dist[vert] != inf) continue;

        dist[vert] = price;

        for(auto viz : g[vert]){
            fila.push({price + viz.first, viz.second});
        }
    }

}


int main(){

    fastio;
    ll n, m; cin >> n >> m;
    for(ll i = 0; i < m; i ++){
        ll a, b, c; cin >> a >> b >> c;
        g[a].push_back({c,b});
    }

    dykstra(1);

    for(ll i = 1; i <=n; i++){
        cout << dist[i] << " ";
    }cout << endl;
    

}