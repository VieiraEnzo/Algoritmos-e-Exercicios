#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;

int main(){
    fastio;
    ll n; cin >> n;
    vector<ll> v(n);
    for(ll i =0; i <n; i++) cin >> v[i];

    ll ans = -1e18, sum_now = 0;
    for(ll i =0 ; i < n; i++){
        sum_now += v[i];
        ans = max(ans, sum_now);
        if(sum_now < 0){
            sum_now = 0;
        }
    }
    cout << ans << endl;

}