#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;
int MAXN = 5 * 1e5 + 7;
vector<vector<int>> graph(MAXN);
vector<ll> fundo;
vector<int> marc(MAXN);

ll findAns(){

    sort(fundo.begin(), fundo.end());

    ll ans = 0;
    
    // for(auto a : fundo){
    //     cout << a << " "; 
    // }cout<<endl;

    if(fundo.size() > 0)ans = fundo[0];
    for(int i = 0 ; i < fundo.size()-1 ; i++){
        if(fundo[i+1] <= fundo[i]){
            fundo[i+1] = fundo[i] + 1;
        }
        ans = max(ans, fundo[i+1]);
    }


    return ans;
}


void dfs(int v, int height){
    marc[v] = 1;
    if(graph[v].size() == 1 ) fundo.push_back(height);
    for(auto a : graph[v]){
        if(marc[a]) continue;
        dfs(a, height + 1);
    }
}


void solve(){
    
    ll resp = 0;
    for(auto a : graph[1]){
        fundo.clear();
        marc[1] = 1;
        dfs(a,1);
        resp = max(resp, findAns());
    }

    cout << resp << endl;

}


int main(){
    fastio;
    int n; cin >> n;
    for(int i = 0; i< n-1; i++){
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);

    }

    solve();
}