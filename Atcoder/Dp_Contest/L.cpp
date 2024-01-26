#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;


int main(){
    int n; cin >> n; n++;
    vector dp(n, vector(n, (int) 0));
    int mult = -1;
    if((n-1)%2) mult = 1;

    for(int i = 0; i < n-1; i++){
        cin >> dp[i][i+1];
        dp[i][i+1] *= mult;
    }
    mult *= -1;

    for(int j =2; j < n; j++){
        for(int i = 0; i + j < n; i++){
            dp[i][i+j] = mult * (max(abs(dp[i][i+j-1]), abs(dp[i+1][i+j])) -
                         min(abs(dp[i][i+j-1]), abs(dp[i+1][i+j])));
        }
        mult*=-1;
    }

    for(auto a : dp){
        for(auto b : a)
            cout << b << " ";
        cout << endl;
    }


    cout << dp[0][n-1] << endl;



}