#include <bits/stdc++.h>
#define int long long
using namespace std;

int maxn = 5e4 + 5;

signed main(){
    int k, p; cin >> k >> p;
    vector<int> dp(maxn, 1e9);
    vector<int> prod(p);
    for(int i = 0; i < p; i++) cin >> prod[i];

    dp[0] = 0;

    for(int i = 1; i < maxn; i++){
        for(int j = 0; j < p; j++){
            int peso = prod[j];
            if(i - peso < 0){
                dp[i] = min(dp[i], abs(i - peso));
            }else{
                dp[i] = min(dp[i], dp[i-peso]);
            }
        }
    }

    for(int i = 0; i < k; i++){
        int e; cin >> e;
        cout << dp[e] << "\n";
    }
}