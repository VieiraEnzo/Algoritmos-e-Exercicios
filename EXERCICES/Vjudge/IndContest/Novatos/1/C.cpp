#include <bits/stdc++.h>
// #pragma GCC optimize("pragv")
using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;
int maxn = 1e5 + 5;

struct DSU
{
    int n;
    vector<int> pai, rank;

    DSU(int n) : n(n), pai(n+1), rank(n+1,1){
        for(int i = 1; i <=n; i++){
            pai[i] = i;
        }
    }

    int find(int a){
        if(pai[a] == a) return a;
        return pai[a] = find(pai[a]);
    }

    void uu(int a, int b){
        a = find(a), b = find(b);
        if(a == b) return;
        if(rank[a] > rank[b]) swap(a,b);
        rank[b] += rank[a];
        pai[a] = b;
    }

};

int entrada(int n){
    return 2*n;
}

int saida(int n){
    return (2*n)+1;
}


int main(){
    fastio;
    int n, q; cin >> n >> q;

    DSU dsu(2*n);

    for(int i = 0; i < q; i++){
        int l, r; cin >> l >> r;
        dsu.uu(saida(l), entrada(r));
    }

    for(int i =1 ; i < n; i++){
        dsu.uu(entrada(i), saida(i+1));
    }

    // cout <<  dsu.find(saida(1) << " " << dsu.find(entrada(n))) << "\n";

    if(dsu.find(saida(1)) == dsu.find(entrada(n))){
        cout << "Yes" << "\n";
    }else{
        cout << "No" << "\n";
    }

}