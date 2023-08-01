#include <bits/stdc++.h>
typedef long long ll;
using namespace std;


//nao entendi ainda

int main(){
    ll n,t; cin >> n >> t;
    vector<ll> k(n);
    for(ll i=0; i < n; i++) cin >> k[i];
    sort(k.begin(),k.end());
    ll l =1, r = 1e18;
    ll mid;
    while (l < r)
    {
        mid = (l+r)/2;
        ll prod = 0;
        for(ll j = 0; j < n; j ++){
            prod += mid/k[j];
            if(prod >= t)break;
        }
        if(prod < t){
            l = mid+1;
        }
        else{
            r = mid;
        }
    }
    cout << mid;

}
    