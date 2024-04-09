#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    
    ll a,b,c; cin >> a >> b >> c;
    int ac = a;
    int bc = b;
    //x tem a bits 1's
    //y tem b bits 1's
    //
    int p = __popcount(c);
    string sa = "000000000000000000000000000000000000000000000000000000000000";
    string sb = "000000000000000000000000000000000000000000000000000000000000";

    // cout << __popcount(c) << endl;

    for(int i = 0; i < 60; i++){

        if(a > b &&  (1ll << i) & c){
            a--;
            sa[i] = '1';
        }else if(b > a && (1ll << i) & c){
            b--;
            sb[i] = '1';
        }else if((1ll << i) & c){
            a--;
            sa[i] = '1';
        }
    }

    if(a != b){cout << -1 << endl; return 0;}

    for(int i = 0; i < 60; i++){

        if(a > 0 && sa[i] != '1' && sb[i] != '1'){
            sa[i] = '1';
            sb[i] = '1';
            a--;
        }

    }

    ll x=0, y=0;

    for(int i = 0; i < 60; i++){
        if(sa[i] == '1'){
            x += (1ll << (i));
        }
        if(sb[i] == '1'){
            y += (1ll << (i));
        }
    }


    if( a > 0||__popcount(x)!= ac || __popcount(y) != bc || (x^y) != c){
        cout << -1 << "\n";
        return 0;
    }

    cout << x  << " " <<  y << endl;
    // cout << (x ^ y) << endl;
    
}   