#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;
const ll inf = 1e18;
const int maxn = 501;
vector<vector<ll>> d(maxn, vector<ll>(maxn, inf));

void floydWarshall( ){

    for(int i = 0; i < maxn; i++)d[i][i] = 0;

    for(int k = 1; k < maxn; k++)
        for(int i = 1; i < maxn; i++)
            for(int j = 1; j < maxn; j++){
                if(d[i][k] < inf && d[k][j] < inf)
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        
}


int main(){
    fastio;
    int n, m, q; cin >> n >> m >> q;

    for(int i = 0; i < m; i++){
        ll a, b, c; cin >> a >> b >> c;
        d[a][b] = min(d[a][b], c);
        d[b][a] = d[a][b];
    }   

    floydWarshall();

    while (q--)
    {
        int a, b; cin >> a >> b;
        if(d[a][b] == inf) {cout << -1 << endl; continue;}
        cout << d[a][b] << endl;
    }
    
    
    

}