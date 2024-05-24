#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int tot;
vector<int> marc(16);
vector<int> dist(16);
map<string,vector<int>> art;
map<string,vector<int>> msc;
vector<vector<int>> grafo;

void bfs(int v){

    queue<int> q;
    q.push(v);
    dist[v] = 0;
    marc[v] = 1;

    while (!q.empty())
    {
        int t = q.front();
        q.pop();

        for(auto a : grafo[t]){
            if(marc[a]) continue;
            marc[a] = 1;
            dist[a] = dist[t] + 1;
            q.push(a);
        }
        
    }
    

}

bool ans(int teste){

    for(int i = 0; i < 16; i++) marc[i] = 0;

    for(int i = 0; i < tot; i++){
        if(!(teste & (1<<i))){
            marc[i] = 1;
        }
    }
    vector<int> save = marc;

    for(int i = 0; i < tot; i++){
        // marc = save;
        for(int i = 0; i < tot; i++) marc[i] = save[i];
        fill(all(dist), 0);
        if(!marc[i]) bfs(i);
        int maxn = 0;
        for(int i = 0; i < tot; i++){
            maxn = max(maxn, dist[i]);
        }
        cout << maxn << "\n";
        if(maxn == __popcount(teste)-1){
            return true;
        }
    }
    return false;
}   

void solve(){
    art.clear();
    msc.clear();
    grafo.clear();
    int n; cin >> n; tot = n;
    grafo.resize(n);
    for(int i = 0; i < n; i++){
        string a, b; cin >> a >> b;
        art[a].push_back(i);
        msc[b].push_back(i);
    }

    for(auto a : grafo[1]) cout << a << "\n";

    for(auto a : art){
        for(int i = 0; i < a.second.size(); i++){
            for(int j = i+1; j < a.second.size(); j++){
                grafo[a.second[i]].push_back(a.second[j]);
                grafo[a.second[j]].push_back(a.second[i]);
            }
        }
    }

    for(auto a : msc){
        for(int i = 0; i < a.second.size(); i++){
            for(int j = i+1; j < a.second.size(); j++){
                grafo[a.second[i]].push_back(a.second[j]);
                grafo[a.second[j]].push_back(a.second[i]);
            }
        }
        
    }

    // for(auto a : grafo[2]) cout << "morte: " << a << "\n";

    int finalmente = 0;
    for(int i = 0 ; i < (1<<n); i++){
        if(ans(7)){
            finalmente = max(finalmente, __popcount(i));
        }
    }
    
    cout << n-finalmente << "\n";
}

int main(){
    fastio;
    int t; cin >> t;
    while (t--) solve();
}