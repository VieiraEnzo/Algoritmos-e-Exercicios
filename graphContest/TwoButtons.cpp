#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int minimum_presses(int n, int m){
    if(n > m){
        return n - m;
    }
    else if(n == m){
        return 0;
    }

    else if(n > (1+m)/2 && m % 2 == 0){
        return n - (1+m)/2 + 1;
    }

    else if(n > (1+m)/2){
        return (n - (1+m)/2) + 2;
    }

    else{
        return minimum_presses(n*2,m) + 1;
    }
}

int main(){
    int m,n; cin >> n >> m;
    cout << minimum_presses(n,m);
    

}
    

