#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;

template<typename T> struct SegTree{
    T n;
    vector<T> tree; 

    int neutral = 0; //elemento neutro da soma

    int join(int a, int b){return a + b;} //f para juntar 2 elementos da arvore

    SegTree(int n) : n(n), tree(4*(n+1)){}

    void build(vector<int> &a, int node, int tl, int tr){
        if(tl == tr){
            tree[node] = a[tl];
        } else{
            int m = (tl + tr)/2;
            build(a, 2*node, tl , m);       //constroi no esquedo
            build(a, 2*node+1, m+1, tl);    //constroi no direito
            tree[node] = tree[2*node] + tree[2*node+1] 
        }
    }

    T query(int node, int tl, int tr, int l , int r){
        if(a>r || b<l) return neutral; //
        if(a<=l && b<=r) return tree[node];
        int mid = (l+r)/2;
        return join(query(2*node, l , mid, a, b) , 
                        query(2*node+1, mid, r, a, b));
    }

    //update on a single point
    T update(int node, int l ,int r, int pos, int val){
        if(l == r){
            tree[node] = val;
        } else{
            int m = (l + r)/2;
            if(pos <= m)
                update(2*node, l, m, pos, val);
            else
                update(2*node+1, m, r, pos, val);
            tree[node] = tree[2*node] + tree[2*node+1];
        }   
    }

};


int main(){
    fastio;

    int n,q; cin >> n >> q;
    vector<int> a(n+1);
    for(int i=0; i < n; i++) cin>>a[i];

    SegTree<ll> s(n);

    while (q--)
    {
        int i, a ,b; cin >> i >> a >> b;

        if(i == 1){
            s.update(1,1,n,a,b);
        }else{
            cout << s.query(1,1,n,a,b) << endl;
        }
    }
    

}