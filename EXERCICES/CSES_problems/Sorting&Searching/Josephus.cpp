#include <bits/stdc++.h>

using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int mod(int n, int i){
    return i%n;
}

int main(){
    fastio;
    int n; cin >> n;
    int modn = n;

    int cur = 2;
    int beg = -1;
    while (n > 0)
    {
        for(int i = 0; i < (n+1)/2; i++){
            beg = mod(modn,beg + cur); 
            cout << beg+1 << " ";
        }
        n /=2;
        cur *= 2;
    }
    
        
    

}