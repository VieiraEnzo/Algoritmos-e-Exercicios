#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;

int main(){
    fastio;
    int n, k; cin  >> n >> k;
    vector<int> A(n);
    vector<int> dp(k+1, 0);
    int mink = 1e9;
    for(int i = 0; i < n; i++){
        cin >> A[i];
        dp[A[i]] = 1;
        mink = min(mink, A[i]);
        }   

    for(int i = 0; i < mink; i++) dp[i] = 0;

    for(int i = 1; i < k+1; i++)
        for(int j =0; j < n; j++){
            if(i- A[j] <= 0) continue;
            if(dp[i - A[j]] == 0){
                dp[i] = 1;
            }
        }

    
    if(dp[k]) cout << "First" << endl;
    else cout << "Second" << endl;
    

}