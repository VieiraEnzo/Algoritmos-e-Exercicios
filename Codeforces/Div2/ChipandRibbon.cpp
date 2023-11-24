#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;
vector<ll> v;
ll ans;

void solve(ll i, ll n, ll red){
    if(i == n){
        ans += v[i] - red;
        return;
    }
    ll minE = 1e9, pos;
    for(ll j = i; j <= n; j++){
        if(v[j] < minE){
            pos = j;
            minE = v[j];
        }
    }
    ans += minE - red;
    //cout << pos << endl;
    if(pos == i){
        solve(pos+1, n, minE);
        }
    else if(pos == n){
        solve(i,pos-1, minE);
    }else{
        solve(i,pos-1, minE);
        solve(pos+1, n, minE);
    }

}



int main(){
    fastio;
    ll t; cin >> t;
    while (t--)
    {
        ll n; cin >> n;
        v.resize(n);
        for(ll i = 0 ; i < n; i++){
            cin >> v[i];
        }
        ans = 0;
        solve(0,n-1,0);
        cout << ans - 1 << endl;
    }
    
    

}