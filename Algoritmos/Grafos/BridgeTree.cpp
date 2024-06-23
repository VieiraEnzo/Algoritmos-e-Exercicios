template<typename T> struct ArticPont{

    int n;
    int count = 0;
    vector<int> marc, tin, low, artic;
    vector<vector<int>> grafo, BT;
    vector<pair<int,int>> bridges;

    vector<int> BTcomponent;

    ArticPont(int n) : n(n), grafo(n+1), marc(n+1), tin(n+1), low(n+1), artic(n+1), 
                        BTcomponent(n+1){}

    void add_edge(int a, int b){
        grafo[a].push_back(b);
        grafo[b].push_back(a);
    }

    void dfs(int x, int p){
        marc[x] = 1;
        tin[x] = low[x] = ++count;
        int children = 0;
        for(int i : grafo[x]){
            if(i == p) continue;
            if(marc[i]){
                low[x] = min(low[x], tin[x]);
            }else{
                dfs(i,x);
                low[x] = min(low[x], low[i]);
                if(low[i] > tin[x]){
                    bridges.push_back({min(i,x), max(i, x)});
                }
                if(low[i] >= tin[x] && p) artic[x] = 1;
                children++;
            }
        }
        if(!p && children>1) artic[x] = 1;
    }

    void find_brig_and_artc(){
        for(int i=1; i<=n; i++){
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
            if(!BTcomponent[b.first])  BTdfs(b.first, ++comp, b.first);
            if(!BTcomponent[b.second]) BTdfs(b.second, ++comp, b.second);
            BT[BTcomponent[b.first]].push_back(BTcomponent[b.second]);
            BT[BTcomponent[b.second]].push_back(BTcomponent[b.first]);
        }
    }


};
