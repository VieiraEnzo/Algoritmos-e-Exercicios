#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,c1,c2,r;
    int x,y,hits=0;
    cin >> n >> c1 >> c2 >> r;
    
    for(int i = 0; i < n ; i++){
        cin >> x >> y;
        if(pow(x-c1,2) + pow(y-c2,2) <= pow(r,2)){hits++;}
    }
    cout << hits;
}
