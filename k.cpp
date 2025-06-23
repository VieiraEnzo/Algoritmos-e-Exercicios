#include<bits/stdc++.h>

using namespace std;

int n, q;
char m[55][55], nx[55][55];

int viz(int i, int j){
    int res = 0;
    if(i-1 >= 0 and j-1 >= 0) res += m[i-1][j-1] - '0';
    if(i-1 >= 0 and j >= 0) res += m[i-1][j] - '0';
    if(i-1 >= 0 and j+1 < n) res += m[i-1][j+1] - '0';
    if(i >= 0 and j-1 >= 0) res += m[i][j-1] - '0';
    if(i >= 0 and j+1 < n) res += m[i][j+1] - '0';
    if(i+1 < n and j-1 >= 0) res += m[i+1][j-1] - '0';
    if(i+1 < n and j >= 0) res += m[i+1][j] - '0';
    if(i+1 < n and j+1 < n) res += m[i+1][j+1] - '0';
    return res;
}
int main(){
    cin >> n >> q;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            cin >> m[i][j];
        }
    }
    for(int a = 0;a < q;a++){
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                int vizinhos = viz(i, j);
                if(m[i][j] == '0'){
                    if(vizinhos == 3){
                        nx[i][j] = '1';
                    }
                    else nx[i][j] = '0';
                }
                else{
                    if(vizinhos == 2 or vizinhos == 3){
                        nx[i][j] = '1';
                    }
                    else nx[i][j] = '0';
                }
            }
        }
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                m[i][j] = nx[i][j];
            }
        }
    }
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            cout << m[i][j];
        }
        cout << '\n';
    }
}