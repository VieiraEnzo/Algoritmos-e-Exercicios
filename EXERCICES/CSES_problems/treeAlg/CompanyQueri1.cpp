#include <bits/stdc++.h>
using namespace std;
vector jmp(32, vector<int> (2e5+5, -1));

int main(){
    int n, q; cin >> n >> q;

    for(int i = 2; i <= n; i++){
        cin >> jmp[0][i];
    }

    for(int i = 1; i < 32; i++){
        for(int j = 1; j <= n; j++){
            // cout << i << " " << j << endl;
            jmp[i][j] = jmp[i-1][jmp[i-1][j]];
        }
    }

    while (q--)
    {
        int node, dif; cin >> node >> dif;

        for(int i = 0; i < 32; i++){
            if(1<<i & dif){
                node = jmp[i][node];
            }
        }
        
        cout << node << endl;      
        
    }
    

}