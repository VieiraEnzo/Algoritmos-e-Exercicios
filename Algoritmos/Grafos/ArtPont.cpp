template<typename T> struct ArticPont{

    int n;
    int count = 0;
    vector<int> marc, tin, low, artic;
    vector<vector<int>> grafo;
    vector<pair<int,int>> bridges;

    ArticPont(int n) : n(n), grafo(n+1), marc(n+1), tin(n+1), low(n+1), artic(n+1) {}

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

};
