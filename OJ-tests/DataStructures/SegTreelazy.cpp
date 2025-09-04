#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_E"

#include <bits/stdc++.h>
using namespace std;

#define int long long

#include "../../Algoritmos/DataStructures/LazySegTree.h"


signed main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    int n, q;
    cin >> n >> q;
    vector<int> a(n+1);
    SegTree st(a);

    while (q--) {
        int t;
        cin >> t;
        if (t == 0) {
            int a,b,u;
            cin >> a >> b >> u;
            st.RangeUpdate(a,b,u);
        } else {
            int k; cin >> k;
            cout << st.query(k,k).val << '\n';
        }
    }
    return 0;
}
