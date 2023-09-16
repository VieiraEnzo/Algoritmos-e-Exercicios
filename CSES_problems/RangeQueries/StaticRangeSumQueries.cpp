#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;


int main(){

    fastio;
    ll n, q; cin >> n >> q;
    n++;
    vector<ll> v(n);
    vector<ll> s(n);
    v[0] = s[0] = 0;
    for(ll i =1; i <n; i++) cin >> v[i];
    for(ll i =1; i <n; i++)
    {
        s[i] = v[i] + s[i-1];
    }


    while (q--)
    {
        ll i,j; cin >> i >> j;
        cout << s[j] - s[i-1] << endl;
    }

}