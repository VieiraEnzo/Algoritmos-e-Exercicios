#include <bits/stdc++.h>

using namespace std;
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

bool solved = false;
int h, w;


struct Ponto{
    int i,j;
};

Ponto S,T;
vector<pii> dir = {{1,0}, {-1,0}, {0,1}, {0,-1}};


void bfs(vector<vector<char>> &mat, vector<vector<int>> &bonus){

    queue<Ponto> fila;
    fila.push(S);

}



int main(){
    fastio;
    cin >> h >> w;
    vector mat(h, vector<char> (w));
    vector bonus(h, vector<int> (w));

    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >>  mat[i][j];
            if(mat[i][j] == 'S'){S.i = i; S.j = j;}
            else if(mat[i][j] == 'T'){T.i = i; T.j = j;}
        }
    }

    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int r, c, e; cin >> r >> c >> e;
        bonus[r-1][c-1] = e;
    }

    bfs(mat, bonus);

    if(solved){
        cout << "Yes" << "\n";
    }else{
        cout << "No" << "\n";
    }

}