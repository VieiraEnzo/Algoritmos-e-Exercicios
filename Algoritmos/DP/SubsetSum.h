
/*
    Desired Sum - S
    Numbers - n
    Subset sum - Implementation O(n) memory and O(S * sqrt(N)) runtime
    Uses sliding window technique to optimize the subset sum problem.
    This implementation assumes that the input is a set of integers where each integer can be used multiple
    times, and the goal is to determine if a subset of these integers can sum up to a given target sum S.
*/

vector<pair<int,int>> sack; // {item, frequency}
vector<int> dp(S+1, 0);


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