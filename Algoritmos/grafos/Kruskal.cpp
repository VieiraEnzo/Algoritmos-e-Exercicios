//Arvore Geradora Mínima, Algoritmo de Kruskal
//requerido um dsu antes

template<typename T> void Kruskal(){
    init();
    sort(total.begin(), total.end());
    for(array<init, 3> i : total){
        if(ff(i[1]) != ff(i[2])){
            uu(i[1], i[2]);
            resp+=i[0];
        }
    }
}