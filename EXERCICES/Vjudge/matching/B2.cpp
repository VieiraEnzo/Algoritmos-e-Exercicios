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

    int test(int pref){

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

    int d; cin >> d;
    vector<int> AlunosRemovidos(d);
    for(int i = d-1; i >=0; i--){
        cin >> AlunosRemovidos[i];
        removed[AlunosRemovidos[i]] = 1;
    }       

    vector<vector<int>> clubesDePot(5001);
    //Monta solução Otima por enquanto
    bm_t bm(5001,m);
    for(int i = 1; i <= n; i++){
        if(!removed[i]){
            clubesDePot[potential[i]].push_back(clubs[i]);
        }
    }

    while(!clubesDePot[0].empty()){
            bm.add_edge(0, clubesDePot[0].back());
            clubesDePot[0].pop_back();
    }

    //Adicionando alunos:
    vector<int> resp;
    int pref = 0;
    for(int i = 0; i < d; i++){

        while (bm.solve())
        {
            while(!clubesDePot[pref].empty()){
                bm.add_edge(pref, clubesDePot[pref].back());
                clubesDePot[pref].pop_back(); 
            }
            pref++;
        }
        
        resp.push_back(pref);

        int aluno = AlunosRemovidos[i];
        bm.add_edge(potential[aluno], clubs[aluno]);
    }

    reverse(all(resp));
    for(auto a : resp){
        cout << a << "\n";
    }
}