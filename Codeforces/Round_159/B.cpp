#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;

ll ceil(ll a, ll b){
    if(a < 0) return 0;
    if(a%b == 0){return a/b;}
    else{return a/b + 1;}
}







void solve(){
    ll n, p , l ,t; cin >> n >> p >> l >> t;
    int num_testes = ceil(n,7);
    if(2 * ceil(num_testes,2) * t + ceil(num_testes,2) * l <= p){
        cout << n - max(ceil((p - num_testes * t),l), ceil(num_testes,2)) << endl;
        return;
    }
    ll left = 0, right = n;
    while (left < right)
    {
        ll mid = (left + right)/2;
        if(2 * mid * t + mid * l < p){
            left = mid + 1;
        }else{
            right = mid;
        }   
    }
    cout << n - left << endl;

}



int main(){
    fastio;
    ll t; cin >> t;
    while (t--)
    {
        solve();
    }
    
    

}