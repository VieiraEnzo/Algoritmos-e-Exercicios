#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"
#include <bits/stdc++.h>
using namespace std;
#define int long long
#include "../../Algoritmos/DataStructures/BIT.h"

signed main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);


    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    FenwickTree bit(a);
    while (q--) {
        int t, x, y;
        cin >> t >> x >> y;
        if (t == 0) bit.add(x, y);
        else cout << bit.sum(x, y - 1) << '\n';
    }
    return 0;
}
