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
        ll n; cin >> n;
        vector<ll> v(n), ans(n);
        for(ll i = 1; i < n; i++) cin >> v[i];
        v[0] = v[1] + 1;
        ans[0] = *max_element(v.begin(), v.end()) + 1;

        for(ll i = 1; i < n; i++){
            ans[i] = ans[i-1] + v[i];
        }


        for(auto a : ans){
            cout << a << " ";
        }cout << endl;
    }


    int main(){
        
        fastio;

        ll t; cin >> t;
        while (t--)
        {
            solve();
        }

    }