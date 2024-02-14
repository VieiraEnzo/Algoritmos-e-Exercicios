//Binary Indexed Tree
//
//dada uma função f associativa em um sobre um
//conjunto com elemento neutro e inversos
//Querry - O(log(n))
//  ++suporta apenas querry de update singular
//Update - O(log(n))
//
//Não suporta mínimo: Já que míninimo não forma um
//grupo com o conjunto de numeros inteiros, uma vez
//quen não possui elemento inverso

//está quebrada
template<typename T> struct FenwickTree{

    T n;
    vector<T> bit;

    FenwickTree(vector<T> const &a) : n(a.size()), bit(n,0) {
        for(T i = 1; i <= n; i++){
            upd(i, a[i]);
        }
    }

    void upd(T x, T val){
        for(; x<=n; x+= x&-x) bit[x]+=val;
    }
    
    int sum(T x){
        T ans = 0;
        for(; x; x-=x&-x) ans+=bit[x];
        return ans;
    }

};