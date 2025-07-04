#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;

const int maxn = 2e6;
vector<ll> fact(maxn+1), ifact(maxn+1);

ll fastexp(ll x, ll e){
    ll ans = 1;
    while(e){
        if(e&1) ans = (ans * x)%mod;
        x = (x * x)%mod;
        e/=2;
    }
    return ans;
};

ll inv(ll x){
    return fastexp(x, mod-2);
};

void build(){

    fact[0] = 1;
    for(int i = 1; i <= maxn; i++) fact[i] = (fact[i-1] * i)%mod;
    ifact[maxn] = inv(fact[maxn]);
    for(int i = maxn-1; i >= 0; i--) ifact[i] = (ifact[i+1] * (i+1))%mod;

}

void solve(){


    int n; cin >> n;
    ll ans = 0;
    for(int i = 0; i <= n; i++){
        if(i%2 == 0) ans = (ans + fact[n] * ifact[i]%mod)%mod;
        else ans = ((ans - fact[n] * ifact[i]%mod)%mod + mod)%mod;
    }
    cout << ans << "\n";


}

int main(){

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    build();
    int t; t = 1;
    while(t--) solve();

}