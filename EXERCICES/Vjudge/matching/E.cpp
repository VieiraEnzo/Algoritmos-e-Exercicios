#include <bits/stdc++.h>

using namespace std;

#ifdef local
    #include "/home/enzo/Documents/Prog/OBItraining/debug.h"
    #define pr(...) debug(#__VA_ARGS__, __VA_ARGS__)
    #define prs(...) debug_nameless(__VA_ARGS__)
#else
    #define pr(...) 69
    #define prs(...) 69
#endif


#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;


struct bm_t
{
    int N, M, T;
    vector<vector<int>> grafo;
    vector<int> match, seen;
    bm_t(int a, int b) : N(a), M(a+b), T(0), grafo(M),
                        match(M, -1), seen(M, -1) {}
    
    void add_edge(int a, int b){
        grafo[a].push_back(b + N);
    }

    bool dfs(int cur){
        if(seen[cur] == T) return false;
        seen[cur] = T;
        for(int nxt : grafo[cur]) if(match[nxt] == -1){
            match[nxt] = cur;
            match[cur] = nxt;
            return true;
        }
        for(int nxt : grafo[cur]) if(dfs(match[nxt])){
            match[nxt] = cur;
            match[cur] = nxt;
            return true;
        }
        return false;
    }

    int solve(){
        int res = 0;
        for(int cur = 1; cur;){
            cur = 0; ++T;
            for(int i = 0; i < N; ++i) if(match[i] == -1)
                cur += dfs(i);
            res += cur;
        }
        return res;
    }

};

int n;
int ID(int i, int j){
    return i + n*j;
}

int CorLinha(int cor, int linha){
    // 0...n-1 : (n) linhas
    // 0...2*n : 2*n+1 cores
    //Total = 2*n² + n vértices
    return (2*n+1)*linha + cor;
}

int CorColuna(int cor, int coluna){
    const int pref = (2*n+1)*n + n + 1;
    return pref + (2*n+1)*coluna + cor;
}

void solve(){
    //Problema de minimum vertex cover
    //Podem existir n³ arestas
    //Não é bipartido
    //Para cada linha e coluna Vértices com esses
    //números
    //Para cada celula, uma aresta ligando a cor em
    //sua linha e coluna respectivamente
    //V = 2*N * Ci + N²
    //E = 2*N
    //Achar minimum vertex cover
    //O(N³) * T
    cin >> n;
    vector<vector<int>> mat(n, vector<int> (n));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int temp; cin >> temp;
            mat[i][j] = temp + n;
        }
    }

    bm_t bm(n*n,4*n*n);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            bm.add_edge(ID(i,j), CorLinha(mat[i][j], i));
            bm.add_edge(ID(i,j), CorColuna(mat[i][j], j));
        }
    }
    

    cout << bm.solve() << "\n";
}



signed main(){
    fastio;
    int t; cin >> t;
    while (t--) solve();
}