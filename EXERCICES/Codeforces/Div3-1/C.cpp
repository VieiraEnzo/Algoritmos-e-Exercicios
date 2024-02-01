#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define endl "\n"
typedef long long ll;

void solve()
{
        ll n, f, a, b; cin  >> n >> f >> a >> b;
        vector<ll> v(n);
        for(ll i = 0; i < n; i++) cin >> v[i];

        ll momento_atual = 0;
        for(ll i = 0 ; i < n; i ++) 
        {
            f = f - min(a*(v[i] - momento_atual), b);
            momento_atual = v[i];
        }

        if(f <= 0) cout << "NO" << endl;
        else cout << "YES" << endl;
}

int main()
{
    fastio 

    ll t; cin >> t;
    while (t--)
    {
        solve();
    }
    
}