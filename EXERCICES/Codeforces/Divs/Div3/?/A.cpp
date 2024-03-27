#include <bits/stdc++.h>
#pragma GCC optimize("pragv")
using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;

void solve(){
    int n, m, k; cin >> n >> m >> k;
    vector<int> b(n);
    vector<int> c(m);
    for(int i = 0; i < n; i++) cin >> b[i];
    for(int i = 0; i < m; i++) cin >> c[i];

    int ans = 0;
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < m; j++){
            if(b[i] + c[j] <= k){
                ans++;
            }
        }
    }

    cout << ans << endl;

}


int main(){
    
    fastio;

    int t; cin >> t;
    while (t--)
    {
        solve();
    }

}