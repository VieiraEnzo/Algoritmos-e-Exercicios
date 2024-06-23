#include <bits/stdc++.h>

using namespace std;

#ifdef local
    #include "/home/enzo/Documents/Prog/OBItraining/debug.h"
    #define pr(...) debug(#__VA_ARGS__, __VA_ARGS__)
    #define prs(...) debug_nameless(__VA_ARGS__)
#else
    #define pr(...) 69
    #define prs(...) 69
#endif


#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

void solve(){
    int n, m; cin >> n >> m;

    vector<vector<int>> mat(n+2, vector<int> (m+2));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> mat[i][j];
        }
    }

    vector<pair<int,int>> dir = {{1,0}, {0,1}, {-1,0}, {0,-1}};

    bool att = false;    
    do{
        att = false;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                bool maior = true;
                int maior_viz = -1e9;
                for(auto d : dir){
                    if(mat[i][j] <= mat[i + d.first][j + d.second]) maior = false;
                    maior_viz = max(maior_viz, mat[i + d.first][j + d.second]);
                }
                if(maior){
                    att = true;
                    mat[i][j] -= (mat[i][j] - maior_viz);
                }
            }
        }
    }while(att);


    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cout << mat[i][j] << " ";
        }
        cout << "\n";
    }

}

signed main(){
    fastio;
    int t; cin >> t;
    while (t--) solve();
}