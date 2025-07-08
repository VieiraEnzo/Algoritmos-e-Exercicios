#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"

#include <bits/stdc++.h>
using namespace std;

#include "../../Algoritmos/DataStructures/DSU.h"

int main(){

    cin.tie(0);
    ios_base::sync_with_stdio(false);


    int n; cin >> n;
    int q; cin >> q;

    DSU dsu(n);

    while(q--){
        int t; cin >> t;
        int a,b; cin >> a >> b;
        if(t == 0){
            dsu.uu(a,b);
        }else{
            cout << (dsu.find(a) == dsu.find(b)) << "\n";
        }
    }
}