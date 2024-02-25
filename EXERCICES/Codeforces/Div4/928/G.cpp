#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;
int maxn = 1e5 + 5;
vector<vector<int>> g;
string type;
int ans = 0;

pair<bool,bool> dfs(int v){

    bool s = type[v-1] == 'S', p = type[v-1] == 'P';

    int cnts = 0, cntp = 0;
    for(auto viz : g[v]){
        auto a = dfs(viz);
        if(a.first)cnts++;
        if(a.second)cntp++; 
        
    }

    if(type[v-1] == 'P'){ans += cnts; s = false;}
    if(type[v-1] == 'S'){ans += cntp; p = false;}
    // else if(cnts < cntp){
    //     ans += cnts;
    //     s = false;
    // }else{
    //     ans += cntp;
    //     p = false;
    // }
    if(type[v-1] == 'C'){
        ans += min(cntp, cnts);
        if(cntp == min(cntp, cnts)) p = false;
        else s = false;    
    }

    return {s,p};

}


void solve(){
    int n; cin >> n;
    g.clear();
    g.resize(n+1);
    ans = 0;

    for(int i = 2; i <= n; i++){
        int temp; cin >> temp;
        g[temp].push_back(i);
    }

    cin >> type;

    dfs(1);

    cout << ans << endl;
}


int main(){
    
    fastio;

    int t; cin >> t;
    while (t--)
    {
        solve();
    }

}