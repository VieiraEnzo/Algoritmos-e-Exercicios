#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll maxn = 1e5 + 10;
vector<vector<ll>> grafo(maxn);
vector<ll> marc(maxn);
ll count = 0;
vector<ll> leaves;
ll h;

void dfs(ll v){ 
    marc[v] = 1;
    if(grafo[v].size() == 1){leaves.push_back(v);}
    for(auto viz : grafo[v]){
        if(!marc[viz]) {dfs(viz);}
    }
}

int main(){
    cin.tie(0); ios_base::sync_with_stdio(0);
    ll n; cin >> n >> h;
    for(ll i = 0; i < n-1; i++){
        ll a,b; cin >> a >> b;
        grafo[a].push_back(b);
        grafo[b].push_back(a);
    }

    ll init = h;
    if(grafo[h].size() == 1) init = grafo[h].back(); 
    dfs(init);

    cout << (leaves.size()+1)/2 << "\n";
    for(ll i = 0; i < leaves.size()/2; i++){
        cout << leaves[i] << " " << leaves[i + leaves.size()/2 + leaves.size()%2] << "\n";
    }
 
    if(leaves.size()%2 == 1){ cout << leaves[leaves.size()/2 ] << " " << init << "\n";}
}   