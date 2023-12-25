#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;
 
 
int main()
{
    fastio;
    int n, x; cin >> n >> x;
    vector<ll> pref(n);
    map<ll,set<int>> mp;
    ll sum = 0;
    ll ans = 0;
    mp[0].insert(-1);
    for(int i = 0; i < n; i++)
    {
        ll temp; cin >> temp;
        sum += temp;
        pref[i] = sum;
        if(!mp[pref[i] - x].empty())
        {
            //ams += numeros de resp < i
            ans+= mp[pref[i] - x].size();
        }
        mp[sum].insert(i);
    }
 
    cout << ans << endl;
}