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

using vi = vector<int>;
bool dfs(int a, int L, const vector<vi> &g, vi &btoa, vi &A, vi &B) { ///start-hash
    if (A[a] != L) return 0;
    A[a] = -1;
    for(auto &b : g[a]) if (B[b] == L + 1) {
        B[b] = 0;
        if (btoa[b] == -1 || dfs(btoa[b], L+1, g, btoa, A, B))
            return btoa[b] = a, 1;
    }
    return 0;
} ///end-hash
int hopcroftKarp(const vector<vi> &g, vi &btoa) { ///start-hash
    int res = 0;
    vector<int> A(g.size()), B(int(btoa.size())), cur, next;
    for (;;) {
        fill(A.begin(), A.end(), 0), fill(B.begin(), B.end(), 0);
        cur.clear();
        for(auto &a : btoa) if (a != -1) A[a] = -1;
        for (int a = 0; a < g.size(); ++a) if (A[a] == 0) cur.push_back(a);
        for (int lay = 1;; ++lay) { 
            bool islast = 0; next.clear();
            for(auto &a : cur) for(auto &b : g[a]) {
                if (btoa[b] == -1) B[b] = lay, islast = 1;
                else if (btoa[b] != a && !B[b])
                    B[b] = lay, next.push_back(btoa[b]);
            }
            if (islast) break;
            if (next.empty()) return res;
            for(auto &a : next) A[a] = lay;
            cur.swap(next);
        }
        for(int a = 0; a < int(g.size()); ++a)
            res += dfs(a, 0, g, btoa, A, B);
    }
} ///end-hash

signed main(){
    fastio;
    //Informação dos alunos é inutil
    //Modelagem Clubes -> números (0,1,2,3,...,n)
    //Matching entre clubes e números que máximiza o menor número

    int n, m; cin >> n >> m;
    vector<int> potential(n), clubs(n), removed(n);
    for(int i = 0; i < n; i++) cin >> potential[i];
    for(int i = 0; i < n; i++) cin >> clubs[i];

    auto f = [&](int x){
        //Verificar se existe um matching para
        // o potencial n
        vector<vector<int>> graph(m);
        vector<int> btoa(x+1, -1);
        // bm_t bm(m,x+1);
        for(int i = 0; i < n; i++){
            if(potential[i] <= x && !removed[i]){
                // bm.add_edge(clubs[i]-1, potential[i]);
                graph[clubs[i]-1].push_back(potential[i]);
            }           
        }
        return hopcroftKarp(graph, btoa) == (x+1);
    };

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

    // cout << "Oi " << f(3) << " "  << f(2) << "\n"; 

    int d; cin >> d;
    while (d--)
    {
        int k; cin >> k; k--;
        removed[k] = 1;

        cout << solve() + 1 << "\n";
    }


    

}