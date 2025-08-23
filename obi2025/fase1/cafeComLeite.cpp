#include <bits/stdc++.h>
using namespace std;

int main(){

    int a,b,c,d; cin >> a >> b >> c >> d;

    int leite = c-d;

    if(leite >= a && leite <= b){
        cout << "S\n";
    }else{
        cout << "N\n";
    }

    return 0;
}