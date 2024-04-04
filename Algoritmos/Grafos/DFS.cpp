

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

//iterativo

template<typename T> struct  DfsIterativo
{
    while (!pilha.empty())
    {
        int v = pilha.top();
        pilha.top();

        if(!vis[v]){

            vis[v] = true;

            for(int next : grafo[v]){
                if(vis[next]) continue;
                pilha.push(next);
            }

        }
    }   
};
