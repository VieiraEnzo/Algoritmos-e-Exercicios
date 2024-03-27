#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;

int main(){
    fastio;
    int n, x; cin >> n >> x;
    vector<int> dp(x+1);
    vector<int> coins(n);
    int mod = 1e9+7;

    for(int i = 0; i < n; i++){
        cin >> coins[i];
    }

    dp[0] = 1;

    map<int,int> vis;
    for(int i = 1; i <= x; i++){
        vis.clear();
        for(int j = 0; j < n; j++){
            int coin = coins[j];
            if(i - coin < 0 || vis[coin]) continue;
            dp[i] = (dp[i-coin] + dp[i])%mod;
            vis[i-coin] = 1;
        }
    }

    for(int i = 0; i < x; i++) cout << dp[i] << " ";

    cout << dp[x] << endl;


}