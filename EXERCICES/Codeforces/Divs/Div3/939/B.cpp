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
    int n, c, d; cin >> n >> c >> d;
    vector mat(n, vector<int> (n));

    map<int,int> can;

    int aij = 1e9;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n ;j ++){
            cin >> mat[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        aij = min(aij, *min_element(mat[i].begin(), mat[i].end()));
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n ; j++){
            can[aij + c * i + d * j]++;
        }
    }


    for(int i = 0; i < n; i++){
        for(int j = 0; j < n ;j ++){
            if(can[mat[i][j]] > 0){
                can[mat[i][j]]--;
            }else{
                cout << "NO\n";
                return; 
            }
        }
    }

    cout << "YES\n";

}


int main(){
    
    fastio;

    int t; cin >> t;
    while (t--)
    {
        solve();
    }

}