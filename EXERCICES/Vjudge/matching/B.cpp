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


signed main(){
    // fastio;
    //Informação dos alunos é inutil
    //Modelagem Clubes -> números (0,1,2,3,...,n)
    //Matching entre clubes e números que máximiza o menor número

    int n, m; cin >> n >> m;
    vector<int> potential(n+1), clubs(n+1), removed(n+1);
    for(int i = 1; i <= n; i++) cin >> potential[i];
    for(int i = 1; i <= n; i++) {cin >> clubs[i]; clubs[i]--;}

    auto f = [&](int x){
        //Verificar se existe um matching para
        // o potencial n
        bm_t bm(m,x+1);
        for(int i = 1; i <= n; i++){
            if(potential[i] <= x && !removed[i]){
                bm.add_edge(clubs[i], potential[i]);
            }           
        }
        return bm.solve() == (x+1);
    };

    //Retorna o maior número possivel de fazer
    auto solve = [&](){
        int l = -1, r = 5001;
        while (r - l > 1)
        {
            int mid = (l+r)/2;
            if(f(mid)){
                l = mid;
            }else{
                r = mid;
            }
        }
        return l;
    };


    int d; cin >> d;
    vector<int> AlunosRemovidos(d);
    for(int i = d-1; i >=0; i--){
        cin >> AlunosRemovidos[i];
        removed[AlunosRemovidos[i]] = 1;
    }   


    vector<vector<int>> clubesDePotencial(5001);

    //Monta solução Otima por enquanto
    int cur = solve();
    bm_t bm(5001,m);
    for(int i = 1; i <= n; i++){
        if(potential[i] <= cur && !removed[i]){
            bm.add_edge(potential[i], clubs[i]);
        }else if(!removed[i]){
            clubesDePotencial[potential[i]].push_back(clubs[i]);
        }
    }
    assert(bm.solve() == cur + 1);

    // cout << "oi " << bm.solve() << " " << cur  << "\n";

    //Adicionando alunos:
    vector<int> resp;
    for(int i = 0; i < d; i++){
        resp.push_back(cur + 1); //Primeiro rodamos o algoritmo, depois adicionamos arestas
        int aluno = AlunosRemovidos[i];
        
        if(potential[aluno] == cur+1){
            bm.add_edge(cur+1, clubs[aluno]);
        }else if(potential[aluno] <= cur){
            bm.add_edge(potential[aluno], clubs[aluno]);            
        }else{
            clubesDePotencial[potential[aluno]].push_back(clubs[aluno]);
        }

        int tam = 1;
        while(tam){
            while(!clubesDePotencial[cur+1].empty()){
                int clube = clubesDePotencial[cur+1].back();
                bm.add_edge(cur+1, clube);
                clubesDePotencial[cur+1].pop_back();
            }
            tam = bm.solve();
            cur += tam;
        }

    }

    reverse(all(resp));
    for(auto a : resp){
        cout << a << "\n";
    }
}