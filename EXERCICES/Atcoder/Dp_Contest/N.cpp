#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifdef local
    #include "/home/enzo/Documents/Prog/OBItraining/debug.h"
    #define pr(...) debug(#__VA_ARGS__, __VA_ARGS__)
    #define prs(...) debug_nameless(__VA_ARGS__)
#else
    #define pr(...) 69
    #define prs(...) 69
#endif

int main(){
    cin.tie(0), ios_base::sync_with_stdio(0);
    ll n; cin >> n;
    vector dp(n, vector<pair<ll,ll>> (n, {1e15,1e15}));
    vector<ll> items(n);
    for(ll i = 0; i < n; i++) cin >> items[i];
    for(ll i = 0; i < n; i++) dp[i][i] = {0, items[i]};

    for(ll size = 1; size < n; size++){
        for(ll i = 0; i+size < n; i++){
            for(ll j = 0; j < size; j++){
                ll sum_price = dp[i][i+j].first + dp[i+j+1][i+size].first;
                ll sum_size =  dp[i][i+j].second + dp[i+j+1][i+size].second;
                if(sum_price + sum_size  < dp[i][i+size].first){
                    dp[i][i+size] = {sum_price + sum_size, sum_size};   
                }
            }
        }   
    }

    pr(dp);

    cout << dp[0][n-1].first << "\n";

}