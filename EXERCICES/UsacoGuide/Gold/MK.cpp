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
    int n; cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    
    int inf = 1e9;
    vector<vector<int>> dp(n + 1, vector<int> (2, inf));
    dp[0][0] = 0;
    dp[0][1] = inf;

    for(int i = 0; i < n; i++){
        dp[i+1][1] = min(dp[i][0] + v[i], dp[i+1][1]);
        if(i+2 <= n) dp[i+2][1] = min(dp[i][0] + v[i] + v[i+1], dp[i+2][1]);
        dp[i+1][0] = min(dp[i][1], dp[i+1][0]);
        if(i+2 <= n) dp[i+2][0] = min(dp[i][1], dp[i+2][0]);       
    }

    // pr(dp);

    cout << min(dp[n][0], dp[n][1]) << "\n";
}

signed main(){
    fastio;
    int t; cin >> t;
    while (t--)solve();
    
    

}