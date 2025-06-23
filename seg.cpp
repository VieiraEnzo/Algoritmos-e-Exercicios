#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct SegTree{ //segtree 0 indexada sem lazy
  int n;
  struct Node{
    ll val;
    Node operator+(Node other) const{
        return {this->val + other.val};
    }
    Node operator=(int x){
      return {this->val = x};
    }
  };
  Node neutral = {0};
  vector <Node> t;

  SegTree(vector <int> a){
    n = a.size();
    t.resize(4*n);
    build(a, 1, 0, n-1);
  }

  void build(vector <int>& a, int v, int tl, int tr) {
    if (tl == tr) {
      t[v] = a[tl];
    } else {
      int tm = (tl + tr) / 2;
      build(a, v*2, tl, tm);
      build(a, v*2+1, tm+1, tr);
      t[v] = t[v*2] + t[v*2+1];
    }
  }

  int query(int k){
    return query(1, 0, n-1, k);
  }

  int query(int v, int tl, int tr, int k){
    if(tl == tr){
        return tl;
    }
    int tm = (tl + tr) / 2;
    if(t[v*2].val >= k){
        return query(v*2, tl, tm, k);
    }else{
        return query(v*2 + 1, tm+1, tr, t[v*2].val - k);
    }
  }

  void update(int pos, int val){
    update(1, 0, n-1, pos, val);
  }

  void update(int v, int tl, int tr, int pos, int new_val){
    if (tl == tr) {
      t[v] = new_val;
    } else {
      int tm = (tl + tr) / 2;
      if (pos <= tm)
        update(v*2, tl, tm, pos, new_val);
      else
        update(v*2+1, tm+1, tr, pos, new_val);
      t[v] = t[v*2] + t[v*2+1];
    }
  }
};


void solve(){

    int n, m; cin >> n >> m;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    SegTree seg(a);

    while(m--){ 
        int t; cin >> t;
        if(t == 1){
            int i; cin >> i;
            a[i] = !a[i];
            seg.update(i, a[i]);
        }else{
            int k; cin >> k;
            cout << seg.query(k+1) << "\n";
        }
    }

}   

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t; t = 1;
    while (t--)
    {
        solve();
    }
}

