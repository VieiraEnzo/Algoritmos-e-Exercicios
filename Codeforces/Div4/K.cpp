#include <bits/stdc++.h>
using namespace std;
int MAXN = 1e5 + 7;
vector<int> marc(MAXN), pre(MAXN);
vector<vector<int>> graph(MAXN), cicles(MAXN);
stack<int> stk;
int c = 0;
int t = 0;
typedef unsigned long long ull;



void getAns(int viz){

    while (!stk.empty() && stk.top() != viz)
        {   
            //cout << stk.top();
            cicles[c].push_back(stk.top());
            stk.pop();
        }
        if(!stk.empty()){
            cicles[c].push_back(stk.top());
            stk.pop();
        }
        c++;
    
}


//tratar caso ciclo de 2 vértices
void dfs(int x, int pai){
    pre[x] = ++t;
    marc[x] = 1;
    stk.push(x);
    // cout << x << endl;
    // cout << stk.top() << endl;
    for(auto viz : graph[x]){
        if(marc[viz]){
            if(viz == pai) continue;
            if(pre[x] < pre[viz]) continue;
            getAns(viz);
        }else{
            dfs(viz, x);
        }
    }
    if(!stk.empty() && x == stk.top()) stk.pop();
}

void solve(int t){

    int n, m; cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(1,0);

    ull ans = 1;
    for(int i = 0; i < c; i++){
        ans *= cicles[i].size();
    }

    cout << "Case "<< t << ": "  << ans << endl;
}




int main(){

    int t; cin >> t;
    for(int i = 1; i <=t; i++){
        solve(t);
    }
    


}