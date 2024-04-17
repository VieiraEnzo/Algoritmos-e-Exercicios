#include <bits/stdc++.h>

using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pii;
typedef pair<ll,ll> pll;

void solve(){
    ll n; cin >> n;

    int sum = 0;
    for(int i = 1; i <=n ; i++){
        sum += i * (2*i-1);
    }

    cout << sum << " " <<  2*n << "\n"; 

    for(ll i = n; i >= 1; i--){
        cout << 1 << " " << i  << " ";
        for(ll i = 1; i <= n; i++){
            cout << i << " ";
        }cout << "\n";
        cout << 2 << " " << i  << " ";
        for(int i = 1; i <= n; i++){
            cout << i << " ";
        }cout << "\n";
    }   


}


int main(){
    fastio;
    ll t; cin >> t;
    while (t--)
    {
        solve();
    }
    
    

}