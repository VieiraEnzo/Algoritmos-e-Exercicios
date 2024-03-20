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

    void uu(ll a, ll b){
        a = find(a);
        b = find(b);
        if(rank[a] > rank[b]) swap(a,b);
        rank[b] += rank[a];
        pai[a] = b;
    }

};




int main(){

    ll n,m; cin >> n >> m;

    DSU dsu(n);

    vector<array<ll,3>> arestas(m);

    for(ll i = 0; i < m; i++){
        cin >> arestas[i][1] >> arestas[i][2]  >> arestas[i][0]; 
    }

    sort(arestas.begin(), arestas.end());
    
    ll ans = 0;
    for(ll i = 0; i < m; i++){
        ll a = arestas[i][1];
        ll b = arestas[i][2];
        ll p = arestas[i][0];

        if(dsu.find(a) != dsu.find(b)){
            dsu.uu(a,b);
            ans += p;
        }
    }

    ll solve = 0;
    for(ll i = 1; i <= n; i++){
        if(dsu.pai[i] == i){
            solve++;
        }
    }
    if(solve > 1){
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }else{
        cout << ans << endl;
    }
}