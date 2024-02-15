#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;

template<typename T> struct SegTree{
    int n;
    vector<T> tree; 

    int inf = 1e9;
    int neutral = inf; //elemento neutro da soma

    T join(T a, T b){return min(a,b);} //f para juntar 2 elementos da arvore

    SegTree(int n) : n(n), tree(4*(n+1)){}

    //Coda build é opcional, obtem-se o mesmo resultado em O(nlog)
    //fazendo um update para cada nó
    void build(vector<T> &a, int node, int l, int r){
        if(l == r){
            tree[node] = a[l];
        } else{
            int m = (l + r)/2;
            build(a, 2*node, l , m);       //constroi no esquedo
            build(a, 2*node+1, m+1, r);    //constroi no direito
            tree[node] = join(tree[2*node],tree[2*node+1]);
        }
    }

    T query(int node, int l, int r, int a , int b){
        if(a>r || b<l) return neutral; //verificar se nó pertence ao range
        if(a<=l && b>=r) return tree[node]; //usar se estiver contido
        int mid = (l+r)/2;
        return join(query(2*node, l , mid, a, b) , 
                        query(2*node+1, mid+1, r, a, b));
    }

    //update on a single point
    void update(int node, int l ,int r, int pos, T val){
        if(l == r){
            tree[node] = val;
        } else{
            int m = (l + r)/2;
            if(pos <= m)
                update(2*node, l, m, pos, val);
            else
                update(2*node+1, m+1, r, pos, val);
            tree[node] = join(tree[2*node] ,tree[2*node+1]);
        }   
    }

};


int main(){
    fastio;
    int n, q; cin >> n >> q;
    vector<ll> a(n+1);
    for(int i = 1; i <=n; i++)cin>>a[i];

    SegTree<ll> s(n);

    s.build(a, 1, 1, n);

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