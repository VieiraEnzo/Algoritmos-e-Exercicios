#include <bits/stdc++.h>

using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;


void solve(){
    int n, k; cin >> n >> k;

    if(n == 1) {cout << k << '\n'; return;}

    int Bit = 0;
    for(int i = 0; i < 32; i++){
        if(k & (1 << i)){
            Bit = i;
        }
    }    

    vector<int> ans;
    ans.push_back((1 << Bit)-1);
    ans.push_back(k - ((1 << Bit)-1));

    while(ans.size() < n){
        ans.push_back(0);
    }

    for(auto a : ans){cout << a << " ";}
    cout << "\n";

}


int main(){
    fastio;
    int t; cin >> t;
    while (t--)
    {
        solve();
    }
    
    

}