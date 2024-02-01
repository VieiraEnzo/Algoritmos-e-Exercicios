#include <bits/stdc++.h>
typedef long long ll;
using namespace std;


int main(){
    vector<int> num(8);
    for(int i =0; i < 8; i++) cin >> num[i];
    bool monotonically = true, betwen = true,multiple = true;
    for(int i=0; i < 7; i++){
        if(num[i] > num[i+1]) monotonically = false;
    }
    for(int i=0; i < 8; i++){
        if(num[i] < 100 || num[i] > 675) betwen =false;
        if(num[i] % 25 != 0 )multiple =false; 
    }
    if(betwen && monotonically && multiple) cout << "Yes";
    else cout << "No";
}
    