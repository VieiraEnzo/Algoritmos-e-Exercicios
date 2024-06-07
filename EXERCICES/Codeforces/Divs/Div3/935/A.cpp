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
    int ans = 0;
    int a,b,c; cin >> a >> b >> c;
    ans += a;
    int r = 3 - b%3;
    if(c < r && r != 3) {cout << -1 << "\n"; return;}
    if(b%3 == 0) r = 0; 
    c -= r;
    ans += (b+2)/3;
    ans += (c+2)/3;
    cout << ans << "\n";
}

signed main(){
    fastio;
    int t; cin >> t;
    while (t--)
    {
        solve();
    }
    
}