//Arvore Geradora Mínima, Algoritmo de Kruskal
//requerido um dsu antes

template<typename T> struct Kruskal
{
    void MinTree(){
        sort(arestas.begin(), arestas.end());
        for(auto arr : arestas){
            int p = arr[0], a = arr[1], b = arr[2];
            if(find(a) != find(b)){
                uu(a,b);
                //dicionar aresta
            }
        }
    }

};