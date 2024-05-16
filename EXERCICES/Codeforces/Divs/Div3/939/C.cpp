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


void solve(){
    ll n, k; cin >> n >> k;
    deque<ll> boats;

    for(ll i = 0; i < n; i++) {ll a; cin >> a; boats.push_back(a);}

    while (boats.size() > 1 && k > 0)
    {
        if(k < 2*boats.front() - 1 && k < 2*boats.back()) break;
        if(boats.front() < boats.back()){
            ll dam = boats.front();
            boats.pop_front();
            boats.back() -= (dam);
            k -= (2*dam);
        }else if (boats.back() < boats.front()){
            ll dam = boats.back();
            boats.pop_back();
            boats.front() -= dam;
            k -= 2*dam;
        }else{
            ll dam = boats.front();
            boats.pop_front();  
            k -= dam;
            if(k < dam){
                break;
            }else{
                boats.pop_back();
                k -= dam;
            }
        }
    }

    if(boats.size() == 1){
        if(k >= boats.front()){
            boats.pop_front();
        }
    }

    cout << n - boats.size() << "\n";



}


int main(){
    
    fastio;

    ll t; cin >> t;
    while (t--)
    {
        solve();
    }

}