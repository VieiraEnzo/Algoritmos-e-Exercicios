
//Algoritmo de Caminho mínimo para grafos com
//pesos não negativos. Um para todos
// O(nlog)

template<typename T> struct Dykstra
{
    ll INF = 1e18;

    int n;
    vector<ll> dist;

    Dykstra(int n) : n(n), dis(n,INF) {}

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
                fila.push({price + viz.first, viz.second});
            }
        }

}



};


