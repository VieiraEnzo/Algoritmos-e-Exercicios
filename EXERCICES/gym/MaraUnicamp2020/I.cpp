#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pii;
typedef pair<ll,ll> pll;

ll n,m;
vector<vector<char>> mat;


pair<ll,ll> rcell(ll v){
    v-=2;
    return {v%n, (v - (v%n))/n};
}


ll cell(ll i, ll j){
    return (i + n*j) + 2 ; 
}


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
                ll v = edges[i].v;
                ll u = edges[i].u;
                auto a = rcell(u);
                if(mat[a.first][a.second] != '.'){
                    a = rcell(v);
                }   
                mat[a.first][a.second] = '%';
                

            }
        }
    }
};


// s = 1
// cell = 2 ... n*m + 1
// t = n*m + 2

int main(){
    fastio;
    cin >> n >> m;

    mat.resize(n);
    ll s = 1;
    ll t = n*m + 2;
    Dinic dinic(t , s ,t);

    for(ll i = 0; i < n; i++){
        mat[i].resize(m);
        for(ll j = 0; j < m; j++){
            cin >> mat[i][j];
        }
    }
    


    vector<pair<ll,ll>> dir = {{1,0}, {0,1}, {-1,0}, {0,-1}};

    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < m; j++){
            for(auto a : dir){
                if(i + a.first < 0 || i + a.first >= n) continue;
                if(j + a.second < 0 || j + a.second >= m) continue;
                if(mat[i + a.first][j+a.second] != '#' && mat[i + a.first][j+a.second] != '1'){
                    dinic.add_edge(cell(i,j), cell(i+a.first, j+a.second), 1);
                }
            }

            if(mat[i][j] == '1'){
                dinic.add_edge(s, cell(i,j), 1e9+7);
            }else if(mat[i][j] == '2'){
                dinic.add_edge(cell(i,j), t, 1e9+7);
            }

        }
    }

    // for(ll i = 0; i < dinic.edges.size(); i+=2){
    //     cout << dinic.edges[i].v << " " << dinic.edges[i].u << endl;
    // }

    ll mf = dinic.max_flow();

    cout << mf << endl;

    if(mf > 0) dinic.recap();

    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < m; j++){
            cout << mat[i][j];
        }cout << endl;
    }
}