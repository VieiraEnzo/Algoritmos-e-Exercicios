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
    int n, x; cin >> n >> x;
    int dp[n+1][x+1];
    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= x; j++)
            dp[i][j] = 0;
    vector<int> pages(n+1);
    vector<int> price(n+1);

    for(int i = 1; i <= n; i++) cin >> price[i];
    for(int i = 1; i <= n; i++) cin >> pages[i];

    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= x; j++){
            dp[i][j] = dp[i-1][j];
            if(j - price[i] >= 0) {dp[i][j] = max(dp[i][j], dp[i-1][j - price[i]] + pages[i]);} 
        }
    }

    cout << dp[n][x] << endl;
}