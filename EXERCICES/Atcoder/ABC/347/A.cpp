#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k; cin >> n >> k;

    for(int i = 0; i < n; i++){
        int b; cin >> b;
        if(b % k == 0){
            cout << b/k << " "; 
        }
    }
    
}