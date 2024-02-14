#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;

void solve(){

    int n, k; cin >> n >> k;

    bool solvable = true;
    vector<vector<int>> g(n+1);
    vector<int> grau(n+1, 0);
    
    vector<int> v(n);
    for(int i = 0; i < k; i++){
        for(int j = 0; j < n; j++)cin >> v[j];
        for(int j = 1; j < n-1; j++){
            g[v[j]].push_back(v[j+1]);
            grau[v[j+1]]++;
        }
    }

    //if(k == 1){cout << "YES" << endl; return;}

    //for(auto a : grau) cout << a << " ";
    //cout << endl;

    queue<int> fila;
    vector<int> vis(n+1);

    for(int i = 1; i <= n; i++){
        if(!grau[i]) {
            fila.push(i);
            vis[i] = 1;
            //cout << i << " ";
            }
    }//cout << endl;

    while (!fila.empty())
    {   
        int u = fila.front();
        fila.pop();

        for(auto a : g[u]){
            grau[a]--;
            if(!grau[a] && !vis[a]){
                fila.push(a);
                vis[a] = 1;
            }
        }
    }
    
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            solvable = false;
            //cout << "a" << endl;
        }
    }

    if(solvable || k == 1) cout << "YES" << endl;
    else cout << "NO" << endl;
}


int main(){
    
    fastio;

    int t; cin >> t;
    while (t--)
    {
        solve();
    }

}