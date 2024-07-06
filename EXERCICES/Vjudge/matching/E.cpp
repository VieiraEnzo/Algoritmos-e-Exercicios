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


void solve(int t){

    int n; cin >> n;
    vector<vector<pair<int,int>>> clr_of_pts(2*n + 10);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int temp; cin >> temp;
            clr_of_pts[temp+n].push_back({i,j});
        }
    }

    int ans = 0;
    for(int i = 0; i <= 2*n; i++){
        bm_t bm(n,n);
        for(auto p : clr_of_pts[i]){
            bm.add_edge(p.first, p.second);
        }
        ans += bm.solve();
    }
    

    cout << "Case #" << t << ": " <<  n*n - ans << "\n";
}



signed main(){
    fastio;
    int i = 0;
    int t; cin >> t;
    while (t--) solve(++i);
}