#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    for(int i=0; i < t; i ++){
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        int count = 0;
        if(a<b){count++;}
        if(a<c){count++;}
        if(a<d){count++;}
        cout << count << endl;

    }   
}