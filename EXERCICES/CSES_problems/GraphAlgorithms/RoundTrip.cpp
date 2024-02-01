#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;
int maxn =  1e6;
vector<int> marc(maxn);
vector<vector<int>> g(maxn);
vector<int> parent(maxn);
vector<int> ans;
bool resp = false;
int t = 0;

void getAns(int v, int viz){    
    
    ans.push_back(viz);
    while (v != viz)
    {
        ans.push_back(v);
        v = parent[v];
    }
    ans.push_back(viz);
}   


void dfs(int v, int pai){
    marc[v] = 1;
    for(auto viz : g[v]){
        if(marc[viz]){
            if(resp) continue;
            if(viz == pai) continue;
            getAns(v,viz);
            resp = true;
        }
        parent[viz] = v;
        dfs(viz, v);
    }
}



int main(){
    fastio;
    int n, m; cin >> n >> m;
    for(int i =0; i < m; i++)
    {
        int t1, t2; cin >> t1 >> t2;
        g[t1].push_back(t2);
        g[t2].push_back(t1);
    }

    parent[1] = 0;

    for(int i = 1; i<= n; i++){
        if(!marc[i]) dfs(i,0);
    }
    

    if(ans.size()){
        cout << ans.size() << endl;

        for(auto a : ans){
            cout << a << " ";
        }cout << endl;
    }else
        cout << "IMPOSSIBLE" << endl;
    


    

}