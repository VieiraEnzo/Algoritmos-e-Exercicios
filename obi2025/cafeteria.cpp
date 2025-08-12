#include <bits/stdc++.h>
using namespace std;

int main(){

    // entrada do problema
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    bool resp=false;
    for(int n=0; n<=50; n++){
        // n*d + a <= c <= n*d + b
        if(n*d + a <= c && c <= n*d + b) resp = true;
    }

    cout << (resp? "S\n": "N\n");

    return 0;
}