#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;

#ifdef local
    #include "/home/enzo/Documents/Prog/OBItraining/debug.h"
    #define pr(...) debug(#__VA_ARGS__, __VA_ARGS__)
    #define prs(...) debug_nameless(__VA_ARGS__)
#else
    #define pr(...) 69
    #define prs(...) 69
#endif


using namespace __gnu_pbds;

#define int long long
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
using ordered_set = tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>;
using ordered_multiset = tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update>;

int inf = 1e9;

struct SegTree{ //segtree 0 indexada sem lazy
    int n;
    struct Node{
        int val;
        Node operator+(Node other) const{
            return {max(this->val,other.val)};
        }
    };
    Node neutral = {-inf};
    vector <Node> t;

    SegTree(vector <int> a){
        n = a.size();
        t.resize(4*n);
        build(a, 1, 0, n-1);
    }

    void build(vector <int>& a, int v, int tl, int tr) {
        if (tl == tr) {
            t[v].val = a[tl];
        } else {
            int tm = (tl + tr) / 2;
            build(a, v*2, tl, tm);
            build(a, v*2+1, tm+1, tr);
            t[v] = t[v*2] + t[v*2+1];
        }
    }

    int query(int x){
        return query(1, 0, n-1, x);
    }

    int query(int v, int tl, int tr, int x){
        if(t[v].val < x){
            return -1;
        }
        if(tl == tr){
            return tl;
        }
        int tm = (tl+tr)/2;
        if(t[2*v].val >= x){
            return query(2*v, tl, tm, x);
        }else{
            return query(2*v + 1, tm+1, tr, x);
        }
    }

    void update(int pos, int val){
        update(1, 0, n-1, pos, val);
    }

    void update(int v, int tl, int tr, int pos, int new_val){
        if (tl == tr) {
            t[v].val -= new_val;
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
    int n, m; cin >> n >> m;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    SegTree seg(v);

    while (m--)
    {
        int a; cin >> a;
        int resp = seg.query(a);
        cout << resp + 1 << " ";
        if(resp != -1) seg.update(resp, a);
    }
    
    cout << "\n";


}