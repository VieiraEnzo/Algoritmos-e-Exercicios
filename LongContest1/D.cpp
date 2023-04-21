#include <bits/stdc++.h>
using namespace std;

int main(){
    int x,y,a,b;
    cin >> x >> y;
    b = (y-2*x);
    a = x - b/2;
    if (b % 2 == 0 && a >= 0 && b >= 0){
        cout << "Yes";
    }
    else{
        cout << "No";
    }
}
