#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pii;
typedef pair<ll,ll> pll;

void solve(){
    ll m, x; cin >> m >> x;
    vector<ll> c(m+1);
    vector<ll> h(m+1);
    ll sum = 0;
    for(ll i = 1; i <= m; i++){
        cin >> c[i] >> h[i];
        sum += h[i];
    }

    vector dp(m+1, vector<ll> (sum+1, 1e18));
    for(ll i = 1; i <= m; i++) dp[i][0] = 0;

    for(ll i = 1; i <= m; i++){
        for(ll j = 1; j <= sum; j++){
            dp[i][j] = dp[i-1][j];
            if(j - h[i] >= 0 && dp[i-1][j - h[i]] + c[i] <= (i-1) * x)
                dp[i][j] = min(dp[i-1][j - h[i]] + c[i], dp[i][j]);
        }
    }

    for(ll i = 1; i <= m; i++){
        if(c[i] <= (i-1)*x) dp[i][h[i]] = c[i];
        for(ll j = 1; j <= sum; j++){
            dp[i][j] = min(dp[i][j],dp[i-1][j]);
            if(j - h[i] >= 0 && (dp[i-1][j - h[i]] + c[i] <= (i-1) * x))
                dp[i][j] = min(dp[i-1][j - h[i]] + c[i], dp[i][j]);
        }
    }

    // cout << dp[2-1][110 - h[2]] + c[2] << " " << (2-1) * x << endl;

    // for(ll i = 1; i <= m; i++){
    //     for(ll j = 1; j <= sum; j++){
    //         cout << dp[i][j] << " ";
    //     }cout << endl;
    // }

    for(ll i = sum; i >= 0; i--){
        if(dp[m][i] != 1e18){
            cout << i << "\n";
            break;
        }
    }


}

signed main(){
    fastio;
    ll t; cin >> t;
    while (t--) solve();
}