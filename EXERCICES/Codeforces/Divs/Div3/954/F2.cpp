
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
typedef pair<ll,ll> pii;
typedef pair<ll,ll> pll;

struct ArticPont{

    ll n;
    ll count = 0;
    vector<ll> marc, tin, low, artic, dp;
    vector<vector<ll>> grafo, BT;
    vector<pair<ll,ll>> bridges;

    vector<ll> BTcomponent;

    ArticPont(ll n) : n(n), grafo(n+1), marc(n+1), tin(n+1), low(n+1), artic(n+1), 
                        BTcomponent(n+1), dp(n+1){}

    void add_edge(ll a, ll b){
        grafo[a].push_back(b);
        grafo[b].push_back(a);
    }

    void dfs(ll x, ll p){
        marc[x] = 1;
        tin[x] = low[x] = ++count;
        ll children = 0;
        for(ll viz : grafo[x]){
            if(viz == p) continue;
            if(marc[viz]){
                low[x] = min(low[x], tin[viz]);
            }else{
                dfs(viz,x);
                low[x] = min(low[x], low[viz]);
                if(low[viz] > tin[x]){
                    bridges.push_back({min(viz,x), max(viz, x)});
                }
                if(low[viz] >= tin[x] && p) artic[x] = 1;
                children++;
            }
        }
        if(!p && children>1) artic[x] = 1;
    }


    void DPdfs(int v){
        marc[v] = 1;
        for(auto viz : grafo[v]){
            if(marc[viz] ) continue;
            DPdfs(viz);
            dp[v] += dp[viz];
        }
        dp[v]++;
    }

    void solve(){

        pr(bridges);

        if(bridges.size() == 0){
            cout << (n*(n-1))/2 << "\n";
            return;
        }

        fill(all(marc), 0);
        DPdfs(bridges[0].first);

        pr(dp);

        ll ans = 1e18;
        for(int i = 0; i < bridges.size(); i++){
            int k1 = bridges[i].first;
            int k2 = bridges[i].second;
            ll v1 = n - min(dp[k1], dp[k2]);
            ll v2 = min(dp[k1], dp[k2]);
            ans = min(ans, (v1*(v1-1))/2 + (v2*(v2-1))/2);
        }


        cout << ans << "\n";
    }

};

void solve(){
    int n, m; cin >> n >> m;
    ArticPont art(n);

    for(int i = 0; i < m; i++){
        int a,b; cin >> a >> b;
        art.add_edge(a,b);
    }

    art.dfs(1,0);

    art.solve();
}

signed main(){
    fastio;
    ll t; cin >> t;
    while (t--) solve();
}