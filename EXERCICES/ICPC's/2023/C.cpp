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

int n; 
vector<vector<int>> grafo;
vector<int> peso;
vector<int> ans;
set<int> LIS;

void dfs(int v){

    int tirado = -1, posto = -1;
    auto it = LIS.lower_bound(peso[v]);
    if(it == LIS.end()) {LIS.insert(peso[v]); posto = peso[v];}
    else if(*it  != peso[v]){tirado = *it, posto = peso[v]; LIS.erase(it); LIS.insert(peso[v]);}
    ans[v] = LIS.size();


    for(auto viz : grafo[v]){
        dfs(viz);
    }

    if(tirado != -1) {LIS.insert(tirado);}
    if(posto != -1)  {LIS.erase(posto);}

}

signed main(){
    fastio;
    cin >> n;
    grafo.resize(n+1);
    peso.resize(n+1);
    ans.resize(n+1);

    for(int i = 2; i <= n; i++){
        int a; cin >> a;
        grafo[a].push_back(i);
    }

    for(int i = 1; i <= n; i++) cin >> peso[i];

    dfs(1);

    for(int i = 2; i <= n; i++){
        cout << ans[i] << " ";
    }cout << "\n";
}