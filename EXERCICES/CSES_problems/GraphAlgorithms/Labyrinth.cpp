#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;

vector<vector<char>> v, visited;
int n, m;

vector<char> ans;

void dfs(int i, int j){
    visited[i][j] = 1;
    
}


int main(){
    fastio;
    cin >> n >> m;
    v.resize(n);
    visited.resize(n);

    int iA, jA, iB, jB;
    for(int i = 0; i < n; i++){
        v.resize(m);
        visited.resize(m);
        for(int j = 0; j < m; j++){
            cin >> v[i][j];
            if(v[i][j] == 'A'){
                iA = i, jA = j;
            }else if(v[i][j] == 'B'){
                iB = i, jB = j;
            }
        }
    }

    dfs(iA,jA);

}