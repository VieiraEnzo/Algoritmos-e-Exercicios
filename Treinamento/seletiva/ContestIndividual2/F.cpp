#include <bits/stdc++.h>
typedef long long ll;
using namespace std;


int main(){
    int H, W; cin >> H >> W;
    vector<string> v(H);
    for(int i =0; i < H; i++) cin >> v[i];
    bool visited[H][W];
    for(int i=0; i< H; i++)
        for(int j=0; j< W; j++)
            visited[i][j] = false;
    queue<pair<int,int>> fila;
    map<char,char> snuke;
    snuke['s'] = 'n';
    snuke['n'] = 'u';
    snuke['u'] = 'k';
    snuke['k'] = 'e';
    snuke['e'] = 's';
    fila.push(make_pair(0,0));


    while (!fila.empty())
    {      
        int x = fila.front().first;
        int y = fila.front().second;
        fila.pop();

        if(x == H-1 && y == W-1){cout << "Yes"; return 0;}
        

        if(x+1 < H &&v[x+1][y] == snuke[v[x][y]] && !visited[x+1][y]){
            fila.push(make_pair(x+1,y));
            visited[x+1][y] = true;
        }

        if(y+1 < W && v[x][y+1] == snuke[v[x][y]] && !visited[x][y+1]){
            fila.push(make_pair(x,y+1));
            visited[x][y+1] = true;
        }

        if(x-1 >= 0 && v[x-1][y] == snuke[v[x][y]] && !visited[x-1][y]){
            fila.push(make_pair(x-1,y));
            visited[x-1][y] = true;
        }

        if(y-1 >= 0 && v[x][y-1] == snuke[v[x][y]] && !visited[x][y-1]){
            fila.push(make_pair(x,y-1));
            visited[x][y-1] = true;
        }
    }
    cout << "No";
}
    