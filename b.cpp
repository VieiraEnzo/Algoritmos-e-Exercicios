#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifdef local
    #include "/home/enzo/Documents/Prog/OBItraining/debug.h"
    #define pr(...) debug(#__VA_ARGS__, __VA_ARGS__)
    #define prs(...) debug_nameless(__VA_ARGS__)
#else
    #define pr(...) 69
    #define prs(...) 69
#endif



int main(){
    cin.tie(0), ios_base::sync_with_stdio(false);

    int n; cin >> n;
    vector<vector<int>> grafo(n+1);

    vector<int> q(n+1), marc(n+1);

    for(int i = 0; i < n-1; i++){
        int a,b;cin >> a >> b;
        grafo[a].push_back(b);
        grafo[b].push_back(a);
    }

    function<void(int)> dfs = [&](int x){
        q[x] = 1;
        marc[x] = 1;
        for(auto viz : grafo[x]){
            if(marc[viz]) continue;
            dfs(viz);
            q[x] += q[viz];
        }
    };

    function<int(int)> find_centroid = [&](int x){
    
        int total = 0;
        for(auto viz : grafo[x]){
            total += q[viz];
        }

        for(auto viz : grafo[x]){
            if(q[viz] > n/2){
                q[x] = total - q[viz];
                return find_centroid(viz);
            }
        }

        return x;
    };

    dfs(1);

    cout << find_centroid(1) << "\n";

}   