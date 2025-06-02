/*
    # Numbers - n 
    Desired Sum - S
    Subset sum - Implementation O(n*sqrtN) memory and runtime
*/

vector<vector<int>> dp(sack.size()+1, vector<int> (n+1, 0));
dp[0][0] = 1;

for(int i = 1; i <= sack.size(); i++){
    auto [item, freq] = sack[i-1];
    for(int j = 0; j < item; j++){
        int numTrues = 0;
        for(int k = j; k <= n; k += item){
            dp[i][k] = dp[i-1][k];
            if(numTrues > 0) dp[i][k] = true;

            if(k - freq*item >= 0) numTrues -= dp[i-1][k - freq*item];
            numTrues += dp[i-1][k];
        }   
    }
}

/*
    Subset sum - Implementation O(n) memory and O(nsqrt) runtime
*/

for(int i = 0; i < sack.size(); i++){
    vector<int> ndp(n+1);
    auto [item, freq] = sack[i];
    for(int j = 0; j < item; j++){
        int numTrues = 0;
        for(int k = j; k <= n; k += item){
            ndp[k] = dp[k];
            if(numTrues > 0) ndp[k] = true;
            if(k - freq*item >= 0) numTrues -= dp[k - freq*item];
            numTrues += dp[k];
        }
    }
    swap(ndp, dp);
}