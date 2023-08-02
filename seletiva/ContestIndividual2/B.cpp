#include <bits/stdc++.h>
typedef long long ll;
using namespace std;


int main(){
    map<char,int> dist;
    dist['A'] = 3;
    dist['B'] = 1;
    dist['C'] = 4;
    dist['D'] = 1;
    dist['E'] = 5;
    dist['F'] = 9;
    char p,q; cin >> p >> q;
    if(p > q) swap(p,q);
    int total = 0;
    for(char i = p; i < q; i++){
        total += dist[i];
    }
    cout << total;
}
    