#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"

#include <bits/stdc++.h>
using namespace std;

#define int long long

#include "../../Algoritmos/DataStructures/SegTree.h"


signed main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    SegTree st(a);
    while (q--) {
        int t;
        cin >> t;
        if (t == 0) {
            int c, d;
            cin >> c >> d;
            st.update(c, a[c]+d);
            a[c] += d;
        } else {
            int l, r; cin >> l >> r;
            cout << st.query(l,r-1).val << '\n';
        }
    }
    return 0;
}
