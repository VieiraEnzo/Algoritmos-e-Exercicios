#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

template<int MOD> struct Hashing{
    ll base, n;
    vector<ll> pow, ha; 

    Hashing(string & s, int a) : n(s.size()), base(a) ,pow(n+1), ha(n+1){

        pow[0] = 1;
        for(int i = 0; i < n; i++){
            ha[i + 1] = (ha[i] * base + s[i])%MOD;
            pow[i+1] = (pow[i] * base)%MOD;
        }

    }
    
    //Retorna o Hashing da substring [a, b)
    int getRange(int a, int b){
        assert(a <= b);
        ll hash =  ha[b] - ha[a] * pow[b-a];
        return hash < 0 ? hash + MOD : hash;
    }
    
};

set<int> ans;

int main(){

    string s; cin >> s;
    const int MOD = 1e9 + 7;
    int n = s.size();


    Hashing<MOD> ha(s, 33);

    for(int i = 1; i < n; i++){
        ans.insert(ha.getRange(0,i));
    }

    for(int i = n-1; i > 0; i--){
        if(ans.find(ha.getRange(i, n)) != ans.end()){
            cout << n - i << " ";
        }
    }
    cout << endl;

}