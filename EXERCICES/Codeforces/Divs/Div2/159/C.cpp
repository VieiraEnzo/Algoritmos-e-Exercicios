#include <bits/stdc++.h>

using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pii;
typedef pair<ll,ll> pll;

void solve(){
    ll n; cin >> n;
    vector<ll> v(n);
    set<ll> socorro;
    ll ans = 0, M = -1e9, m = 1e9;
    for(ll i = 0; i< n; i++){cin >> v[i]; M = max(M, v[i]); socorro.insert(v[i]); m = min(m, v[i]);}
    ll mdc = M - m;
    for(ll i = 0; i < n; i++) if(v[i] != M) mdc = __gcd(mdc, M - v[i]);
    if(mdc == 0) mdc = 1;
    for(ll i = 0; i < n; i++) ans += (M - v[i])/mdc;

    // prllf("%d, %d\n", M, mdc);
    
    for(ll i = M; ; i -= mdc){
        // cout << i << "\n";
        if(socorro.find(i) == socorro.end()){
            ans += (M-i)/mdc;
            break;
        }
    }

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