#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;
ll maxn = 1e6 + 5;
vector<vector<ll>> tree(maxn);
vector<ll> comprize(maxn);
vector<ll> indprize(maxn);
vector<ll> marc(maxn);
vector<ll> subarv(maxn);

void dfs(ll v){
    for(ll viz : tree[v]){
        dfs(viz);
        comprize[v] += comprize[viz];
    }
}

void dfs2(ll v){
    subarv[v] = indprize[v] + comprize[v];
    for(ll viz: tree[v]){
        dfs2(viz);
        subarv[v] += subarv[viz];
    }
}


int main(){
    fastio;
    ll n, m, q; cin >> n >> m >> q;


    ll raiz = 1;
    for(ll i = 1; i <= n; i++){
        ll temp; cin >> temp;
        if(temp == 0) raiz = i;
        else tree[temp].push_back(i);
    }

    for(ll i =0 ; i < m; i++){
        ll mi, ci, vi; cin >> mi >>  ci >>  vi;
        if(mi == 1){
            indprize[ci] += vi;
        }else{
            comprize[ci] += vi;
        }
    }

    dfs(raiz);

    dfs2(raiz);


    for(ll i = 0; i < q; i++){
        ll ti, ci; cin >> ti >> ci;
        if(ti == 1){
            cout << indprize[ci] + comprize[ci] << endl;
        }else{
            cout << subarv[ci] << endl;
        }

    }
    

}