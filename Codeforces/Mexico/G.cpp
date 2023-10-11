#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;

int main()
{
    fastio;
    ll l, g;
    cin >> l >> g;
    vector<pair<ll, ll>> gmb(g);
    for (ll i = 0; i < g; i++)
    {
        cin >> gmb[i].first >> gmb[i].second;
    }

    ll ans = 0;
    for (ll i = 0; i < g; i++)
    {
        if (gmb[i].second)
        {
            ans = max(ans, l - gmb[i].first);
        }
        else
        {
            ans = max(ans, gmb[i].first);
        }
    }
    cout << ans << endl;
}