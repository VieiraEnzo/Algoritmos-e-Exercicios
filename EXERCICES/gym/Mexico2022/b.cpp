#include <bits/stdc++.h>
using namespace std;

int maxn = 1e5 + 7;
vector<vector<int>> grafo(maxn);
vector<vector<int>> marc(maxn, vector<int> (100));
vector<int> ans;
set<int> pq;

void bfs(int v){

    queue<pair<int,int>> fila;
    fila.push({v, 0});
    ans.push_back(v);

    while (!fila.empty())
    {
        auto p = fila.front();
        fila.pop();
        for(auto viz : grafo[p.first]){
            int dist = p.second + 1;
            if(!marc[viz][dist]){
                fila.push({viz, dist});
                marc[viz][dist] = 1;
            }
        }
    }
    

}

int main(){
    int n, k; cin >> n >> k;
    for(int i = 0; i < n ;i++)
    {   int a, b; cin >> a >> b;
        grafo[a].push_back(b); 
        grafo[b].push_back(a);
    }

    vector<int> ans;

    search();

}