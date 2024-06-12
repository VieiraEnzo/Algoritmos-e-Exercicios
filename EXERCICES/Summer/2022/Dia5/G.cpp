#include <bits/stdc++.h>
using namespace std;

int main(){
    
    cin.tie(nullptr), ios_base::sync_with_stdio(0);
    
    int l;

    while (cin >> l)
    {
    
        int c; cin >> c;
        int linhaDo1 =-1, colunaDo1 = -1;
        vector<vector<int>> v(l, vector<int> (c));

        bool possible = true;
        for(int i = 0; i < l; i++)
            for(int j = 0; j < c; j++){
                cin >> v[i][j];
                if(v[i][j] == 1){linhaDo1 = i, colunaDo1 = j;}
        }
        //check if lines are coherent

        for(int i =0; i < l; i++){
            for(int j = 0; j < c; j++){
                
            }
        }

        //manor manor numero de passor para reorganizar numeros
        if(!possible){cout << '*' << "\n"; continue;}

        int ans = 0;
        if(c > 1)
            for(int i = 0; i < c; i++){
                if(v[linhaDo1][i] != i + 1) {
                    swap(v[linhaDo1][i], v[linhaDo1][v[linhaDo1][i]-1]);
                    ans++;
                }
                if(v[linhaDo1][i] != i + 1){i--;}
            }

        // for(int i = 0; i< c; i++){cout << v[linhaDo1][i] << " ";}
        // cout << "\n";

        if(l > 1)
            for(int i = 0; i < l; i++){
                if(v[i][colunaDo1] != c*i + 1){
                    swap(v[i][colunaDo1], v[(v[i][colunaDo1]-1)/c][colunaDo1]);
                    ans++;
                }
                if(v[i][colunaDo1] != c*i + 1){i--;}
            }

        cout << ans << "\n";
    }

}