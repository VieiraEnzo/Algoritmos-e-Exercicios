#include <bits/stdc++.h>
#include <vector>
using namespace std;


int main(){
    int n,t;
    string nome_temp;
    pair <int,int> code_temp;
    cin >> n;
    map <pair<int,int>,string> codigos;
    for(int i =0; i < n; i ++){
        cin >> code_temp.first;
        cin >> code_temp.second;
        cin >> nome_temp;
        codigos[code_temp] = nome_temp;
    }
    cin >> t;
    for(int i =0; i < t; i ++){
        cin >> code_temp.first;
        cin >> code_temp.second;
        cout << codigos[code_temp] << endl;
    }
}
