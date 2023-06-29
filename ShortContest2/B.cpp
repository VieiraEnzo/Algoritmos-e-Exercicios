#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    string model = "codeforces";
    int t;
    cin >> t;
    for(int i =0; i < t; i++){
        int erro = 0;
        cin >> s;
        for(int i =0; i < 10; i++){
            if(model[i] != s[i]){erro ++;}
        }
        cout << erro << endl;
    }
}
