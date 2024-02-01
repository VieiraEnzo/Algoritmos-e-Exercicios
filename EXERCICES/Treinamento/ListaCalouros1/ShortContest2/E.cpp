#include <bits/stdc++.h>
using namespace std;

int main(){
    int t,n;
    cin >> t;
    for(int i =0; i< t; i ++){
        cin >> n;
        if(n > 4 && n != 1){
            cout << "Alice" << endl;
        }
        else{
            cout << "Bob" << endl;
        }
    }
}