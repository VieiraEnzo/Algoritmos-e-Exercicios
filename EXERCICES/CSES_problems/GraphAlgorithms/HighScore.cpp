#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;
int maxn = 2501;
vector<vector<int>> g(maxn);
vector<int> marc(maxn);

void dfs(int v){
    marc[v] = 1;
    for(auto a : g[v]){
        if(marc[a]) continue;
        dfs(a);
    }
}

struct Edge{
    int v, u, cost;
    Edge(int v, int u, int cost): v(v), u(u), cost(cost) {}
};

struct Ford
{   
    const ll INFL = 1e18;
    const ll MINFL = -1e18;
    int n, m;
    vector<Edge> edges;
    vector<ll> dist;
    vector<int> p; //retorna caminho

    Ford(int n, int m) : n(n), m(m), dist(n+1, MINFL), p(n,-1) {}

    void add_edge(int v, int u, int cost){
        edges.emplace_back(v,u,cost);
    }

    ll bellman(int s, int t){
        dist[s] = 0;

        //Encontrar distancias
        for(int k=1; k < n; k++){
            for(Edge e : edges){
                int a = e.v, b = e.u, c = e.cost;
                if(dist[a] != MINFL && dist[b] < dist[a] + c){
                    dist[b] = dist[a] + c;
                }
            }
        }

        //Se conseguirmos melhorar após n-1, significa que existe ciclo negativo
        for(Edge e : edges){
            int a = e.v, b =e.u, c=e.cost;
            if(dist[a] != MINFL && dist[b] < dist[a]+c){
                if(!marc[a]){
                    dfs(a);
                }
            }
        }

        if(marc[t]) return -1;

        return dist[t] == MINFL?-1:dist[t];
        
    }


};



int main(){
    fastio;
    
    int n, m; cin >> n >> m;
    Ford f(n,m);
    for(int i = 0; i < m; i++){
        int a, b, c; cin >> a >> b >> c;
        f.add_edge(a,b,c);
        g[a].push_back(b);
    }

    cout << f.bellman(1,n) << endl;

}