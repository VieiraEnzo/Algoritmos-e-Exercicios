#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll maxn = 1e5 + 7;

void solve(ll n){


    vector<ll> p(3 * n);
    vector<ll> inp(n);

    ll Tsum = 0;
    for(ll i = 0; i< n; i++){
        cin >> inp[i];
        Tsum += inp[i];
    }

    ll sum = 0;
    for(ll i = 0; i < 3*n; i++){
        p[i] = sum;
        sum += inp[i%n];
    }

    // for(auto a : p){
    //     cout << a << " ";
    // }cout << "\n";

    if(Tsum%3 != 0){cout << 0 << "\n"; return;}
    ll arc = Tsum/3;

    ll ans = 0;
    for(ll i = 0; i < n; i++){
        // cout << p[i] + arc << " " << (Tsum+p[i])-arc << "\n";
        // cout <<*lower_bound(p.begin(), p.end(), (Tsum+p[i])-arc ) << " " << *lower_bound(p.begin(),p.end(), p[i] + arc) << "\n";
        if(*lower_bound(p.begin(),p.end(), p[i] + arc) == p[i] + arc && 
           *lower_bound(p.begin(), p.end(), (Tsum+p[i])-arc ) == (Tsum+p[i])-arc){
            ans++;
        }
    }


    cout << ans/3 << "\n";


}




int main(){

    cin.tie(nullptr); ios_base::sync_with_stdio(0);

    ll n;
    while (cin >> n)
    {
        solve(n);
    }
    


}