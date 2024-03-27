#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;

void solve(){
    ll n, k; cin >> n >> k;

    ll i = 1;
    while (k > (n+1)/2)
    {
        k -= (n+1)/2;
        n/=2;
        i*=2;
    }

    cout << i*(2*k - 1) << endl;
    

}


int main(){
    
    fastio;


    ll t; cin >> t;
    while (t--)
    {
        solve();
    }

}