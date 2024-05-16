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
typedef pair<ll,ll> pii;
typedef pair<ll,ll> pll;
using ordered_set = tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>;
using ordered_multiset = tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update>;

map<ll,ll> appearB;
map<ll,ll> subseg;


void solve(){
    ll n, m, k; cin >> n >> m >> k;

    appearB.clear();
    subseg.clear();

    vector<ll> a(n);
    vector<ll> b(m);
    for(ll i = 0; i < n; i++) cin >> a[i];
    for(ll j = 0; j < m; j++){cin >> b[j]; appearB[b[j]]++;}

    ll ans = 0;
    ll difNumAp = 0;
    for(ll i = 0; i < m; i++){
        if(subseg[a[i]] < appearB[a[i]]){
            difNumAp++;
        }
        subseg[a[i]]++;
    }

    if(difNumAp >= k) ans++;
    // cout << "a: " << difNumAp << endl;

    for(ll i = 1; i + m -1 < n; i++){
        if(appearB[a[i-1]]){
            if(subseg[a[i-1]] <= appearB[a[i-1]]) 
                difNumAp--;
        }
        subseg[a[i-1]]--;

        if(appearB[a[i + m - 1]]){
            if(subseg[a[i + m - 1]] < appearB[a[i + m - 1]]){
                difNumAp++;
            }
        }
        subseg[a[i + m - 1]]++;

        if(difNumAp >= k) ans++;
        // cout << "a: " << difNumAp << endl;
    }
    // cout << endl;
    cout << ans << "\n";
}


int main(){
    
    fastio;

    ll t; cin >> t;
    while (t--)
    {
        solve();
    }

}