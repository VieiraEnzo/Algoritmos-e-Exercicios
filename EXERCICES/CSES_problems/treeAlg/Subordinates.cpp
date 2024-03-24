#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> grafo(2e5 + 5);
vector<int> dp(2e5 + 5);

void dfs(int v){
    int sum = 0;
    for(auto a : grafo[v]){
        dfs(a);
        sum += 1 + dp[a];
    }
    dp[v] = sum;
}

int main(){
    int n; cin >> n;
    
    for(int i = 2; i <= n; i++){
        int a; cin >> a;
        grafo[a].push_back(i);
    }   

    dfs(1);

    for(int i = 1; i <= n; i++){
        cout << dp[i] <<  " ";
    }
}