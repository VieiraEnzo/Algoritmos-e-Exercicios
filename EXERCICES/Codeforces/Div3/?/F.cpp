#include <bits/stdc++.h>
//#pragma GCC optimize("pragv")
using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;

void solve(){
    ll n, m, k; cin >> n >> m >> k;
    vector<ll> a(n);
    vector<ll> d(m);
    vector<ll> f(k);
    for(ll i = 0; i < n; i++) cin >> a[i];
    for(ll i = 0; i < m; i++) cin >> d[i];
    for(ll i = 0; i < k ;i++) cin >> f[i];

    sort(f.begin(), f.end());

    ll maxd = 0;
    ll ind = -1;
    for(ll i = 0; i < n-1; i++){
        if(a[i+1] - a[i] == max(maxd, a[i+1] - a[i])){
            maxd = a[i+1] - a[i];
            ind = i;
        }
    }

    ll newcomp = ((a[ind+1] + a[ind])+1)/2;

    ll res = 1e9;
    ll elment;
    for(ll i = 0; i < m; i++){
        auto it = upper_bound(f.begin(), f.end(), newcomp - d[i]);
        if(it != f.end()){
            if(res != min(res, abs((*it + d[i]) - newcomp))){
                
            }
        }
        if(it != f.begin())res = min (res, abs((*prev(it)+d[i]) - newcomp));
    }

    if(res < maxd){a.push_back(newcomp - res);n++;}

    sort(a.begin(), a.end());

    ll ans = 0;    
    for(ll i = 0; i < n-1; i++){
        ans = max(ans, a[i+1] - a[i]);
    }

    cout << ans << endl;

}   



int main(){
    
    fastio;

    ll t; cin >> t;
    while (t--)
    {
        solve();
    }

}