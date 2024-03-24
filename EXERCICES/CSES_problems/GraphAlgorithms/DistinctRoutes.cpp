#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fastio cin.tie(0), ios_base::sync_with_stdio(0);

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

    void recap(){ //find mincut
        for(int i=0; i<(int)edges.size(); i+=2){
            if(lv[edges[i].v]>=0 && lv[edges[i].u] == -1){
                cout << edges[i].v << " " << edges[i].u << endl;
            }
        }
    }
};


//DFS ESTA ERRADAAAAAAAA BURRO BURRO BURRO BURRO BURRO
int n;
vector<int> ans;
void dfs(int v, Dinic &d){
    for(int i : d.vec[v]){
        if(i%2 == 0 && d.edges[i].flow > 0){
            d.edges[i].flow = 0;
            ans.push_back(v);
            dfs(d.edges[i].u, d);
            if(v != 1) break;
        }
    }
    if(ans.size()){
        cout << ans.size() + 1 << endl;
        for(auto a : ans) cout << a << " ";
        cout << n;
        cout << endl;
        ans.clear();
    }
}



int main(){

    fastio;
    int m; cin >> n >> m;

    Dinic dinic(n,1,n);

    for(int i = 0; i < m; i++){
        int a,b; cin >> a >> b;
        dinic.add_edge(a,b,1);
    }

    cout << dinic.max_flow() << endl;

    dfs(1, dinic);

}
