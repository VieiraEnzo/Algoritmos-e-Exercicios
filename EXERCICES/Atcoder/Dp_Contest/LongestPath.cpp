#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;
int n, m;
vector<vector<int>> graph;
vector<int> Dist;

int maiorDist(int v){
   if(Dist[v] != -1) return Dist[v];
   Dist[v] = 0;
   for(auto a : graph[v]){
        Dist[v] = max(Dist[v], maiorDist(a) + 1);
   }
   return Dist[v];
}


int main(){
    cin >> n >> m;
    graph.resize(n);
    Dist.resize(n);
    fill(Dist.begin(), Dist.end(), -1);
    
    for(int i= 0; i < m; i++){
        int x1,y1; cin >> x1 >> y1; x1--;y1--;
        graph[x1].push_back(y1);
    }

    int ans = 0;
    for(int i= 0; i < n; i++){
        ans = max(ans, maiorDist(i));
        //cout << "maior dist: " << i << " " << maiorDist(i) << endl;
    }
    cout << ans << endl;
    
    
    
}