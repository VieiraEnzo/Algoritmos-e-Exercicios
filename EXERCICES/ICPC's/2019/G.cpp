#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

struct Edge{
    int v, u;
    double cap, flow = 0;
    Edge(int v, int u, double cap) : v(v), u(u), cap(cap) {}
};

struct Dinic{
    ll INFL = 1e18;
    int n, m = 0, s, t;
    vector<Edge> edges;
    vector<vector<int>> vec;
    vector<int> lv, pos;
    queue<int> fila;

    Dinic(int n, int s, int t): n(n), s(s), t(t), vec(n+1), lv(n+1), pos(n+1) {}

    void add_edge(int v, int u, double cap){
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

    double dfs(int v, double menor){
        if(!menor) return 0;
        if(v == t) return menor;

        for(int& j=pos[v]; j < (int)vec[v].size(); j++){
            int i=vec[v][j];
            int u=edges[i].u;

            if(lv[v]+1 != lv[u] || edges[i].cap - edges[i].flow < 1) continue;
            double agr=dfs(u, min(menor, edges[i].cap - edges[i].flow));
            if(!agr) continue;

            edges[i].flow += agr;
            edges[i^1].flow -= agr;

            return agr;
        }
        return 0;
    }

    double max_flow(){
        double flow = 0;
        while (1)
        {
            fill(lv.begin(), lv.end(), -1);

            lv[s] = 0;
            fila.push(s);

            if(!bfs()) break;

            fill(pos.begin(), pos.end(), 0);

            while(double atual=dfs(s,INFL)) flow += atual;
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

int pos(int n, int t){
    return n + t;
}

int main(){
    fastio;
    int n; cin >> n;
    int s = 0, t = 2*n + 5;

    Dinic dinic(2*n + 5, s, t);
    vector<double> maxd(n+1);
    vector<double> maxP(n+1);

    vector v(n, vector<int> (n));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            int temp; cin >> temp;
            maxd[i] = max(maxd[i], log2(temp));
            maxP[j] = max(maxP[j], log2(temp));
            dinic.add_edge(i,pos(n,j), log2(temp));
        }
    }

    for(int i = 1; i <= n; i++) dinic.add_edge(s, i, maxd[i]);
    for(int i = 1; i <= n; i++) dinic.add_edge(pos(n,i), t, maxP[i]);

    vector<int> order(n+1);

    cout << dinic.max_flow() << endl;

    for(auto a : dinic.edges){
        if(a.flow > 0 && a.u != s && a.u != t && a.v != s && a.v != t && a.flow == a.cap){
            cout << a.v << " " << a.u << " " << a.cap << "\n";
        }
    }

    for(int i = 1; i <=n ; i++){
        cout << order[i] << " ";
    }cout << "\n";

}