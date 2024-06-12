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
    int x,y,z, k; cin >> x >> y >> z >> k;

    int ans = 0;
    for(int i = 1; i <= x; i++){
        int agr = 0;
        for(int j = 1; j <= y; j++){
            int l = k / (i*j);
            if(i*j*l != k || l == 0 || l > z) continue;
            ans = max(ans, (x+1-i) * (y+1-j) * (z+1-l));
        }
    }

    cout << ans << "\n";
}

signed main(){
    fastio;
    int t; cin >> t;
    while (t--) solve();
}