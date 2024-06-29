#include <bits/stdc++.h>

using namespace std;

#ifdef local
    #include "/home/enzo/Documents/Prog/OBItraining/debug.h"
    #define pr(...) debug(#__VA_ARGS__, __VA_ARGS__)
    #define prs(...) debug_nameless(__VA_ARGS__)
#else
    #define pr(...) 69
    #define prs(...) 69
#endif

#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;


int main(){
    fastio;
    int n; cin >> n;
    vector<ll> item(n);
    for(int i = 0; i < n; i++){
        cin >> item[i];
    }
    vector<vector<ll>> dp(n, vector<ll> (n, 1e9));

    int par = n%2;
    for(int i = 0; i < n; i++) dp[i][i] = par == 0? -item[i]: item[i];

    for(int i = n-1; i >= 0; i--){
        for(int j = 0; j < n; j++){
            if(j <= i) continue;
            if((j-i + 1)%2 == par){ //Taros
                dp[i][j] = max(dp[i+1][j] + item[i], dp[i][j-1] + item[j]);
            }else{  //Jiro
                dp[i][j] = min(dp[i+1][j] - item[i], dp[i][j-1] - item[j]);
            }
        }
    }

    std::cout << dp[0][n-1] << "\n";

}