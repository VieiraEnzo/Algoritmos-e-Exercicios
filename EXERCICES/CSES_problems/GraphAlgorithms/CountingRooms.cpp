#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
vector<string> v;
int n,m; 

void bfs(int i,int j, vector<vector<int>> &visited){
    queue<pair<int,int>> fila;
    fila.push(make_pair(i,j));
    visited[i][j] = 1;

    while (!fila.empty())
    {
        int x = fila.front().first;
        int y = fila.front().second;
        fila.pop();
        if(x+1 < n && v[x+1][y] == '.' && !visited[x+1][y]){
            fila.push(make_pair(x+1,y));
            visited[x+1][y] = 1;
        }
        if(x-1>=0 && v[x-1][y] == '.' && !visited[x-1][y]){
            fila.push(make_pair(x-1,y));
            visited[x-1][y] = 1;
        }
        if(y+1 < m && v[x][y+1] == '.' && !visited[x][y+1]){
            fila.push(make_pair(x,y+1));
            visited[x][y+1] = 1;
        }
        if(y-1 >= 0 &&v[x][y-1] == '.' && !visited[x][y-1]){
            fila.push(make_pair(x,y-1));
            visited[x][y-1] = 1;
        }
    }
    
}   



int main(){
    fastio;
    cin >> n >> m;
    v.resize(n);
    for(int i=0; i< n; i ++) cin >> v[i];
    vector<vector<int>> visited(n);
    for(int i=0; i <n; i ++)visited[i].resize(m);
    for(int i=0; i < n; i ++){
        for(int j=0; j < m; j ++){
            if(v[i][j] == '#'){
                visited[i][j] = 1;
            }
            else{
                visited[i][j] = 0;
            }
        }
    }
    int c =0;
    for(int i=0; i < n; i ++){
        for(int j=0; j < m; j ++){
            if(!visited[i][j]){
                c++;
                bfs(i,j, visited);
            }
        }
    }
    cout << c;
}