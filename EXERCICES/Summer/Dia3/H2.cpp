#include <bits/stdc++.h>
using namespace std;

template<typename T> struct Hashing{
    int base, n;
    vector<T> pow, ha; 

    Hashing(string & s, int a) : n(s.size()), base(a) ,pow(n+1), ha(n+1){

        pow[0] = 1;
        for(int i = 0; i < n; i++){
            ha[i + 1] = ha[i] * base + s[i];
            pow[i+1] = pow[i] * base;
        }

    }

    T getRange(int a, int b){
        assert(a <= b);
        return ha[b] - ha[a] * pow[b-a];

    }
    

};

int main(){

    const unsigned int mod1 = 1e9 + 7;
    const unsigned int mod2 = 1e9 - 9;
    const int base1 = 33;
    const int base2 = 31;

    using num1 = modnum<mod1>;
    using num2 = modnum<mod2>;

    string s; cin >> s;

    Hashing<num1> h1(s,base1);
    Hashing<num2> h2(s,base2);

    int t; cin >> t;
    while (t--)
    {
        int a, b; cin >> a >> b;
        cout << (h1.getRange(a,b).x);
        cout << (h2.getRange(a,b).x);
        cout << endl;
    }
    


}