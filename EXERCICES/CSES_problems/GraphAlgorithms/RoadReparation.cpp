#include<bits/stdc++.h>
using namespace std;

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
        return pai[a] = find(pai[a]);
    }

    void union(int a, int b){
        
    }


};




int main(){

    int n,m; cin >> n >> m;

    DSU dsu(n);

    vector<array<int,3>> arestas(m);

    for(int i = 0; i < m; i++){
        cin >> arestas[i][0] >> arestas[i][1]  >> arestas[i][2]; 
    }

    sort(arestas.begin(), arestas.end());
    
    int ans = 0;
    for(int i = 0; i < m; i++){
        int a = arestas[i][1];
        int b = arestas[i][2];
        int p = arestas[i][0];

        if(dsu.find(a) != dsu.find(b)){
            dsu.union(a,b);
            ans += p;
        }

    }

}