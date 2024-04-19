#include <bits/stdc++.h>
using namespace std;

int maxn = 1e6 + 5;
vector<int> color(maxn);
vector<int> grafo(maxn);
vector<int> novo;


void dfs(int v, int c){
    color[v] = -c;
    if(color[grafo[v]] == 0) dfs(grafo[v], -c);
}

int main(){
    int n; cin >> n;
    vector<int> in(n+1);
    vector<pair<int,int>> fila;
    for(int i = 1; i <= n; i++){
        int a; cin >> a;
        grafo[i] = a;
        in[a]++;
    }


}