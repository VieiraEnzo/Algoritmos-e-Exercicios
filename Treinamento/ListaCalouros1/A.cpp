#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)

int main(){
    int l,y; cin >> l >> y;
    bool pts4 = false, pts2 = false, pts1 = false;
    if(l >= 4){
        l-=4;
        pts4 = true;
    }
    if(y >= 4){
        y-=4;
        pts4 = true;
    }
    if(l >= 2){
        l-=2;
        pts2 = true;
    }
    if(y >= 2){
        y-=2;
        pts2= true;
    }
    if(l >= 1){
        l-=1;
        pts1 = true;
    }
    if(y >= 1){
        y-=1;
        pts1= true;
    }
    int pontPaul =0;
    if(pts1){
        pontPaul += 1;
    }
    if(pts2){
        pontPaul += 2;
    }
    if(pts4){
        pontPaul += 4;
    }
    cout << pontPaul;


}