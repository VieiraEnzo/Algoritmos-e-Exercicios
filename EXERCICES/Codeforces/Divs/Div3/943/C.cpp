#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#pragma GCC optimize("pragv")

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
    int n; cin >> n;
    vector<int> v(n);
    v[0] = 0;
    for(int i = 1; i < n; i++) cin >> v[i];
    vector<int> ans ;
    
    for(int i = 1; i < n; i++){
        if(v[i] >= v[i+1]){
            int dif = v[i-1] - v[i];        
            dif = max(dif, 2);
            if(i == 0) ans.push_back(dif);
            ans.push_back(v[i] + dif);
            v[i] = v[i] + dif;
        }else{

        }
    }

}


int main(){
    
    fastio;

    int t; cin >> t;
    while (t--)
    {
        solve();
    }

}