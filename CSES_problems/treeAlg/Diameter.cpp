#include <bits/stdc++.h>
using namespace std;
int maxn = 2e5 + 7;
vector<vector<int>> graph(maxn);
vector<int> height(maxn);
vector<int> marc(maxn);

int bfs(int vert){

    int MaxCara = vert;
    queue<int> fila;
    fila.push(vert);
    height[vert] = 0;
    marc[vert] = 1;

    while (!fila.empty())
    {
        int v = fila.front();
        marc[v] = 1;
        MaxCara = v;
        fila.pop();

        for(auto viz : graph[v]){
            if(marc[viz]) continue;
            fila.push(viz);
            height[viz] = height[v] + 1;
        }

    }
    
    return MaxCara;
}




int main(){
    int n; cin >> n;

    for(int  i =0; i < n-1 ; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int i = bfs(1);

    fill(marc.begin(), marc.end(), 0);
    fill(height.begin(), height.end(), 0);

    int v = bfs(i);

    cout << height[v] << endl;
}   