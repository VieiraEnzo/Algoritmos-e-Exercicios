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
    int n, m; cin >> n >> m;
    vector<int> ai(n), bi(n);
    for(int i = 0; i < n; i++)cin >> ai[i];
    for(int i = 0; i < n; i++)cin >> bi[i];


    ll price = 0, resp = 1e18;
    for(int i = n-1; i >= 0; i--){
        if(i <= m-1) resp = min(resp, price + ai[i]);
        price += min(ai[i], bi[i]);
    }    

    cout << resp << "\n";
}

signed main(){
    fastio;
    int t; cin >> t;
    while (t--) solve();
}