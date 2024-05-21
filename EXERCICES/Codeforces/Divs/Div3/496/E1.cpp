#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pii;
typedef pair<ll,ll> pll;

int main(){
    fastio;
    ll n, m; cin >> n >> m;
    vector<ll> perm(n+1);
    for(ll i = 1; i <= n; i++) cin >> perm[i];

    map<ll,ll> quant;
    quant[0]++;
    vector<ll> sv(n+1);
    sv[0] = 0;

    ll ans = 0;
    bool saiu = false;
    for(ll i = 1; i <= n; i++){
        if(perm[i] < m){
            sv[i] = sv[i-1] + 1;
        }else if(perm[i] > m){
            sv[i] = sv[i-1] -1;
        }else{
            sv[i] = sv[i-1];
            saiu = true;
        }

        if(saiu){
            ans += (quant[sv[i]] + quant[sv[i]+1] );
        }else{
            quant[sv[i]]++;
        }
        // cout << i << ": "  << ans << " " << sv[i] << " "  << quant[sv[i]] << "\n";
        // if(perm[i] == m) continue;
    }

    cout << ans << "\n";
}