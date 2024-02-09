#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;

ll INF = 1e18;
int maxn = 1e5 + 2;
vector<ll> dist(maxn, INF);
vector<vector<pair<ll,ll>>> g(maxn);

void dykstra(ll v){

    typedef pair<pair<int,int>, int> ppii;

    //preparing structures
    priority_queue<ppii, vector<ppii>, 
    greater<ppii>> fila;

    //setting up
    fila.push({make_pair(0,v), 0});
    
    while (!fila.empty())
    {    
        ll vert = fila.top().first.second;
        ll price = fila.top().first.first;
        ll maxC = fila.top().second;
        fila.pop();

        dist[vert] = min(price, dist[vert]);

        for(auto viz : g[vert]){
            if(viz.second > maxC){
                int cor = (maxC+1)/2;
                fila.push({make_pair(price + cor + (viz.second/2), viz.first), viz.second});
            }else{
                fila.push({make_pair(price + viz.second, viz.first), maxC});
            }

        }
    }
}


int main(){
    fastio;

    int n, m; cin >> n >> m;

    for(int i = 0; i < m; i++){
        ll a, b, c; cin >> a >> b >> c;
        g[a].push_back({b,c});
    }

    dykstra(1);

    cout << dist[n] << endl;

}