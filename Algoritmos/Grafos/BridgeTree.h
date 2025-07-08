//Algoritmos para encontrar a árvore de pontes e articulação de um grafo
//Complexidade: O(V + E), onde V é o número de vértices e E é o número de arestas.
//A árvore de pontes é um grafo que representa as componentes conexas de um grafo original,
//onde cada componente é formada por uma ponte do grafo original.

struct BridgeTree{

    int n;
    int count = 0;
    vector<int> marc, tin, low, artic;
    vector<vector<int>> grafo, BT;
    vector<pair<int,int>> bridges;

    vector<int> BTcomponent;

    BridgeTree(int n) : n(n), grafo(n+1), marc(n+1), tin(n+1), low(n+1), artic(n+1), 
                        BTcomponent(n+1){}

    void add_edge(int a, int b){
        grafo[a].push_back(b);
        grafo[b].push_back(a);
    }

    void dfs(ll x, ll p){
        marc[x] = 1;
        tin[x] = low[x] = ++count;
        ll children = 0;
        for(ll viz : grafo[x]){
            if(viz == p) continue;
            if(marc[viz]){
                low[x] = min(low[x], tin[viz]);
            }else{
                dfs(viz,x);
                low[x] = min(low[x], low[viz]);
                if(low[viz] > tin[x]){
                    bridges.push_back({min(viz,x), max(viz, x)});
                }
                if(low[viz] >= tin[x] && p) artic[x] = 1;
                children++;
            }
        }
        if(!p && children>1) artic[x] = 1;
    }

    void find_brig_and_artc(){
        for(ll i=1; i<=n; i++){
            if(!marc[i]) dfs(i,0);
        }   
    }

    void BTdfs(int v, int comp, int proib){
        BTcomponent[v] = comp;
        for(auto viz : grafo[v]){
            if(BTcomponent[viz] || viz == proib) continue; 
            BTdfs(viz, comp, proib);
        }
    }

    void BrigeTree(){
        int comp = 0;
        for(auto &b : bridges){
            if(!BTcomponent[b.first])  BTdfs(b.first, ++comp, b.second);
            if(!BTcomponent[b.second]) BTdfs(b.second, ++comp, b.first);
            BT[BTcomponent[b.first]].push_back(BTcomponent[b.second]);
            BT[BTcomponent[b.second]].push_back(BTcomponent[b.first]);
        }
    }


};
