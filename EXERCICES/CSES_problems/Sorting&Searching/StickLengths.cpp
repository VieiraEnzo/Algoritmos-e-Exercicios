#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;

int main(){
    fastio;
    ll n; cin >> n;
    vector<ll> v(n);
    for(ll i = 0; i < n; i++) cin >> v[i];

    ll mediana;
    sort(v.begin(), v.end());
    if(n%2){mediana = v[(n/2)];}
    else{mediana = (v[n/2] + v[(n-1)/2])/2;}


    ll ans = 0;
    for(ll i =0 ; i< n; i++) ans += abs(v[i] - mediana);


    cout << ans << endl;


}