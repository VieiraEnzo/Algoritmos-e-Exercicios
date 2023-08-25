#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)

int main(){
    fastio;
    long long n; cin >> n;
    while (n != 1)
    {   
        cout << n << ' ';
        if(n%2){
            n = 3 *n +1;
        }
        else{
            n/=2;
        }
        
    }
    cout << n << endl;
}