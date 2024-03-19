#include <bits/stdc++.h>
#pragma GCC optimize("pragv")
using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;

void solve(){
    ll n; cin >> n;
    vector<ll> v(n);
    for(ll i = 0; i < n; i++) cin >> v[i];

    for(ll i = 0; i < n-2; i++){
        if(v[i] < 0) continue;
        v[i+1] -= 2*v[i];
        v[i+2] -= v[i];
        v[i] = 0;
    }

    bool res = true;
    for(ll i = 0; i < n; i++){
        if(v[i] != 0) res = false;
        // cout << v[i] << " ";
    }

    if(res) cout << "YES" << endl;
    else cout << "NO" << endl; 
}


int main(){
    
    fastio;

    ll t; cin >> t;
    while (t--)
    {
        solve();
    }

}