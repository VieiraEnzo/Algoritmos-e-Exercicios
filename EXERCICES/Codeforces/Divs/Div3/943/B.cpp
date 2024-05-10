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
    string a, b; cin >> a >> b;
    vector<int> num(2);
    for(int i = 0; i < m; i++){num[b[i] - '0']++;}

    int resp = 0;
    for(int i = 0; i < n; i++){
        if(num[a[i] - '0'] > 0){
            num[a[i] - '0']--;
            resp++;
        }else{
            break;  
        }
    }

    cout << resp << "\n";
}


int main(){
    
    fastio;

    int t; cin >> t;
    while (t--)
    {
        solve();
    }

}