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

void solve(){
    ll l, a, b; cin >> a >> b >> l;

    set<ll> num;
    for(ll i = 1; i <= l; i *= a){
        for(ll j = 1; j <= l; j *= b){
            if(i*j > l) continue;
            if(l % (i*j) == 0) {num.insert(l/(i*j));}
        }
    }

    cout << num.size() << "\n";
}

signed main(){
    fastio;
    int t; cin >> t;
    while (t--) solve();
}