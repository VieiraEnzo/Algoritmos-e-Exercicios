#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll fastexp(ll a, ll b, ll mod = 1e9 + 7){
    if(b == 0) return 1;
    ll e = a;b--;
    for(ll i = 0; i < 32; i++){
        if((1 << i) & b){
            a = (a * e)%mod;
        }
        e = (e * e)%mod;
    }
    return a;
}


int main(){
    ll n; cin >> n;
    while (n--)
    {
        ll a, b,c; cin >> a >> b >> c;
        cout << fastexp(a,fastexp(b,c)) << endl;
    }
    
}