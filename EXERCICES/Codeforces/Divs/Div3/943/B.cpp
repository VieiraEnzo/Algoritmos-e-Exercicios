#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace std;
using namespace __gnu_pbds;

#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
using ordered_set = tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>;
using ordered_multiset = tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update>;


void solve(){
    int n, m; cin >> n >> m;
    string a,b; cin >> a >> b;
    vector<int> dp(m+1);
    dp[0] = 0;

    int l = 0;
    for(int i = 1; i <= m; i++){
        dp[i] = dp[i-1];
        if(l < n && a[l] == b[i-1]){
            dp[i] = dp[i-1] + 1;
            l++;
        }
    }

    cout << dp[m] << "\n";
}


int main(){
    
    fastio;

    int t; cin >> t;
    while (t--)
    {
        solve();
    }

}