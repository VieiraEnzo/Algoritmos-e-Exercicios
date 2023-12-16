#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;

int main(){

    fastio;
    int n,k; cin >> n >> k;
    vector<int> p(n);
    vector<int> dp(n,1e9);
    for(int i =0; i <n; i++) cin >> p[i];

    //bottom up
    dp[0] = 0;
    for(int i =0; i <n; i++)
    {
        for(int j = 1; j <= k && (i+j) < n; j++)
        {
            dp[i+j] = min(dp[i+j], dp[i] + abs(p[i+j] - p[i]));            
        }
    }

    cout << dp[n-1] << endl;

}