#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Kosa{

    ll n, cont;
    vector<ll> marc, ord, comp;
    vector<vector<ll>> grafo, rgrafo,scc;

    Kosa(ll n) : n(n), marc(n+1), grafo(n+1), rgrafo(n+1), comp(n+1), scc(n+1) {} 

    void add_edge(ll a, ll b){
        grafo[a].push_back(b);
        rgrafo[b].push_back(a);
    }

    void dfs1(ll v){   
        marc[v] = 1;
        for(auto viz : grafo[v]){
            if(!marc[viz]) dfs1(viz);
        }
        ord.push_back(v);
    }

    void dfs2(ll v, ll c){
        comp[v] = c;
        for(auto viz : rgrafo[v]){
            if(!comp[viz]) dfs2(viz, c);
        } 
    }

    void build(){

        cont = 0;

        for(ll i = 1; i <=n ;i++){
            if(!marc[i]) dfs1(i);
        }

        reverse(ord.begin(), ord.end());

        for(ll v : ord){
            if(!comp[v]){
                dfs2(v, ++cont);
            }
        }

        for(ll i = 1; i <=n; i++){
            for(ll j : grafo[i]){
                if(comp[i] == comp[j]) continue;
                scc[comp[i]].push_back(comp[j]);
            }
        }

    }

};



void dfs3(ll v, Kosa &kosa, vector<ll> &dp, vector<ll> &marc){

    ll res = 0;
    marc[v] = 1;
    for(auto a : kosa.scc[v]){
        if(!marc[a]) dfs3(a, kosa, dp, marc);
        res = max(res, dp[a]);
    }

    dp[v] += res;
}

int main(){
    cin.tie(nullptr), ios_base::sync_with_stdio(0);
    ll n , m; cin >> n >> m;
    
    Kosa kosa(n);
    vector<ll> coins(n+1);
    
    for(ll i = 1; i <=n ; i++){
        cin >> coins[i];
    }

    for(ll i = 0; i < m; i++){
        ll a, b; cin >> a >> b;
        kosa.add_edge(a,b);
    }

    kosa.build();

    vector<ll> dp(n+1);
    vector<ll> marc(n+1);
    
    for(ll i = 1; i <= n; i++){
        dp[kosa.comp[i]] += coins[i];
    }

    ll ans = 0;
    for(ll i =1; i<=n; i++){
        if(!marc[i]){
            dfs3(i, kosa, dp, marc);
            ans = max(ans, dp[i]);
        }
    }

    cout << ans << endl;

}