#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct DSU
{
    ll n;
    vector<ll> pai, rank;

    DSU(ll n) : n(n), pai(n+1), rank(n+1,1){
        for(ll i = 1; i <=n; i++){
            pai[i] = i;
        }
    }

    ll find(ll a){
        if(pai[a] == a) return a;
        return pai[a] = find(pai[a]);
    }

    int uu(ll a, ll b){
        a = find(a);
        b = find(b);
        if(rank[a] > rank[b]) swap(a,b);
        rank[b] += rank[a];
        pai[a] = b;
        return rank[b];
    }

};




int main(){

    cin.tie(nullptr), ios_base::sync_with_stdio(0);

    ll n,m; cin >> n >> m;

    DSU dsu(n);

    int comp = n, maxcomp = 0;
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        if(dsu.find(a) != dsu.find(b)){
            comp--;
            maxcomp = max(maxcomp, dsu.uu(a,b));
        }
        cout << comp << " " << maxcomp << endl;
    }
}