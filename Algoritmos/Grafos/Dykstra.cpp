
//Algoritmo de Caminho mínimo para grafos com
//pesos não negativos. Um para todos
// O(nlog)

template<typename T> struct Dykstra
{
    ll INF = 1e18;

    int n;
    vector<ll> dist;
    vector<vector<pair<int,int>>> g;

    Dykstra(int n) : n(n), dist(n+1,INF), g(n+1) {}

    void addEdge(ll v, ll u, ll p){
        g[v].push_back({u,p});
        g[u].push_back({v,p});
    }

    void dykstra(ll v){

        //preparing structures
        priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, 
        greater<pair<ll,ll>>> fila;

        //setting up
        fila.push({0,v});
        
        while (!fila.empty())
        {      
            ll vert = fila.top().second;
            ll price = fila.top().first;
            fila.pop();

            if(dist[vert] != INF) continue;

            dist[vert] = price;

            for(auto viz : g[vert]){
                ll nxt = viz.first;
                ll cost = viz.second;
                fila.push({price + cost, nxt});
            }
        }

    }

};

