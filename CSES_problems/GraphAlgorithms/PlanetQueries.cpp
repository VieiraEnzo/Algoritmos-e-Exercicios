#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;




int main(){
    fastio;
    int n, q; cin  >> n >> q;
    int jumps[33][n+5];
    for(int i =0; i < n; i++){
        cin >> jumps[0][i];jumps[0][i]--;
    }

    for(int j = 1; j < 33; j++){
        for(int i =0; i < n; i++){
            jumps[j][i] = jumps[j-1][jumps[j-1][i]];
        }
    }


    while (q--)
    {
        int x, k; cin >> x >> k;x--;

        for(int i= 31; i >= 0; i--){
            if((1 << i) & k){
                x = jumps[i][x];
            }
        }

        cout << ++x << endl;    
        

    }
    
}