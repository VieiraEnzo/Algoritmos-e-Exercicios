//SegTree c/ Lazy

struct SegTree{ 
  int n;
  struct Node{
    int val;
    Node operator+(Node other) const{
      return {this->val + other.val};
    }
    Node operator=(int x){
      return {this->val = x};
    }
  };
  Node neutral = {0};
  vector <Node> t;
  vector<int> lazy;

  SegTree(vector <int> a){
    n = a.size();
    t.resize(4*n);
    lazy.resize(4*n);
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

  void unlazy(int v, int tl, int tr){
    if(lazy[v] == 0) return;

    //Update current range
    t[v].val += (tr-tl+1) * lazy[v]; 

    //Pass lazy to child if any
    if(tl != tr){
        lazy[2*v] += lazy[v];   
        lazy[2*v+1] += lazy[v]; 
    }
    
    //Reset lazy
    lazy[v] = 0; 
  }

  Node query(int l, int r){
    return query(1, 0, n-1, l, r);
  }

  Node query(int v, int tl, int tr, int l, int r){
    unlazy(v, tl, tr);
    if (l > r) 
      return neutral;
    if (l == tl && r == tr) {
      return t[v];
    }
    int tm = (tl + tr) / 2;
    return query(v*2, tl, tm, l, min(r, tm))
      + query(v*2+1, tm+1, tr, max(l, tm+1), r);
  }

  void RangeUpdate(int l, int r, int new_val){
    RangeUpdate(1,0,n-1,l,r,new_val);
  }

  void RangeUpdate(int v, int tl, int tr, int l, int r, int new_val){
    unlazy(v, tl, tr);
    if (l > r) 
      return;
    if (l == tl && r == tr) {
        lazy[v] += new_val; //Change here
        unlazy(v, tl, tr);
        return;
    }
    int tm = (tl + tr) / 2;
    RangeUpdate(v*2, tl, tm, l, min(r, tm), new_val);
    RangeUpdate(v*2+1, tm+1, tr, max(l, tm+1), r, new_val);
    t[v] = t[2*v] + t[2*v+1];
  }

  void PointUpdate(int pos, int val){
    PointUpdate(1, 0, n-1, pos, val);
  }

  void PointUpdate(int v, int tl, int tr, int pos, int new_val){
    unlazy(v, tl, tr);
    if (tl == tr) {
      t[v] = new_val;
    } else {
      int tm = (tl + tr) / 2;
      if (pos <= tm)
        PointUpdate(v*2, tl, tm, pos, new_val);
      else
        PointUpdate(v*2+1, tm+1, tr, pos, new_val);
      t[v] = t[v*2] + t[v*2+1];
    }
  }
};
