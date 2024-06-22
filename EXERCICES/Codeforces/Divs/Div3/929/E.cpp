#include <bits/stdc++.h>

using namespace std;

#ifdef local
    #include "/home/enzo/Documents/Prog/OBItraining/debug.h"
    #define pr(...) debug(#__VA_ARGS__, __VA_ARGS__)
    #define prs(...) debug_nameless(__VA_ARGS__)
#else
    #define pr(...) 69
    #define prs(...) 69
#endif


#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pii;
typedef pair<ll,ll> pll;

void solve(){

    //ai caras: u + u-1 + u-2 + ...
    //          u * (1 + 0 + -1 + -2)
    // Pa de razão -1
    // (u + (u + 1 - ai) / 2) * ai
    // (2*u + 1 - ai)/2 * ai
    // (u + 1/2 - ai/2) * ai

    ll n; cin >> n;
    vector<ll> a(n+1), sum(n+1); 
    for(ll i = 1; i <= n; i++) cin >> a[i];
    for(ll i = 1; i <= n; i++) sum[i] += sum[i-1] + a[i];

    ll q; cin >> q;
    while(q--){
        ll l, u; cin >> l >> u;

        auto f = [&] (ll mid){
            ll ai = sum[mid] - sum[l-1];
            return ((2*u + 1 - ai) * ai)/2;
        };

        ll left = l, right = n;
        while (right - left > 2)
        {
            ll m1 = left + (right - left)/3;
            ll m2 = right - (right - left)/3;
            ll f1 = f(m1);
            ll f2 = f(m2);
            if(f1 < f2){
                left = m1;
            }else{
                right = m2;
            }
        }

        ll maxA = -1e9, index = 0;
        for(ll i = left; i <= right; i++){
            if(f(i) > maxA){
                maxA = f(i);
                index = i;
            } 
        }
        
        cout << index << " ";

    }
    cout << "\n";
}

signed main(){
    fastio;
    ll t; cin >> t;
    while (t--) solve();
}