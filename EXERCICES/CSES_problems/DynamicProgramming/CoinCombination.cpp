#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;

int main(){
    fastio;
    int n, x; cin >> n >> x;

    vector<int> coins(n);
    vector<int> dp(x+1);
    for(int i =0; i < n; i++){cin>>coins[i];dp[coins[i]]++;}


    

}