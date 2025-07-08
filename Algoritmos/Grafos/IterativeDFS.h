//DFS iterativa
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
