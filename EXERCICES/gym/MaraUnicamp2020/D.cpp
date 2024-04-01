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
    int n, m; cin >> n >> m;
    vector<int> monster(n+1);
    vector<vector<pii>> dp(n+1, vector<pii> (m+1));

    for(int i = 0; i <=m ; i++) dp[0][i].first = 0;
    for(int i = 1; i <=n ;i ++) cin >> monster[i];

    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= m; j++){
            dp[i][j].second = dp[i-1][j].second + monster[i]; 
            dp[i][j].first = dp[i-1][j].first +  dp[i][j].second; 
            if(j - 1 >= 0 ) dp[i][j] = min(dp[i][j], {dp[i-1][j-1].first ,  0}); 
        }
    }

    //HIPOTESE: PESO QUE CARREGA IMPORTA 

    cout << dp[n][m].first << endl;
   
   


}