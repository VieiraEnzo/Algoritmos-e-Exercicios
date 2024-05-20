#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pii;
typedef pair<ll,ll> pll;

void solve(){
    ll n; cin >> n;
    vector<ll> v(n);
    for(ll i = 0; i < n; i++) cin >> v[i];

    map<pair<ll,ll>, pair<ll, map<ll,ll>>> inicio;
    map<pair<ll,ll>, pair<ll, map<ll,ll>>> meio;
    map<pair<ll,ll>, pair<ll, map<ll,ll>>> fim;

    ll ans = 0;
    for(ll i = 0; i < n-2; i++){
        inicio[{v[i+1], v[i+2]}].second[v[i]]++;
        inicio[{v[i+1], v[i+2]}].first++;
        meio[{v[i], v[i+2]}].second[v[i+1]]++;
        meio[{v[i], v[i+2]}].first++;
        fim[{v[i], v[i+1]}].second[v[i+2]]++;
        fim[{v[i], v[i+1]}].first++;
    }

    for(auto a : inicio){
        ll i = 0;
        for(auto b : a.second.second){
            ans += b.second * (a.second.first - b.second);
            i++;
        }
    }


    for(auto a : meio){
        ll i = 0;
        for(auto b : a.second.second){
            ans += b.second * (a.second.first - b.second);
            i++;
        }
    }

    for(auto a : fim){
        ll i = 0;
        for(auto b : a.second.second){
            ans += b.second * (a.second.first - b.second);
            i++;
        }
    }


    cout << ans/2 << "\n";
}

signed main(){
    fastio;
    ll t; cin >> t;
    while (t--) solve();
}