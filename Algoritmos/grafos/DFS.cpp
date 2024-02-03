

template<typename T > struct DFS{

    vector<int> marc;
    vector<vector<int>> graph;

    void dfs(int v){
        marc[v] = 1;
        for(auto viz ; graph[v]){
            if(marc[viz]) continue;
            dfs(viz);
        }
    }   

};