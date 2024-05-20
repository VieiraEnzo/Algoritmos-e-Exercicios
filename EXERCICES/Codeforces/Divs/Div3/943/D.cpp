#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pii;
typedef pair<ll,ll> pll;

int maxn = 2e5 + 10;
ll n, k, Pb, Ps;
vector<ll> grafo(maxn);
vector<ll> marc(maxn);
vector<ll> arr(maxn);


void dfs(ll v,ll sum, ll k, ll &ans){
    if(k == 0) return;
    marc[v] = 1;
    ans = max(ans, sum + arr[v] * k);
    if(!marc[grafo[v]]) dfs(grafo[v], sum + arr[v], k - 1, ans);
}

void clear(){
    for(int i = 1; i <= maxn; i++) grafo[i] = marc[i] = arr[i] = 0;
}

void solve(){

    cin >> n >> k >> Pb >> Ps;
    clear();

    for(ll i = 1; i <= n; i++){
        ll v; cin >> v;
        grafo[i] = v;
    }

    for(ll i = 1; i <= n; i++) cin >> arr[i];
    
    ll ansb = 0, anss = 0;
    dfs(Pb, 0, k, ansb);
    for(ll i = 1; i <= n; i++) marc[i] = 0;
    dfs(Ps, 0, k, anss);

    if(ansb < anss){
        cout << "Sasha\n";
    }else if(ansb == anss){
        cout << "Draw\n";
    }else{
        cout << "Bodya\n";
    }
    

}

signed main(){
    fastio;
    ll t; cin >> t;
    while (t--) solve();
}