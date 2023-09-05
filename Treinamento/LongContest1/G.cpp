#include <bits/stdc++.h>
using namespace std;

int main(){
    string number;
    cin >> number;
    int s = 0;
    for(int i =0; i< number.size(); i++){
        s += number[i] - '0';
    }
    if(!(s%9)){
            cout << "Yes";
        }
        else{
            cout << "No";
        }
}
