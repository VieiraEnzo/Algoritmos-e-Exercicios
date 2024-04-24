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
    vector<ll> vec(n);
    vector<ll> Beg(n, 1);
    vector<ll> End(n, 1);
    map<ll, pair<ll,ll>> freq;
    

    ll ans = 0;
    for(ll i = 0; i < n ; i++){
        ll v; cin >> v;
        vec[i] = v;
        if(freq.count(v) <= 0){freq[v] = {1e9, -1};}
        freq[v].first = min(freq[v].first, i);
        freq[v].second = max(freq[v].second, i);
    }

    for(ll i = 0; i < n; i++){
        ll v = vec[i];
        if(i > freq[v].first){
            Beg[i] = 0;
        }
        if(i < freq[v].second){
            End[i] = 0;
        }
    }

    for(ll i = n-2; i >= 0; i--){
        End[i] += End[i+1];
    }
    for(ll i = 0; i < n; i++){
        if(Beg[i]){
            // cout << i << "\n";
            ans += End[i];
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