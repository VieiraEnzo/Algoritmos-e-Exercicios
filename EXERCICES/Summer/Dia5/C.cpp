#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll maxn = 500 + 7;
vector<vector<int>> graph(maxn);
vector<int> age(maxn);
vector<int> marc(maxn);
int n,m, i, minAge;
int inf = 1e9;

//O(n+m)
void swap(int a, int b){
    
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < graph[i].size(); j++){
            if(graph[i][j] == a){graph[i][j] = b;}
            else if(graph[i][j] == b){graph[i][j] = a;}
        }
    }

    swap(graph[a], graph[b]);

    // for(int i = 0; i < n; i++){
    //     for(auto v : graph[i]){
    //         cout << v << " "; 
    //     }cout << endl;}

}

void dfs(int v){
    // cout << v << " ";
    if(!marc[v]) minAge = min(minAge, age[v]);
    marc[v] = 1;
    for(auto viz : graph[v]){
        if(marc[viz]) continue;
        dfs(viz);
    }

}

void solve(int n){

    for(int i = 1; i <= n; i++)graph[i].clear();
    fill(age.begin(), age.end(), 0);

    cin >> m >> i;

    for(int i = 1; i <= n; i++) cin>> age[i];

    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        graph[b].push_back(a);
    }

    while (i--)
    {
        char c; cin >> c;
        int a, b;
        if(c == 'T'){
            cin >> a >> b;
            swap(a,b);
        }else{
            cin >> a;
            fill(marc.begin(), marc.end(), 0);
            minAge = inf;
            marc[a] = 1;
            dfs(a);
            // cout << endl;
            if(graph[a].empty()){cout << '*' << endl;}
            else cout << minAge << endl;
        }
    }
    
}



int main(){

    cin.tie(nullptr);ios_base::sync_with_stdio(false);

        while (cin >> n)
        {
        solve(n);
        }
   
}