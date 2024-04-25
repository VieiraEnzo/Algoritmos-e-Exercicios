#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int v[] = {16,18,6,17,10,7,3,9};

    int dp[9][43];
    for(int i = 0; i < 9; i++)
        for(int j = 0; j < 43; j++) 
            dp[i][j] = 0;

    dp[0][0] = 1;

    for(int i = 1; i < 9; i++){
        for(int j = 0; j < 43; j++){
            dp[i][j] = dp[i-1][j];
            if(j-v[i-1] >= 0) dp[i][j] =  max(dp[i][j], dp[i-1][j-v[i-1]]);
        }
    }

    for(int i = 1; i < 9; i++){
        cout << "Passo " << i << ": ";
        for(int j = 0; j < 43; j++){
            cout << dp[i][j] << " ";
        }cout << "\n";
    }

    
}