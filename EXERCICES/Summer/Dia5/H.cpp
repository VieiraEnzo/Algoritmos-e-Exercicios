#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int m = 1e7;

ll fastexp(ll b, ll e, ll mod){
    ll res = 1;
    while (e)
    {
        if(e&1) res=(res*b)%mod;
        b=(b*b)%mod;
        e>>=1;
    }
    return res;
}


int main(){
    ll n , k , l; cin >> n >> k >> l;

    if(n%10 == 5){
        ll per = fastexp(((k*k)%m + l)%m, (ll)n/(ll)10, m);
        cout << k * per << endl;

    }else{
        cout << fastexp(((k*k)%m + l)%m, (ll)n/(ll)10, m) << endl;
    }



}