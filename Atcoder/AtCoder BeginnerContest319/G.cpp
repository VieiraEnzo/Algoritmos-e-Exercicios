#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;

int main(){
    fastio;
        int n,m; cin >> n >> m;
    bool tree = false;
    if(m == n-1){tree = true;}
    vector<vector<int>> g(n+1);
    vector<int> visitado(n+1,0);
    vector<int> pai(n+1,-1);

    for(int i =0; i <m; i++){
        int temp1,temp2; cin>>temp1>>temp2;
        g[temp1].push_back(temp2);
        g[temp2].push_back(temp1);
    }

    bool cicles = false;    
    queue<int> fila;
    fila.push(1);
    visitado[1] = 1;
    while (!fila.empty())
    {   
        int v = fila.front();
        fila.pop();

        for(int a : g[v]){
            if(a == v) continue;
            if(visitado[a]){
                cicles = true;
                continue;
            }
            pai[a] = v;
            fila.push(a);
            visitado[a] = 1;
        }
    }

    int a = n;
    int tamanho = 1;
    while (pai[a]!= -1)
    {
        a = pai[a];
        tamanho += 1;
    }

    if(!tree)
    {
        cout << tamanho << endl;
    }
    else
    {   
        set<int> s;
        for(int i =0; i<=n; i++){
            s.insert(pai[i]);
        }
        if(s.size() == n){
            cout << -1 << endl;
        }
        else{
            cout << tamanho << endl;
        }
    }
    

}