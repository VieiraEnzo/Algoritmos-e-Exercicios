#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;
#define fact_9 362880

int fact(int n){
    int mult =1 ;
    for(int i =2; i <= n; i++){
        mult *= i;
    }
    return mult;
}


int main(){
    fastio;
    int square[3][3];
    for(int i =0; i < 3; i++){
        for(int j =0; j < 3; j++){
            cin >> square[i][j];
        }
    }

    int dis = 0;
    for(int i =0; i < 3; i++){
        for(int j =0; j < 3; j++){
            int main = square[i][j];
            if(i+1 < 3 && square[i+1][j] == main){
                dis++;
            }
            if(i-1 >= 0 &&square[i-1][j] == main){
                dis++;
            }
            if(j+1 < 3&&square[i][j+1] == main){
                dis++;
            }
            if(j-1 >= 0 && square[i][j-1] == main){
                dis++;
            }
            
        }   
    }
    if(square[0][0] == square[1][1] || square[1][1] == square[2][2]){
        dis++;
    }
    if(square[0][2] == square[1][1] || square[1][1] == square[2][0]){
        dis++;
    }
    double num_dupl = dis/2;
    double result = pow(((double)2/(double)3), num_dupl);
    cout << result << endl;
    cout << dis;
}