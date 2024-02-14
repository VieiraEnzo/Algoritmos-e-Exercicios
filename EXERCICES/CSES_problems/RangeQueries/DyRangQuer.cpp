#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;

template<typename T> struct FenwickTree{

    T n;
    vector<T> bit;

    FenwickTree(vector<T> const &a) : n(a.size()), bit(n,0) {
        for(T i = 1; i <= n; i++){
            upd(i, a[i]);
        }
    }

    void upd(T x, T val){
        for(; x<=n; x+= x&-x) bit[x]+=val;
    }
    
    int sum(T x){
        T ans = 0;
        for(; x; x-=x&-x) ans+=bit[x];
        return ans;
    }

};


int main(){
    fastio;

    int n, q; cin >> n >> q;
    vector<ll> a(n+1,0);
    for(int i = 1; i <= n; i++) cin >> a[i];

    FenwickTree<ll> f(a);


    while (q--)
    {
        int t; cin >> t;
        
        if(t == 1){
            ll k, u; cin >> k >> u;
            f.upd(k, u - a[k]);
            a[k] = u;

        }else{

            ll a,b; cin >> a >> b;
            if(a == 1) cout << f.sum(b) << endl;
            else cout << f.sum(b) - f.sum(a-1) << endl;
        }
    }
    

}