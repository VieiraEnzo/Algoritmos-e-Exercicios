#include <bits/stdc++.h>

using namespace std;

#ifdef local
    #include "/home/enzo/Documents/Prog/OBItraining/debug.h"
    #define pr(...) debug(#__VA_ARGS__, __VA_ARGS__)
    #define prs(...) debug_nameless(__VA_ARGS__)
#else
    #define pr(...) 69
    #define prs(...) 69
#endif

#define endl "\n"
#define int long long
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

struct SegTree{ //segtree 0 indexada sem lazy
  int n;
  struct Node{
    int val;
    Node operator+(Node other) const{
      return {__gcd(this->val,other.val)};
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

  int query(int l, int r, int x){
    return query(1, 0, n-1, l, r, x);
  }

  int query(int v, int tl, int tr, int l, int r, int x){
    pr(l, r, tl, tr,  t[v].val);
    if (l > r) 
      return 0;
    if (l == tl && r == tr) {
      if(t[v].val == x) return 0;
      else if(__gcd(t[v].val , x)  == x) { return 1;}
      // se não dividir os intervalos
    }
    int tm = (tl + tr) / 2;
    return query(v*2, tl, tm, l, min(r, tm), x)
      + query(v*2+1, tm+1, tr, max(l, tm+1), r, x);
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

signed main(){
    fastio;
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    SegTree seg(a);

    int q; cin >> q;
    while (q--)
    {
        int type; cin >> type;
        if(type == 1){
            int l, r, x; cin >> l >> r >> x;
            l--;r--;
            pr(l,r ,x);
            int resp = seg.query(l,r,x);
            if(resp == 0 || resp == 1) cout << "YES\n";
            else cout << "NO\n";
        }else{
          int i, y; cin >> i >> y;
          i--;
          seg.update(i,y);
        }
    }
    
    
}