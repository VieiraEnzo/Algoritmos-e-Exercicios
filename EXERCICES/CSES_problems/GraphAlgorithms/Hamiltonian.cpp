#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> grafo(23);
vector<int> vis(23);
int cc = 0;
int ans = 0;
int n;


void dfs(int v){
    vis[v] = 1;
    cc++;
    if(v == n){
        if(cc == n){
            ans++;
        }else{
            vis[v] = 0;
            cc--;
            return;
        }
    }
    for(auto a : grafo[v]){
        if(!vis[a]) 
            dfs(a);
    }
    vis[v] = 0;
    cc--;
}


int main(){
    int m; cin >> n >> m;

    for(int i = 0; i < m; i++){
        int a,b; cin >> a >> b;
        grafo[a].push_back(b);
    }

    dfs(1);

    cout << ans << endl;
}