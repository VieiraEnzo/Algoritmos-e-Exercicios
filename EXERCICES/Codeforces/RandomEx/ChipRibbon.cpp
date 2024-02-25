#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;

void solve(){
    
    int n; cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    vector<int> dp(n);

    dp[0] = v[0]-1;
    int minN = v[0];
    for(int i = 1; i < n; i++){
        if(v[i] == 0){dp[i] = 0;}
        else if(v[i-1] >= v[i]) dp[i] = 0;
        else{
            dp[i] = v[i] - minN;
            minN = v[i];
        }
        minN = min(minN, v[i]); 
    }

    ll ans = 0;
    for(int i = 0; i < n; i++){
        ans += dp[i];
    }

    cout << ans << endl;
}


int main(){
    
    fastio;

    int t; cin >> t;
    while (t--)
    {
        solve();
    }

}