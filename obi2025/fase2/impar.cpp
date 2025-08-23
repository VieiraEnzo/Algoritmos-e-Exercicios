#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0), ios_base::sync_with_stdio(false);

    //impar -> par
    //par -> impar

    int n,m; cin >> n >> m;
    vector<vector<int>> mat(n, vector<int> (m));

    int t1 = 0, t2 = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> mat[i][j];
            if((i+j)%2){
                if(mat[i][j]%2)t2++;
                else t1++; 
            }else{
                if(mat[i][j]%2)t1++;
                else t2++;
            }
        }
    }

    cout << min(t1,t2) << "\n";

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(t2<t1 && (i+j)%2 && mat[i][j]%2) mat[i][j]++;
            if(t1<t2 && (i+j)%2 && mat[i][j]%2 == 0) mat[i][j]++;
            if(t2 < t1 && (i+j)%2 == 0 && mat[i][j]%2 == 0) mat[i][j]++;
            if(t1 < t2 && (i+j)%2 == 0 && mat[i][j]%2) mat[i][j]++;
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << mat[i][j] << " ";
        }cout << "\n";
    }


}   
