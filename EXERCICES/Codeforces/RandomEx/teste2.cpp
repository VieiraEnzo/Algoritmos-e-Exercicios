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

  Node query(int l, int r){
    return query(1, 0, n-1, l, r);
  }

  Node query(int v, int tl, int tr, int l, int r){
    if (l > r) 
      return neutral;
    if (l == tl && r == tr) {
      return t[v];
    }
    int tm = (tl + tr) / 2;
    return query(v*2, tl, tm, l, min(r, tm))
      + query(v*2+1, tm+1, tr, max(l, tm+1), r);
  }

  int query(int l, int r, int x){
    return query(1, 0, n-1, l, r, x);
  }

int query(int v, int tl, int tr, int l, int r, int x){
    // cout << tl << " " << tr << "\n";

    if (l > r) 
        return 1e9;
    
    if(tl == tr){
        if(t[v].val % x == 0) return 1e9;
        else return l;
    }

    if (l == tl && r == tr) {
        if(t[v].val % x == 0) return 1e9;
        int tm = (tl + tr) / 2;
        if(t[2*v].val % x == 0) return query(v*2 + 1, tm+1, tr, max(l, tm+1), r, x);
        else return query(v*2, tl, tm, l, min(r, tm), x);
    }
    
    int tm = (tl + tr) / 2;
    return min(query(v*2 + 1, tm+1, tr, max(l, tm+1 ), r, x), query(v*2, tl, tm, l, min(r, tm), x));
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

int main(){
    fastio;
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    SegTree seg(a);

    int q; cin >> q;
    for(int i = 0; i < q; i ++)
    {
        int type; cin >> type;
        if(type == 1){
            int a, b, x; cin >> a >> b >> x;
            a--, b--;
            if(seg.query(a,b).val % x == 0) {cout << "YES\n"; continue;}
            int up = seg.query(a,b,x);
            int up2 = seg.query(up + 1, b, x);
            if(up2 == 1e9) cout << "YES\n";
            else cout << "NO\n";

        }else{

          int i, y; cin >> i >> y;
          i--;
          seg.update(i,y);  
        }
    }
    
    
}