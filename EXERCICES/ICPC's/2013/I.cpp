#include <bits/stdc++.h>
using namespace std;

int n, c, t1, t2; 
vector<int> v;

pair<int,int> deslocamento(int n, int t, int l){
    int ans = n-1, p = t;
    for(int i = n-1; i>= 1+l; i--){
        if(v[n] - v[i] <= t){
            ans = i-1;
        }else{
            break;
        }
    }
    return {ans, p};
}

int main(){
    cin >> n >> c >> t1 >> t2;
    v.resize(2*n+1);
    for(int i = 1; i <= n; i++) cin >> v[i];
    for(int i = 1; i <= n; i++) v[i+n] = v[i] + c;
    vector<int> dp(2*n+1,1e9);
    dp[0]=0;

    int ans = 1e9;
    for(int l = 0; l < n; l++){
        fill(dp.begin(), dp.end(), 1e9);
        dp[l] = 0;
        for(int i = 1 + l; i <= l+n; i++){
            auto a1 = deslocamento(i, t1, l);
            int a = a1.first, p = a1.second;
            auto a2 = deslocamento(i, t2, l);
            int b = a2.first, k = a2.second;
            // cout << a << " " << p << " " << b << " " << k << "\n"; 

            dp[i] = min(dp[a] + p, dp[b] + k);
        }
        ans = min(ans, dp[l+n]);
    }
    cout << ans << "\n";
}