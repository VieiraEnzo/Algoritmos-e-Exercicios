#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;
int max_lucro = 100005;
ll inf = 1e18;
vector<int> peso;
vector<int> lucro;


int main(){
    //fastio;
    int n, w; cin >> n >> w;
    //procurar menor peso para obter valor v
    vector<pair<int,int>> item(n+1);
    for(int i = 1; i <= n; i ++){
        int w1,v1; cin >> w1 >> v1;
        item[i] = {w1,v1};
    }
    
    ll dp[n+1][max_lucro];
    dp[0][0] = 0;
    for(int i = 1; i < max_lucro; i ++) dp[0][i] = inf;

    for(int i =1; i <= n; i++)
        for(int j = 0; j < max_lucro; j++){
            dp[i][j] = dp[i-1][j];
            if(j - item[i].second >= 0)
                dp[i][j] = min(dp[i-1][j], dp[i-1][j - item[i].second] + item[i].first);
        }

    ll ans = 0;
    for(int i= 0; i < max_lucro; i++){
        if(dp[n][i] <= w) ans = i;
    }

    cout << ans << endl;}