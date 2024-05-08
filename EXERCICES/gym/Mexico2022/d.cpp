#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#pragma GCC optimize("O3")

const int maxn = 5e4 + 10;
const int inf = 1e9;
const int mod = 1e9 + 7;
signed main(){
    cin.tie(0), ios_base::sync_with_stdio(0);

    int n, m, k;
    cin >> n >> m >> k;

    vector <pair<int,int>> edge(m);
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        edge[i] = {u-1, v-1};
    }

    vector <vector<int>> dp(2, vector<int>(n));
    for(int i = 0; i < n; i++) dp[0][i] = 1;
    
    for(int i = 1; i <= k; i++){
        for(int j = 0; j < m; j++){
            int u = edge[j].first, v = edge[j].second;
            dp[1][u] += dp[0][v];
            dp[1][v] += dp[0][u];
            dp[1][v] %= mod;
            dp[1][u] %= mod;
        }
        for(int j = 0; j < n; j++){
            dp[0][j] = dp[1][j];
            dp[1][j] = 0;
        }
    }

    cout << dp[0][0] << endl;

    return 0;
}