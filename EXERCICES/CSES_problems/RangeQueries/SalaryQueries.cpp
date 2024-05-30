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
        multiset<int> val;
    };
    Node neutral = {};
    vector <Node> t;

    SegTree(vector <int> a){
        n = a.size();
        t.resize(4*n);
        build(a, 1, 0, n-1);
    }

    void build(vector <int>& a, int v, int tl, int tr) {
        if (tl == tr) {
            t[v].val = {a[tl]};
        } else {
            int tm = (tl + tr) / 2;
            build(a, v*2, tl, tm);
            build(a, v*2+1, tm+1, tr);
            t[v].val.merge(t[v*2].val);
            t[v].val.merge(t[v*2 +1].val);
        }
    }

    int query(int l, int r){
        cout << t[1].val.
    }

    void update(int pos, int val, vector<int> &a){
        update(1, 0, n-1, pos, val, a);

    }

    void update(int v, int tl, int tr, int pos, int new_val, vector<int> &a){
        t[v].val.erase(t[v].val.find(a[pos]));
        t[v].val.insert(new_val);
        if (tl == tr) {
            t[v].val = {new_val};
        } else {
            int tm = (tl + tr) / 2;
            if (pos <= tm)
                update(v*2, tl, tm, pos, new_val, a);
            else
                update(v*2+1, tm+1, tr, pos, new_val, a);
        }
    }
};

signed main(){
    fastio;

    int n, q; cin >> n >> q;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    SegTree seg(a);

    while (q--)
    {
        char k; int n1,n2;
        cin >> k >> n2 >> n2;
        if(k == '!'){
            seg.update(n1,n2,a);
        }else{
            cout << seg.query(n1,n2) << "\n";
        }
    }
    

}