#include <bits/stdc++.h>

using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

void solve(){
    int x; cin >> x;

    int ans = 0;
    int num = 0;
    for(int i = 1; i < x; i++){
        if(__gcd(x,i) + i > ans){
            ans = __gcd(x,i);
            num = i;
        }
    }

    cout << num << "\n";
}

int main(){

    fastio;
    int t; cin >> t;
    while (t--)
    {
        solve();
    }
    
    

}   