#include <bits/stdc++.h>
#pragma GCC optimize ("trapv")
using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;
int maxn  = 4e5 + 4;
int mod = 1e9 + 7;
vector<ll> fact(maxn);

ll inv(int a) {
  return a <= 1 ? a : mod - (long long)(mod/a) * inv(mod % a) % mod;
}

void solve(){

    int n; cin >> n;

    ll N = (2*n - 1)%mod;
    ll K = n-1;

    ll a = fact[N];
    ll b = fact[K];
    ll c = fact[N-K];

    ll ans = (a * inv(b))%mod;
    ans = (ans * inv(c))%mod;

    cout <<  ans << endl;



}


int main(){
    fastio;

    fact[0] = 1;
    for(int i = 1; i < maxn; i++){
        fact[i] = (fact[i-1]%mod * i)%mod;
    }


    int t; cin >> t;

    while (t--)
    {
        solve();
    }
    

    

}