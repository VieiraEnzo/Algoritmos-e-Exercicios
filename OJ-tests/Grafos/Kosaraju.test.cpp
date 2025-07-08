#define PROBLEM "https://judge.yosupo.jp/problem/scc"
#include <bits/stdc++.h>
using namespace std;
#include "../../Algoritmos/Grafos/Kosaraju.h"

int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    Kosa kosa(n);

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        a++;b++;
        kosa.add_edge(a,b);
    }

    kosa.build();

    int ans = kosa.cont;
    vector<vector<int>> g(ans+1);

    cout << ans << "\n";
    for(int i = 1; i <= n; i++){
        g[kosa.comp[i]].push_back(i);
    }

    for(int i = 1; i <= ans; i++){
        cout << g[i].size() << " ";
        for(auto a : g[i]) cout << a-1 << " ";
        cout << "\n";
    }

    return 0;
}
