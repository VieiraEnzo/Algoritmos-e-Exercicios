#include <bits/stdc++.h>
using namespace std;

int main(){
    int x,y,a,b;
    cin >> x >> y >> a >> b;
    //cout <<(x-a)*(y-b) << endl;
    int sum = 0;
    for(int i =a; i <= x; i++){
        for(int j=b; j < i && j <= y; j++){
            sum++;
        }
    }
    cout << sum << endl;
    for(int i =a; i <= x; i++){
        for(int j=b; j < i && j <= y; j++){
            cout << i << ' ' << j << endl;
        }
    }
}