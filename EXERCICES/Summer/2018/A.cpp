#include <bits/stdc++.h>

using namespace std;

#ifdef local
    #include "/home/enzo/Documents/Prog/OBItraining/debug.h"
    #define pr(...) debug(#__VA_ARGS__, __VA_ARGS__)
    #define prs(...) debug_nameless(__VA_ARGS__)
#else
    #define pr(...) 69
    #define prs(...) 69
#endif

#define endl "\n"
#define int long long
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

struct Edge{
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
        edges.emplace_back(v, u, cap);
        edges.emplace_back(u,v,0);
        vec[v].push_back(m);
        vec[u].push_back(m+1);
        m+=2;
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
        return lv[t] !=-1;
    }

    ll dfs(int v, ll menor){
        if(!menor) return 0;
        if(v == t) return menor;

        for(int& j=pos[v]; j < (int)vec[v].size(); j++){
            int i=vec[v][j];
            int u=edges[i].u;

            if(lv[v]+1 != lv[u] || edges[i].cap - edges[i].flow < 1) continue;
            ll agr=dfs(u, min(menor, edges[i].cap - edges[i].flow));
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

            while(ll atual=dfs(s,INFL)) flow += atual;
        }
        return flow;
    }

    void recap(){
        for(int i=0; i<(int)edges.size(); i+=2){
            if(lv[edges[i].v]>=0 && lv[edges[i].u] == -1){
                cout << edges[i].v << " " << edges[i].u << endl;
            }
        }
    }
};


signed main(){
    fastio;
    int n, m; cin >> n >> m;

    int s = 0;
    int t = n+m+1;

    Dinic dinic(t, s, t);

    for(int i = 1; i <= n; i++){
        while (1)
        {
            int r; cin >> r;
            if(r == 0) break;
            dinic.add_edge(i , n + r, 1);
        }
        dinic.add_edge(s, i, 1);
    }

    for(int i  = 1; i <= m; i++){
        dinic.add_edge(n+i, t ,1);
    }

    cout << dinic.max_flow() << "\n";

    for(int i = 0; i < dinic.edges.size(); i+=2){
        int u = dinic.edges[i].u;
        int v = dinic.edges[i].v;
        int flow = dinic.edges[i].flow;

        if(u != s && u != t && v != s && v != t && flow == 1){
            cout << v << " " << u-n << "\n";
        }

    }

}