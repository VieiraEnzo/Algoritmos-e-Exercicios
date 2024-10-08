
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
                        BTcomponent(n+1){}

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

    void find_brig_and_artc(){
        for(ll i=1; i<=n; i++){
            if(!marc[i]) dfs(i,0);
        }   
    }

    ll Nvert = 0;

    void BTdfs(ll v, ll comp, ll proib){
        Nvert++;
        BTcomponent[v] = comp;
        for(auto viz : grafo[v]){
            if(BTcomponent[viz] || viz == proib) continue; 
            BTdfs(viz, comp, proib);
        }
    }

    void DPdfs(ll v, ll pai){
        for(auto viz : BT[v]){
            if(viz == pai) continue;
            DPdfs(viz, v);
            dp[v] += dp[viz];
        }
        dp[v]++;
    }

    void BrigeTree(){
        ll comp = 0;
        vector<ll> BTcomponentSize = {0};

        for(auto &b : bridges){
            if(!BTcomponent[b.first]){
                Nvert = 0;
                BTdfs(b.first, ++comp, b.second);
                BTcomponentSize.push_back(Nvert);
            }
            if(!BTcomponent[b.second]) {
                Nvert = 0;
                BTdfs(b.second, ++comp, b.first);
                BTcomponentSize.push_back(Nvert);
            }
        }


        BT.resize(comp+1);
        dp.resize(comp+1);

        for(auto &b : bridges){
            BT[BTcomponent[b.first]].push_back(BTcomponent[b.second]);
            BT[BTcomponent[b.second]].push_back(BTcomponent[b.first]);
        }

        DPdfs(bridges[0].first, bridges[0].second);
        ll ans = 1e18;
        for(auto &b : bridges){
            int ca = BTcomponent[b.first];
            int cb = BTcomponent[b.second];
            ans = min(ans, dp[ca] * dp[cb]);
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

    art.find_brig_and_artc();

    art.BrigeTree();
}

signed main(){
    fastio;
    ll t; cin >> t;
    while (t--) solve();
}