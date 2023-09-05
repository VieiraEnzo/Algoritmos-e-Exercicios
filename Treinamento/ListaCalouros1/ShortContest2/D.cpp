#include <bits/stdc++.h>
using namespace std;

int main(){
    int X, Y;
    cin >> X >> Y;
    if((4*X - Y) % 2 == 0 && (Y - 2*X)%2 == 0 && (4*X - Y)/2 >= 0 && (Y - 2*X)/2 >= 0){
        printf("Yes");
    }
    else{
        printf("No");
    }
}