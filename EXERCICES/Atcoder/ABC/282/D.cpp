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

pair<int, pair<int,int>> bfs(int v){
    
    queue<int> q;
    q.push(v);
    color[v] = 0;
    bool Bipart= true;
    int numV = 1;
    int numA = 0;

    while (!q.empty())
    {
        int k = q.front();
        q.pop();

        for(auto a : grafo[k]){
            numA++; //COntando quantas arestas
            if(color[a] == color[k]) Bipart = false;
            if(color[a] != -1) continue;
            color[a] = color[k]^1;
            numV++;
            q.push(a);
        }
    }

    if(Bipart) return {1, {numV, numA/2}};
    return {0, {numV, numA/2}};
}   


signed main(){
    fastio;
    int n,m; cin >> n >> m;

    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        grafo[u].push_back(v);
        grafo[v].push_back(u);
    }

    int ans = 0; int removedV = 0, removedA = 0;
    for(int i = 1; i <= n; i++){
        if(color[i] == -1){
            auto num = bfs(i);
            if(num.first == 0){
                removedV += num.second.first;
                removedA += num.second.second;
            }
            pr(i, num);
        }
    }
    
    // pr(((n - removedV)/2  * ((n - removedV) +1)/2), (m - removedA)); 

    cout << ( ((n - removedV)/2)  * (((n - removedV)+1)/2) ) - (m - removedA) << "\n";

}
