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
#define int long long
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int maxn = 2e5 + 10;
vector<int> color(maxn, -1);
vector<vector<int>> grafo(maxn);

pair<int, vector<int>> bfs(int v){
    
    queue<int> q;
    q.push(v);
    color[v] = 0;
    bool Bipart= true;
    vector<int> num(3);
    num[0]++;

    while (!q.empty())
    {
        int k = q.front();
        q.pop();

        for(auto a : grafo[k]){
            num[2]++;
            if(color[a] == color[k]) {Bipart = false; continue;}
            if(color[a] != -1) continue;
            color[a] = color[k]^1;
            num[color[a]]++;            
            q.push(a);
        }
    }

    num[2]/=2;
    if(Bipart) return {1, num};
    return {0, num};
}   


signed main(){
    fastio;
    int n,m; cin >> n >> m;

    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        grafo[u].push_back(v);
        grafo[v].push_back(u);
    }


    vector<vector<int>> compConex;
    for(int i = 1; i <= n; i++){
        if(color[i] == -1){
            auto num = bfs(i);
            if(num.first == 1){
                compConex.push_back(num.second);
            }else{
                cout << 0 << "\n"; return 0;
            }
        }
    }
    
    pr(compConex);

    int ans = 0;
    int sumVert = 0;
    for(int i = 0; i < (int)compConex.size(); i++){
        ans += sumVert * (compConex[i][0] + compConex[i][1]); //Dessa componente com todas as outras
        ans += (compConex[i][0] *  compConex[i][1]) - compConex[i][2] ; //Vertices Pretos com os brancos
        sumVert += (compConex[i][0] + compConex[i][1]);
        pr(sumVert, ans);
    }

    cout << ans << "\n";
}
