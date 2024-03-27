#include <bits/stdc++.h>

using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int main(){
    fastio;
    int n; cin >> n;
    int mod = 1e9+7;

    vector mat(n+1, vector<char> (n+1, '.'));
    vector dp(n+1, vector<int> (n+1));

    for(int i = 1; i <=n; i++)
        for(int j = 1; j<=n; j++)
            cin >> mat[i][j];

    if(mat[1][1] != '*') dp[1][1] = 1;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(mat[i][j] == '*') continue;
            if(mat[i-1][j] == '.') dp[i][j] = (dp[i][j] + dp[i-1][j])%mod;
            if(mat[i][j-1] == '.') dp[i][j] = (dp[i][j] + dp[i][j-1])%mod;
        }
    }

    cout << dp[n][n] << endl;

}