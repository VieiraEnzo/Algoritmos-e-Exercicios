#include <bits/stdc++.h>
using namespace std;

int main(){
    int R,C;
    cin >> R >> C;
    char matriz[R][C];
    for(int i = 0; i< R; i++){
        for(int j =0; j < C;j++){
            cin >> matriz[i][j];
        }   
    }

    for(int i = 0; i< R; i++){
        for(int j =0; j < C;j++){
            if(matriz[i][j] - '0' <= 9 && matriz[i][j] - '0' >= 0){
                for(int k = 0; k< R; k++){
                    for(int l =0; l < C;l++){
                        if(i != k && j != l){
                            if(matriz[i][j] - '0' >= abs(float(i-j)) + abs(float(k-l)));{
                                matriz[k][l] = '.';
                            }
                        }
                    }   
                }
                matriz[i][j] = '.';
            }
            
        }   
    }

    for(int i = 0; i< R; i++){
        for(int j =0; j < C;j++){
            cout <<  matriz[i][j];
        }
        cout << endl;
    }
}
