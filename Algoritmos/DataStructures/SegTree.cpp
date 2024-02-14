//SegTree
//Update - O(n)
//Querry - O(n)


template<typename T> struct SegTree{
    int n;
    vector<T> tree; 

    int neutral = 0; //elemento neutro da soma

    T join(T a, T b){return a + b;} //f para juntar 2 elementos da arvore

    SegTree(int n) : n(n), tree(4*(n+1)){}

    //Coda build é opcional, obtem-se o mesmo resultado em O(nlog)
    //fazendo um update para cada nó
    void build(vector<T> &a, int node, int l, int r){
        if(l == r){
            tree[node] = a[l];
        } else{
            int m = (l + r)/2;
            build(a, 2*node, l , m);       //constroi no esquedo
            build(a, 2*node+1, m+1, r);    //constroi no direito
            tree[node] = tree[2*node] + tree[2*node+1];
        }
    }

    T query(int node, int l, int r, int a , int b){
        if(a>r || b<l) return neutral; //verificar se nó pertence ao range
        if(a<=l && b>=r) return tree[node]; //usar se estiver contido
        int mid = (l+r)/2;
        return join(query(2*node, l , mid, a, b) , 
                        query(2*node+1, mid+1, r, a, b));
    }

    //update on a single point
    void update(int node, int l ,int r, int pos, T val){
        if(l == r){
            tree[node] = val;
        } else{
            int m = (l + r)/2;
            if(pos <= m)
                update(2*node, l, m, pos, val);
            else
                update(2*node+1, m+1, r, pos, val);
            tree[node] = join(tree[2*node] ,tree[2*node+1]);
        }   
    }

};