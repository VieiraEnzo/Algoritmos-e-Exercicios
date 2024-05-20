#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int n, k, Pb, Ps;
vector<int> grafo(2e5 + 10);
vector<int> marc(2e5 + 10);
vector<int> arr(2e5 + 10);
int ans = 0;


void dfs(int v,int sum, int k){
    if(k == 0) return;
    marc[v] = 1;
    ans = max(ans, sum + arr[v] * k);
    if(!marc[grafo[v]]) dfs(grafo[v],sum + arr[v], k - 1);
}

void clear(){
    grafo.clear();
    marc.clear();
    arr.clear();
    ans = 0;
}

void solve(){

    clear();
    cin >> n >> k >> Pb >> Ps;

    for(int i = 1; i <= n; i++){
        int v; cin >> v;
        grafo[i] = v;
    }

    for(int i = 1; i <= n; i++) cin >> arr[i];
    
    dfs(Pb, 0, k);
    int ans1 = ans;
    for(int i = 0; i < 2e5 + 10; i++) marc[i] = 0;
    ans = 0;
    dfs(Ps, 0, k);

    if(ans1 < ans){
        cout << "Sasha\n";
    }else if(ans1 == ans){
        cout << "Draw\n";
    }else{
        cout << "Bodya\n";
    }
    

}

signed main(){
    fastio;
    int t; cin >> t;
    while (t--) solve();
}