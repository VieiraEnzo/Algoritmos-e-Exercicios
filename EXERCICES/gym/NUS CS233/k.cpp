#include <bits/stdc++.h>
#pragma GCC optimize("O2")
//#pragma GCC optimize ("trapv")

using namespace std;

#ifdef local
    #include "debug.h"
    #define pr(...) debug(#__VA_ARGS__, __VA_ARGS__)
    #define prs(...) debug_nameless(__VA_ARGS__)
#else
    #define pr(...) 69
    #define prs(...) 69
#endif

#define pb push_back
#define endl '\n'
#define int long long

typedef double dbl;
typedef long long ll;
typedef unsigned long long ull;

const int inf = 1e4 + 69;
const ll binf = 1e18;
const dbl eps = 1e-9;

void setIO(string s = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(s.size() > 0){
        freopen((s + ".in").c_str(), "r", stdin);
        freopen((s + ".out").c_str(), "w", stdout);
    }
}

struct Node{    
    int min1 = inf;
    int min2 = inf;
    int max1 = -inf;
    int max2 = -inf;
};

const int maxn = 5e5+4;
vector <Node> t(4*maxn);

Node neutral = {inf, inf, -inf, -inf};

Node merge(Node a, Node b){
    vector <int> min = {a.min1, b.min1, a.min2, b.min2};
    vector <int> max = {a.max1, b.max1, a.max2, b.max2};
    sort(min.begin(), min.end());
    sort(max.begin(), max.end());
    Node t;
    t.min1 = min[0], t.min2 = min[1];
    t.max1 = max[3], t.max2 = max[2];
    return t;
}

void build(vector <int> &a, int v, int tl, int tr) {
    if (tl == tr) {
        t[v].min1 = a[tl];
        t[v].min2 = inf;
        t[v].max1 = a[tl];
        t[v].max2 = -inf;
    }else{
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = merge(t[v], t[2*v]);
        t[v] = merge(t[v], t[2*v+1]);
    }
}

Node query(int v, int tl, int tr, int l, int r) {
    if (l > r) 
        return neutral;
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return merge(query(v*2, tl, tm, l, min(r, tm)), 
                query(v*2+1, tm+1, tr, max(l, tm+1), r));
}

void solve(int tc){
    int n, q;
    cin >> n >> q;

    vector <int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    build(arr, 1, 0, n-1);

    while(q--){
        int l, r;
        cin >> l >> r;
        l -= 1;
        r -= 1;

        Node sla = query(1, 0, n-1, l+1, r-1);
        
        pr(sla.min1, sla.min2, sla.max2, sla.max1);
        int num = arr[l]*arr[r];

        vector <int> a = {sla.min1, sla.min2, sla.max2, sla.max1};

        int ans = -binf;
        ans = max({ans, num*a[0]*a[3], num*a[0]*a[1], num*a[3]*a[2]});
        cout << ans << endl;
    }
}   

signed main(){
    setIO();

    int tc = 1;
    if(tc != 1) cin >> tc;
    
    for (int t = 0; t < tc; t++) {
        pr(t); prs(string(50, '-'));
        solve(t);
        prs(string(50, '-') + "\n");
    }

    return 0;
}