#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;
int max_lucro = 100000;
vector<int> peso;
vector<int> lucro;

// int solve(int n, int l){
//     if(l < 0) return 1e9;
//     if(n = 1 && l < lucro[1]) return peso[1];
//     else if (n = 1) return 1e9;
//     int a = solve(n-1,l);
//     int b = solve(n-1, l - lucro[n]) + peso[n];
//     return min(a,b);
// }


int main(){
    //fastio;
    int n, w; cin >> n >> w;
    peso.resize(n+1);
    lucro.resize(n+1);

    int dp[max_lucro];
    fill(dp, dp + max_lucro, 1e9);
    for(int i =1; i <= n; i++)cin >> peso[i] >> lucro[i];
    for(int i = 0; i < lucro[i]; i ++)dp[i] = peso[1];
    for(int i = 2; i <= n; i++){
        for(int l = 0; l <= max_lucro; l++)
        {
            if(l-lucro[i] < 0){continue;}
            dp[l] = min(dp[l], dp[l- lucro[i]] + peso[i]);
            
        }
    }
    for(int l = max_lucro; l>=0; l--){ 
        cout << dp[l] << " ";
        if(dp[l] <= w ){
            cout << dp[l] << endl;
            return 0;
        }
    }



}