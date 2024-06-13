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
#define int long long
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;


ll fastexp(ll b, ll e, ll mod){
    ll res = 1;
    while (e)
    {
        if(e&1) res=(res*b)%mod;
        b=(b*b)%mod;
        e>>=1;
    }
    return res;
}




signed main(){
    fastio;
    int n, m; cin >> n >> m;
    vector<vector<int>> grafo(n);
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    for(int i = 0; i < n; i++){
        int Mxpts = 0, vert = -1;
        for(int j = 0; j < n; j++){
            if(j == i) continue;
            int pts = fastexp(v[i], v[j], m) + fastexp(v[j], v[i], m);
            if(pts >= Mxpts){
                Mxpts = pts;
                vert = j;
            }
        }
        grafo[i].push_back(vert);
    }    

}