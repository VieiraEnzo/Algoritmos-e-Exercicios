#include <bits/stdc++.h>
using namespace std;
int h, l, chamados, cor;
int maxh = 205;
int maxl = 205;
vector<vector<int>> grid(maxh, vector<int> (maxl));
vector<vector<int>> marc(maxh, vector<int> (maxl));

void dfs(int i, int j){
    // cout << i << " " << j << endl;
    marc[i][j] = 1;
    chamados++;
    if(i+1 < h && grid[i][j] == grid[i+1][j] && !marc[i+1][j]){ dfs(i+1,j);}
    if(j+1 < l && grid[i][j] == grid[i][j+1] && !marc[i][j+1]){ dfs(i,j+1);}
    if(i-1 >= 0 && grid[i][j] == grid[i-1][j] && !marc[i-1][j]){ dfs(i-1,j);}
    if(j-1 >= 0 && grid[i][j] == grid[i][j-1] && !marc[i][j-1]){ dfs(i,j-1);}

}



int main(){

     cin >> h >> l;


    for(int i = 0; i < h; i++){
        for(int j = 0; j < l; j++){
            cin >> grid[i][j];
        }
    }

    int minT = 1e9;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < l; j++){
            if(!marc[i][j]){
                chamados = 0;
                dfs(i,j);
                // cout << chamados << endl;
                minT = min(minT, chamados);
            }
            
        }
    }

    cout << minT << endl;
}