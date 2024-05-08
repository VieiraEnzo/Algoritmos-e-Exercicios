#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#pragma GCC optimize("O3")
typedef long long ll;

struct Edge
{
    int v, u;
    ll cap, flow = 0;
    Edge(int v, int u, ll cap) : v(v), u(u), cap(cap) {}
};

struct Dinic{
    ll INFL = 1e18;
    int n, m = 0, s, t;
    vector<Edge> edges;
    vector<vector<int>> vec;
    vector<int> lv, pos;
    queue<int> fila;

    Dinic(int n, int s, int t): n(n), s(s), t(t), vec(n+1), lv(n+1), pos(n+1) {}

    void add_edge(int v, int u, ll cap){
        edges.emplace_back(v, u  ,cap);
        edges.emplace_back(u, v, 0);
        vec[v].push_back(m);
        vec[u].push_back(m+1);
        m+= 2;
    }

    int bfs(){
        while (!fila.empty())
        {
            int v = fila.front();
            fila.pop();
            for(int i : vec[v]){
                if(edges[i].cap - edges[i].flow < 1) continue;
                if(lv[edges[i].u] != -1) continue;

                lv[edges[i].u] = lv[v] + 1;
                fila.push(edges[i].u);
            }
        }
        return lv[t] != -1;
        
    }

    ll dfs(int v, ll menor){
        if(!menor) return 0;
        if(v == t) return menor;

        for(int& j = pos[v]; j <(int) vec[v].size(); j++){
            int i  = vec[v][j];
            int u = edges[i].u;

            if(lv[v]+1 != lv[u] || edges[i].cap - edges[i].flow < 1) continue;
            ll agr = dfs(u, min(menor, edges[i].cap - edges[i].flow));
            if(!agr) continue;

            edges[i].flow += agr;
            edges[i^1].flow -= agr;

            return agr;
        }
        return 0;
    }


    ll max_flow(){
        ll flow = 0;
        while (1)
        {
            fill(lv.begin(), lv.end(), -1);

            lv[s] = 0;
            fila.push(s);

            if(!bfs()) break;

            fill(pos.begin(), pos.end(), 0);

            while (ll atual = dfs(s, INFL)) flow += atual;
            
        }
        return flow;
        
    }

};



signed main(){
    cin.tie(0), ios_base::sync_with_stdio(0);

    int n, m; cin >> n >> m;
    int  s = 0;
    int t = n + m + 1;
    
    vector<int> vis(m+1);
    Dinic dinic(n + m + 1, s, t);

    for(int i = 1;  i <= n; i++){
        int k; cin >> k;
        if(k > 0) dinic.add_edge(s,i,1); //aresta pros compradores
        for(int j = 0; j < k; j++){
            int c; cin >> c;
            dinic.add_edge(i, n + c, 1);
            if(!vis[c]){
                // cout << "v: " << c << "\n";
                dinic.add_edge(n+c, t, 1);
                vis[c] = 1;
            }
        }
    }

    // for(int i = 1; i <= m; i++){
    //     dinic.add_edge(n + i, t, 1);
    // }


    cout << m - dinic.max_flow() << endl;

    return 0;
}