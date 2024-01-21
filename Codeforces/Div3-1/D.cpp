#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define endl "\n"
typedef long long ll;

void solve()
{
    ll n, m; cin >> n >> m;
    vector<ll> b(n);
    vector<ll> c(m);
    for(ll i = 0 ; i < n; i ++) cin >> b[i];
    for(ll i = 0 ; i < m; i ++) cin >> c[i];

    sort(b.begin(), b.end());
    sort(c.begin(), c.end());

    ll ptbb = 0, ptbe = n-1;
    ll ptcb =0, ptce = m-1;
    ll ans = 0;
    for(ll i= 0; i < n; i++)
    {   
        ll lb = abs(b[ptbb] - c[ptcb]);
        ll rb = abs(b[ptbb] - c[ptce]);
        ll le = abs(b[ptbe] - c[ptcb]);
        ll re = abs(b[ptbe] - c[ptce]);

        if(max(lb,rb) > max(le,re)){
            if(lb > rb)
            {
                ans += lb; 
                ptcb++;
            }
            else
            {
                ans += rb;
                ptce--;
            }
            ptbb++;
        }
        else {

            if(le > re)
            {
                ans += le; 
                ptcb++;
            }
            else
            {
                ans += re;
                ptce--;
            }
            ptbe--;
        }
    }

    cout << ans << endl;
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