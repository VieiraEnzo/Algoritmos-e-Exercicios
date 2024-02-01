#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;

int main(){
    fastio;
    int n, m; cin >> n >> m;
    vector<vector<int>> g(n+1);
    vector<int> C(n+1,0);
    for(int i =0; i <m; i++)
    {
        int t1,t2; cin >> t1 >> t2;
        g[t1].push_back(t2);
        g[t2].push_back(t1);
    }
    for(int i =1; i < n+1; i++)
    {
        if(C[i]) continue;
        queue<int> fila;
        fila.push(i);
        C[i] = 1;

        while (!fila.empty())
        {
            int v = fila.front();
            fila.pop();

            for(int a : g[v])
            {
                if(C[a] && C[a] == C[v]) {cout << "IMPOSSIBLE";return 0;}
                if(C[a] && C[a] != C[v]) continue;
                fila.push(a);
                C[a] = (C[v]%2)+1;
            }

        }
    
    }

    for(int i =1; i < n+1; i++)
    {
        cout << C[i] << " ";
    }
    

}