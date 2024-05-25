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
    ll n, x, y; cin >> n >> x >> y;
    map<pair<ll,ll>, ll> mp;

    ll sum = 0;
    for(ll i = 0; i < n ; i++){
        ll a; cin >> a;
        sum += mp[{(x - a%x)%x, a%y}];
        mp[{a%x, a%y}]++;
    }

    cout << sum << "\n";
}

int main(){
    fastio;
    ll t; cin >> t;
    while (t--) solve();
}