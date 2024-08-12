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
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

bool compare(pii a, pii b){
    if(b.second != a.second) return a.second < b.second;
    return a.first < b.first;
}

void solve(){
    int n, m, k; cin >> n >> m >> k;
    vector<pair<int,int>> fontes(k), original;
    for(auto &a : fontes){
        cin >> a.first >> a.second;
        original.push_back({a.first, a.second});
    }
    sort(all(fontes), compare);
    map<pair<int,int>, int> ans;
    for(auto a : fontes) ans[a] = 1;

    for(int i = 0; i < k-1; i++){
        int xi = fontes[i].second;
        int xd = fontes[i+1].second;
        if(xi == xd) ans[fontes[i]] = 0; 
    }

    ll area = 0;
    ll xcur = 0, ycur = 1;
    for(int i = 0; i < fontes.size(); i++){
        ll y = fontes[i].first;
        ll x = fontes[i].second-1ll;
        if(x == xcur){
            ycur = y+1ll;
            continue;
        }
        if(y < ycur){
            ans[fontes[i]] = 0;
            continue;
        }
        area += (x-xcur) * (n-ycur+1ll);
        xcur = x;
        ycur = y+1ll;
        // if(ycur > n) break;
    }
    if(xcur != m && ycur <= n){
        area += (m-xcur) * (n-ycur+1);
    }



    cout << area << "\n";
    for(int i = 0; i < k; i++){
        cout << ans[original[i]] << " ";
    }cout << "\n";

}

signed main(){
    fastio;
    int t; cin >> t;
    while (t--) solve();
}