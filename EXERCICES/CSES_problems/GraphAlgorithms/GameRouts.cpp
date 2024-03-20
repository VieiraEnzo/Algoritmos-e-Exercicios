#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct TopoSort
{
    ll n;
    vector<ll> grau;
    vector<vector<ll>> grafo;

    TopoSort(ll n): n(n), grau(n+1), grafo(n+1){}
    
    void add_edge(ll a, ll b){
        grau[b]++;
        grafo[a].push_back(b);
    }
    
    vector<ll> top_sort(){
        vector<ll> resp;
        queue<ll> fila;
        for(ll i=1; i<=n;i++){
            if(!grau[i])fila.push(i);
        }
        while (!fila.empty())
        {
            ll u = fila.front();
            resp.push_back(u);
            fila.pop();
            for(ll viz : grafo[u]){
                grau[viz]--;
                if(!grau[viz])fila.push(viz);
            }   
        }
        if(resp.size() < n){
            return {};
        }else{
            return resp;
        }
    }
};




int main(){
    ll mod = 1e9 + 7;

    ll n, m; cin >> n >> m;
    vector<ll> dp(n+1);
    vector<vector<ll>> graph(n+1);

    TopoSort top(n);

    for(ll i = 0; i < m; i++){
        ll a, b; cin >> a >> b;
        top.add_edge(a,b);
        graph[a].push_back(b);
    }

    vector<ll> c =  top.top_sort();

    dp[1] = 1;
    for(ll i = 0; i < n; i++){
        ll v = c[i];
        for(auto a : graph[v]){
            dp[a]= (dp[a] + dp[v])%mod;
        }
    }

    cout << dp[n] << endl;

}