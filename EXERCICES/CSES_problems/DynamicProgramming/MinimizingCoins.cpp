#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;
const int  inf = 1e9;

int main(){
    fastio;
    ll n, x; cin >> n >> x;

    vector<ll> c(n);
    for(ll i = 0; i < n; i++)cin>>c[i];

    vector<ll> dp(x+1, inf);

    //todos começam por infinito
    //x = 0 -> dp = 0
    dp[0] = 0;

    for(ll i = 1; i <= x; i++){
        for(ll j = 0; j < n; j++){
            if(i-c[j] < 0) continue;
            dp[i] = min(dp[i],dp[i-c[j]] + 1);
        }
    }

    if(dp[x] == inf){cout << -1 << endl;}
    else cout << dp[x] << endl;
    

}