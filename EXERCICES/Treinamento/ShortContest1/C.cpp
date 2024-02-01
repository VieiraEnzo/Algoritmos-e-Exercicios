#include <bits/stdc++.h>
using namespace std;

int main(){
    string number;
    cin >> number;

    bool first = true;
    for(int i=0; i <number.size(); i++){
        if(number[i] == '0' && first){
            first = false;
            continue;
        }
        else if(i == number.size() - 1 && first){
            break;
        }
        else{
            cout << number[i];
        }
    }

}
