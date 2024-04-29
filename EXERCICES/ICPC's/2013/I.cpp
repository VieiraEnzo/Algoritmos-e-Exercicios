#include <bits/stdc++.h>
using namespace std;

int n, c, t1, t2; 
vector<int> v;

pair<int,int> deslocamento(int n, int t){
    int ans = n-1, p = t;
    for(int i = n-1; i>= 1; i--){
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
    v.resize(n+1);
    for(int i = 1; i <= n; i++) cin >> v[i];
    vector<int> dp(n+1,1e9);
    dp[0]=0;

    for(int i = 1; i <= n; i++){
        auto a1 = deslocamento(i, t1);
        int a = a1.first, p = a1.second;
        auto a2 = deslocamento(i, t2);
        int b = a2.first, k = a2.second;
        // cout << a << " " << p << " " << b << " " << k << "\n"; 

        dp[i] = min(dp[a] + p, dp[b] + k);
    }

    cout << dp[n] << "\n";
}