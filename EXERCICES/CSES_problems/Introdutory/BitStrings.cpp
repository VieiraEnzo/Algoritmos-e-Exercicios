#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;

int fastexp(ll a, ll b){
    ll res = 1;
    while (b > 0)
    {
        if(b & 1)
            res = (res * a)%(1000000000+7);
        a = (a * a)%(1000000000+7);
        b >>= 1;
    }
    return res%(1000000000+7);

}


int main(){
    fastio;
    ll n; cin >> n;

    cout << fastexp(2,n) << endl;

}