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
    int n,m; cin >> n >> m;
    vector<int> v(7);
    for(int i = 0; i < n; i++){
        char temp; cin >> temp;
        v[temp - 'A']++;
    }

    int ans = 0;
    for(int i = 0; i < 7; i++){
        if(v[i] > m) continue;
        else ans += (m - v[i]);
    }

    cout << ans << "\n";
}

signed main(){
    fastio;
    int t; cin >> t;
    while (t--) solve();
}