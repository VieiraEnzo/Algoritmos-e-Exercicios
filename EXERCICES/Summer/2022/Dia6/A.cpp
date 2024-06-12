#include <bits/stdc++.h>
using namespace std;
int maxn = 1e5 + 7;
vector<vector<int>> graph(maxn);

void howManyCon(int v){
    marc[v] = 1;
    for(auto viz : graph[v]){
        if(marc[viz]) continue;
        howManyCon(viz);
    }

}


int main(){

    int n, m, A, B; cin >> n >> m >> A >> B;
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    //se a == 0 ou b == 0 posso juntar componentes
    //se nao alasiar por elas

    //para cada componente conexa?
    for(int i = 0; i< n; i++){
        int ans = 0;
        for(int i = 1; i <= n; i++){
            int ai = graph[i].size();
            int bi = n - ai - 1;
            if(ai >= A && bi >= B)ans++;
        }   
    }

    cout << ans << endl;
}