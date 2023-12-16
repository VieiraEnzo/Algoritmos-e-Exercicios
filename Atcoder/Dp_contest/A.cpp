#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;

int main(){
    fastio;
    int n; cin >> n;
    vector<int> p(n);
    vector<int> dp(n,1e9);
    for(int i =0; i <n; i++) cin >> p[i];

    //bottom up
    dp[0] = 0;
    for(int i =0; i <n; i++)
    {
        dp[i+1] = min(dp[i+1], dp[i] + abs(p[i+1] - p[i]));
        dp[i+2] = min(dp[i+2], dp[i] + abs(p[i+2] - p[i]));
    }

    cout << dp[n-1] << endl;

}