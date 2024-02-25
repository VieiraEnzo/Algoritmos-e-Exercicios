#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;

void solve(){
    ll k, x, a; cin >> k >> x >> a;

    ll numC = 1;
    for(ll i = 1; i <= x; i ++){
        ll c = (numC)/(k-1);
        c++;
        numC += c;
        if(numC > a) {cout << "NO" << endl;return;}
    }

    if(numC<=a){cout << "YES" << endl;}
    else cout << "NO" << endl;
}


int main(){
    
    fastio;

    ll t; cin >> t;
    while (t--)
    {
        solve();
    }

}