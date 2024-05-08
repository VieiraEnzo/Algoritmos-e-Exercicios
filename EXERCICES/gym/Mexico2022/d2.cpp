#include <bits/stdc++.h>
using namespace std;

struct Matriz{

    int D;
    int MOD = 1e9 + 7;
    vector<vector<int>> mat;

    Matriz(int D): D(D), mat(D, vector<int> (D)) {}
    
    vector<int>& operator[](int i){
        return mat[i];
    }
    Matriz operator*(Matriz oth){
        Matriz res(D);
        for(int i = 0; i < D; i++){
            for(int j = 0; j < D;j ++){
                res[i][j] = 0;
                for(int k = 0; k < D; k++)
                    res[i][j] = (res[i][j] + (mat[i][k] *1ll *oth[k][j])%MOD)%MOD; 
            }
        }
        return res;
    }

    Matriz exp(long long e){
        Matriz res(D);
        for(int i = 0; i < D; i++)
            for(int j= 0; j < D; j++)
                res[i][j] = (i == j);
        
        Matriz base = *this;
        while (e > 0)
        {
            if(e & 1ll)
                res= res* base;
            base = base*base;
            e = e>>1;
        }
        return res;
    }
};


int main(){

    cin.tie(0), ios_base::sync_with_stdio(0);

    int n, m, k; cin >> n >> m >> k;
    
    Matriz grafo(n);

    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        grafo[a-1][b-1] = 1;
        grafo[b-1][a-1] = 1;
    }

    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < n; j++){
    //         cout << grafo[i][j] << " ";
    //     }
    //     cout << endl;
    //     }

    Matriz resp = grafo.exp(k);

    int ans = 0;
    for(int i = 0; i < n; i++){
        ans += resp[0][i];
        ans %= (int)1e9+7;
    }

    cout << ans << endl;

}