#include <bits/stdc++.h>
using namespace std;

int main(){
    int H,W;
    cin >> H >> W;
    int matriz[H][W];
    //load the matrix
    for(int i = 0; i< H; i++){
        for(int j =0; j < W;j++){
            cin >> matriz[i][j];
        }   
    }

    //print the matrix
    for(int i = 0; i< H; i++){
        for(int j =0; j < W;j++){
            if (matriz[i][j] == 0){cout << '.';}
            else{cout <<  (char)(matriz[i][j] -1 + 'A');}
        }
        cout << endl;
    }
}
