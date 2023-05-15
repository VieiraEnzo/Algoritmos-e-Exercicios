#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main(){
    int n;
    int input;
    cin >>n;
    int friends[n];

    for(int i=0;i<n;i++){
        cin >> input;
        friends[input - 1] = i;
    }

    for(int i=0;i<n;i++){
        cout << friends[i] + 1 << ' ';
    }
    
}
