#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using i64 = long long;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n;string s;
    cin >> n >> s;
    vector dp(n+1, vector<int>(n+1, 0));
    for(int l = 0; l <= n; l++){
        for(int r = l+1; r <= n; r++){
            dp[r][l] = 1;
        }
    }
    vector <int> prefo(n+1), prefz(n+1);
    for(int i = 1; i <= n; i++){
        prefo[i] = prefo[i-1] + (s[i-1] == '1');
        prefz[i] = prefz[i-1] + (s[i-1] == '0');
    }
    vector <int> sufo(n+1), sufz(n+1);
    for(int i = n-1; i >= 0; i--){
        sufo[i] = sufo[i+1] + (s[i] == '1');
        sufz[i] = sufz[i+1] + (s[i] == '0');
    }
    // for(int i = 0; i <= n; i++){
    //     cout << prefo[i] << " ";
    // }
    // cout << "\n";
    // for(int i = 0; i <= n; i++){
    //     cout << prefz[i] << " ";
    // }
    // cout << "\n";
    // for(int i = 0; i <= n; i++){
    //     cout << sufo[i] << " ";
    // }
    // cout << "\n";
    // for(int i = 0; i <= n; i++){
    //     cout << sufz[i] << " ";
    // }
    // cout << "\n";
    const int mod = 1e9 + 7;
    for(int sz = 1; sz <= n; sz++){
        for(int l = 0; l+sz-1 < n; l++){
            int r = l+sz-1;
            if(prefo[l]+sufo[r+1] < prefz[l]+sufz[r+1]){
                dp[l][r] = 0;
                continue;
            }
            if(s[l] == '1'){//1 esquerda
                dp[l][r] = (dp[l][r] + dp[l+1][r]) % mod;
            }else if(prefo[l]+sufo[r+1] >= prefz[l]+sufz[r+1]+1){//0 esquerda
                dp[l][r] = (dp[l][r] + dp[l+1][r]) % mod;
            }
            //1 direita
            if(l != r){
                if(s[r] == '1'){//1 esquerda
                    dp[l][r] = (dp[l][r] + (r-1 >= 0 ? dp[l][r-1] : 1)) % mod;
                }else if(prefo[l]+sufo[r+1] >= prefz[l]+sufz[r+1]+1){//0 esquerda
                    dp[l][r] = (dp[l][r] + (r-1 >= 0 ? dp[l][r-1] : 1)) % mod;
                }    
            }
            //0 direita
        }
    }
    if(dp[0][n-1] == 0){
        cout << 0 << "\n";
    }else{
        cout << (dp[0][n-1]+1)%mod << "\n";
    }
    return 0;
}