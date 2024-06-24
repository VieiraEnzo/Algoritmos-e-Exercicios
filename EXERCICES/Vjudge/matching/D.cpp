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

struct Pontos{
    pair<int,int> inicio;
    pair<int,int> fim;

    void org(){
        if(inicio > fim){
            swap(inicio, fim);
        }
    }
};


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

bool intersect(Pontos H, Pontos V){
    if(V.inicio.first >= H.inicio.first && V.inicio.first <= H.fim.first)
        if(H.inicio.second >= V.inicio.second && H.inicio.second <= V.fim.second)
            return true;
    return false;
}

signed main(){
    fastio;
    int n; cin >> n;    
    vector<Pontos> Horizontal;
    vector<Pontos> Vertical;

    for(int i = 0; i < n; i++){
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if(x1 == x2){
            Vertical.push_back({{x1,y1},{x2,y2}});
            Vertical.back().org();
        }else{
            Horizontal.push_back({{x1,y1},{x2,y2}});
            Horizontal.back().org();
        }
    }

    bm_t bm(Horizontal.size(), Vertical.size());

    for(int i = 0; i < Horizontal.size(); i++){
        for(int j = 0; j < Vertical.size(); j++){
            if(intersect(Horizontal[i], Vertical[j])){
                bm.add_edge(i,j);
            }
        }
    }

    cout << n - bm.solve() << "\n";

}