#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;


int main(){
    int n; cin >> n;
    vector<double> p(n);
    for(int i =0; i <n; i++) cin >> p[i];
    double dp[n][n+1];
    memset(dp, 0, sizeof(double) * n*n);
    dp[0][0] = (1-p[0]);
    dp[0][1] = p[0];
    

    for(int i= 1; i < n; i++){
        for(int j = 0; j <= n; j++){
            dp[i][j] = dp[i-1][j-1] * p[i] + dp[i-1][j] * (1-p[i]);
        }
    }

    double ans = 0;
    int ind = 0;
    if(n%2) ind = n/2+1;
    else ind = n/2;
    for(int i = ind; i <= n; i++){
        ans += dp[n-1][i];
    }

    cout << fixed << setprecision(10) << ans << endl;

}