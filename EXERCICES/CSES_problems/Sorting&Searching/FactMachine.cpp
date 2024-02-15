#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;
ll t;

bool f(ll test, vector<ll> &v){
    ll ans = 0;
    for(ll i = 0; i < v.size(); i++){
        ans += test/v[i];
        if(ans >= t) return true;
    }
    return ans >= t;
}

void bb(vector<ll> &v){

    ll l=0, r = 1e18;

    while (l < r)
    {   
        ll mid = (l+r)/2;
        if(f(mid, v)){
            r = mid;
        }else{
            l = mid+1;
        }
    }
    
    cout << l << endl;

}

int main(){
    fastio;
    ll n; cin >> n >> t;
    vector<ll> v(n);
    for(ll i = 0; i < n; i++)cin>> v[i];
    bb(v);
    
    
}
