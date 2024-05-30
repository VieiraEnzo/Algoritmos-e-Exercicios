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

void solve(){
    int n, q; cin >> n >> q;
    vector<int> v(n+1);
    for(int i = 1; i <= n; i++) cin >> v[i];
    vector<bitset<30>> sv(n+1);

    for(int i = 1; i <= n; i++){
        sv[i] = sv[i-1];
        for(int i = 0; i < 30; i++){
            sv[i] ^= v[i];
        }
    }

    while (q--)
    {
        int l,r; cin >> l >> r;
        if((sv[l] & sv[r]) == 0 && l-r > 1){
            cout << "YES\n";
        }
        cout << "NO\n";
        
    }
    
}

signed main(){
    fastio;
    int t; cin >> t;
    while (t--) solve();
}