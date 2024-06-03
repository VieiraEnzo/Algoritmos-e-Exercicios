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

void solve(){
    int n; cin >> n;
    vector<int> found(n);
    for(int i = 0; i < n; i++) cin >> found[i];
    vector<int> orig(n);
    set<int> Sorig;
    for(int i = 0; i < n; i++) {cin >> orig[i]; Sorig.insert(orig[i]);}
    int m; cin >> m;
    vector<int> modif(m);
    for(int i = 0; i < m; i++) cin >> modif[i];
    
    multiset<int> need;
    for(int i = 0; i < n; i++){
        if(orig[i] != found[i]) need.insert(orig[i]);
    }


    bool before = false;
    for(int i = m-1; i >= 0; i--){
        auto it = need.find(modif[i]);
        auto it2 = Sorig.find(modif[i]);
        if(it2 != Sorig.end() || it != need.end()) before = true;

        if(it != need.end()) need.erase(it);
        else if(!before) {cout << "No\n"; return;}
    }

    // pr(need);

    if(need.size() > 0){
        cout << "No\n";
    }else{
        cout << "Yes\n";
    }

}

signed main(){
    fastio;
    int t; cin >> t;
    while (t--) solve();
}