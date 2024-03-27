#include <bits/stdc++.h>

using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pii;
typedef pair<ll,ll> pll;

ll digitI(ll n, ll i){
    
    while (i--)
    {
        n/=10;
    }
    
    return n%10;
}


int main(){
    fastio;
    ll n; cin >> n;
    vector<ll> dp(n+1, 1e9);
    dp[0] = 0;

    for(ll i = 1; i <= n; i++){
        for(ll j = 0; j < 7; j++){
            dp[i] = min(dp[i], dp[i- digitI(i,j)] + 1);
        }
    }

    cout << dp[n] << endl;

}