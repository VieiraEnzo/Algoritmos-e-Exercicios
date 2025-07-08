#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
typedef long long ll;

const int mod = 1e9+7;

void solve(){

    
    string a, b; cin >> a >> b;
    vector dp(b.size(), vector (2, vector<int> (2)));

    while(a.size() < b.size()) a.insert(a.begin(), '0');

  
    for(int i = b.size()-1; i>= 0; i--){
        for(int digit = 0; digit <= 9; digit++){

            if(digit < (a[i]-'0')){

            }else if(digit == (a[i]-'0')){

            }

        }
    }

}       

int main(){

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    ll t; t = 1;
    for(int i = 0; i < t; i++){ 
        solve();
    }

}