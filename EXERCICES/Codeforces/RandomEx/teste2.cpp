#include <bits/stdc++.h>
using namespace std;

int ans = 0;
vector<int> Dprinc(100);
vector<int> Dsec(100);
vector<int> Coluna(100);
char mat[8][8];

int socorro(int c){
    if(c < 0) return 50 + (-c);
    return c;
}

void explore(int h){
    // cout << h << "\n";
    if(h == 8) {ans++; return;}    
    for(int i = 0; i < 8; i++){
        if(!Dprinc[socorro(i-h)] && !Dsec[i+h] && !Coluna[i] && (mat[h][i] != '*')){
            Dprinc[socorro(i-h)] = Dsec[i+h] = Coluna[i] = 1;
            // cout << "rainha pos: " << h << " " << i << "\n";
            explore(h+1);
            Dprinc[socorro(i-h)] = Dsec[i+h] = Coluna[i] = 0;
        }
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for(int i = 0; i < 8; i++)
        for(int j = 0; j < 8; j++)
            cin >> mat[i][j];

    explore(0);

    cout << ans << "\n";
}