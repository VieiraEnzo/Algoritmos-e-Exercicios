#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fastio cin.tie(0), ios_base::sync_with_stdio(0);

struct Edge{
    ll v, u;
    ll cap, flow = 0;
    Edge(ll v, ll u, ll cap) : v(v), u(u), cap(cap) {}
};

struct Dinic{
    ll INFL = 1e18;
    ll n, m = 0, s, t;
    vector<Edge> edges;
    vector<vector<ll>> vec;
    vector<ll> lv, pos;
    queue<ll> fila;

    Dinic(ll n, ll s, ll t): n(n), s(s), t(t), vec(n+1), lv(n+1), pos(n+1) {}

    void add_edge(ll v, ll u, ll cap){
        edges.emplace_back(v, u, cap);
        edges.emplace_back(u,v,0);
        vec[v].push_back(m);
        vec[u].push_back(m+1);
        m+=2;
    }

    ll bfs(){
        while (!fila.empty())
        {
            ll v = fila.front();
            fila.pop();
            for(ll i : vec[v]){
                if(edges[i].cap - edges[i].flow < 1) continue;
                if(lv[edges[i].u] != -1) continue;

                lv[edges[i].u] = lv[v] + 1;
                fila.push(edges[i].u);
            }
        }
        return lv[t] !=-1;
    }

    ll dfs(ll v, ll menor){
        if(!menor) return 0;
        if(v == t) return menor;

        for(ll& j=pos[v]; j < (ll)vec[v].size(); j++){
            ll i=vec[v][j];
            ll u=edges[i].u;

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
        for(ll i=0; i<(ll)edges.size(); i+=2){
            if(lv[edges[i].v]>=0 && lv[edges[i].u] == -1){
                cout << edges[i].v << " " << edges[i].u << endl;
            }
        }
    }
};

int antigo(int a){
    return a+1;
}

int novo( int a, int n){
    return a + n + 1;
}




int main(){ 

    fastio

    ll n,m; cin >> n >> m;
    // s = 1
    // cidO = 2 ... n+1
    // cidN = n+2...2n + 1
    // t = 2n+2
    int s = 1;
    int t = 2*n+2;

    Dinic dinic(2*n+2, 1, t);
    
    ll capS = 0;
    ll capT = 0;

    vector<ll> a(n+1);
    vector<ll> b(n+1);
    for(ll i = 1; i <= n; i++){
        cin >> a[i];
        dinic.add_edge(1, antigo(i), a[i]);
        capS += a[i];
    }

    for(ll i = 1; i <=n; i++){
        cin >> b[i];
        dinic.add_edge(novo(i,n), t, b[i]);
        dinic.add_edge(antigo(i), novo(i,n), a[i]);
        capT += b[i];
    }

    for(ll i = 0; i < m; i++){
        ll x, y; cin >> x >> y;
        dinic.add_edge(antigo(x),novo(y,n), a[x]);
        dinic.add_edge(antigo(y),novo(x,n), a[y]);
    }

    ll mf = dinic.max_flow();

    if(mf != max(capS, capT)){
        cout << "NO" << endl;
    }else{
        cout << "YES" << endl;

        vector mat(n, vector<ll> (n, 0));

        for(ll i = 0; i < dinic.edges.size(); i+=2){
            ll v = dinic.edges[i].v;
            ll u = dinic.edges[i].u;
            if(v == s || v == t || u == s || u == t) continue;
            v = v-2;
            u = u - n - 2;
            mat[v][u] += dinic.edges[i].flow;
        }

        for(ll i = 0; i < n; i++){
            for(ll j = 0; j < n; j++){
                cout <<  mat[i][j] << " ";
            }
            cout << endl;
        }
    }

}