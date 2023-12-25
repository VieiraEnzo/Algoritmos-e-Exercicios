#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;
 
 
int main()
{
    fastio;
    int n; cin >> n;
    vector<ll> pref(n);
    vector<ll>smod(n,0);
    smod[0]  = 1;
    ll sum = 0;
    ll ans = 0;
    for(int i = 0; i < n; i++)
    {
        ll temp; cin >> temp;
        sum += temp;
        if(sum < 0) sum = (sum%n) + n;
        pref[i] = sum % n;
        ans+= smod[pref[i]];
        smod[sum % n]++;
    }
    cout << ans << endl;
}