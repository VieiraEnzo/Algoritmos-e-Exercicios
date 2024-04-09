#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n, a, b; cin >> n >> a >> b;
    ll semana = a+b;

    set<ll> st;

    ll day = 0;
    for(ll i = 0; i < n; i++){
        ll k; cin >> k; 
        st.insert(k%semana);
    }

    ll maxdif=  0;
    ll last = *(prev(st.end()));
    // cout << last << endl;
    for(auto a : st){
        ll b = (a - last - 1)<0?(a-last-1)+semana:(a-last-1);
        // cout << a << " " << last << " " << b << endl;
        maxdif = max(maxdif, b);
        
        last = a;
    }



    // cout << maxdif << endl;

    if(maxdif >= b){
        cout << "Yes\n";
    }else{
        cout << "No\n";
    }
}