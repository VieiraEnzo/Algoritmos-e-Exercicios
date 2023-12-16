#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;

int main(){
    fastio;
    ll t; cin >> t;
    while (t--)
    {
        ll n; cin >> n;
        string s; cin >> s;
        bool ex0 = false;
        for(ll i = 0; i < n; i++){
            if (s[i] == '0') ex0 = true;
        }

        if(ex0){
            cout << "YES" << "\n";
        }else{
            cout << "NO"  << "\n";
        }

    }
    
    

}