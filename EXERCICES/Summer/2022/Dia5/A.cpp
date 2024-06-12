#include <bits/stdc++.h>
using namespace std;

int main(){

    int a,b,c; 

    while (cin >> a)
    {
        cin >> b >> c;
        if(a != b && a!=c) cout << 'A' << endl;
        else if(b != c && b!=a) cout << 'B' << endl;
        else if(c != b && c!=a) cout << 'C' << endl;
        else{cout << '*' << endl;}
    }
 
}
    

   