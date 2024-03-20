#include<bits/stdc++.h>
using namespace std;

struct Kosa{

    int n, cont = 0;
    vector<int> marc, ord, comp;
    vector<vector<int>> grafo, rgrafo,scc;

    Kosa(int n) : n(n), marc(n+1), grafo(n+1), rgrafo(n+1), comp(n+1), scc(n+1) {} 

    void add_edge(int a, int b){
        grafo[a].push_back(b);
        rgrafo[b].push_back(a);
    }

    void dfs1(int v){   
        marc[v] = 1;
        for(auto viz : grafo[v]){
            if(!marc[viz]) dfs1(viz);
        }
        ord.push_back(v);
    }

    void dfs2(int v, int c){
        comp[v] = c;
        for(auto viz : rgrafo[v]){
            if(!comp[viz]) dfs2(viz, c);
        } 
    }

    void build(){

        cont = 0;

        for(int i = 1; i <=n ;i++){
            if(!marc[i]) dfs1(i);
        }

        reverse(ord.begin(), ord.end());

        for(int v : ord){
            if(!comp[v]){
                dfs2(v, ++cont);
            }
        }

        for(int i = 1; i <=n; i++){
            for(int j : grafo[i]){
                if(comp[i] == comp[j]) continue;
                scc[comp[i]].push_back(comp[j]);
            }
        }

    }

};
int main(){
    int n, m; cin >> n >> m;

    Kosa k(n);

    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        k.add_edge(a,b);
    }

    k.build();

    if(k.cont > 1){
        cout << "NO" << endl;
        int ans1, ans2;
        for(int i = 1; i<=n; i++){
            if(k.comp[i] == 1){
                ans1 = i;
            }else if(k.comp[i] == 2){
                ans2 = i;
            }
        }

        cout << ans2 << " " << ans1 << endl;
    }else{
        cout << "YES" << endl;
    }
}