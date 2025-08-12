#define PROBLEM "https://judge.yosupo.jp/problem/rectangle_sum"
#include <bits/stdc++.h>
using namespace std;
#define int long long
#include "../../Algoritmos/DataStructures/Pref2D.h"

signed main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);


    int n, q;
    cin >> n >> q;
    
    vector<vector<int>> a(n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int x,y; cin >> x >> y;
            cin >> a[x][y];
        }
    }

    pref2D p(n,n,a);

    while (q--) {
        int l,d,r,u; cin >> l >> d >> r >> u;
        cout << p.query(l,d,r,u) << "\n";
    }
    return 0;
}
