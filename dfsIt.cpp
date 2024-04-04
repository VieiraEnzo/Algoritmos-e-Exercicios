#include <bits/stdc++.h>
using namespace std;


int main(){

    int n, m; cin >> n >> m;
    vector<vector<int>> grafo(n+1);
    vector<bool> vis(n+1);

    for(int i = 0; i < m; i++){
        int a,b; cin >> a >> b;
        grafo[a].push_back(b);
        grafo[b].push_back(a);
    }

    stack<int> pilha;
    pilha.push(3);

    while (!pilha.empty())
    {
        int v = pilha.top();
        pilha.top();

        if(!vis[v]){

            vis[v] = true;

            for(int next : grafo[v]){
                if(vis[next]) continue;
                pilha.push(next);
            }

        }
    }
    


}