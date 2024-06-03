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
    int n, m; cin >> n >> m;
    vector<vector<int>> orig(n, vector<int>(m));
    vector<vector<int>> goal(n, vector<int>(m));

    vector<pair<int,int>> sv((n+1) * (m+1));

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
            cin >> orig[i][j];
            sv[orig[i][j]] = {i,j};
        }

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) 
            cin >> goal[i][j];

    //checar se as linhas batem 
    for(int i = 0; i < n; i++){
        int last = sv[goal[i][0]].first;
        for(int j = 1; j < m; j++){
            if(sv[goal[i][j]].first != last) {cout << "No\n"; return;}
        } 
    }

    for(int j = 0; j < m; j++){
        int last = sv[goal[0][j]].second;
        for(int i = 1; i < n; i++){
            if(sv[goal[i][j]].second != last) {cout << "No\n"; return;}
        } 
    }

    cout << "Yes\n";
}

signed main(){
    fastio;
    int t; cin >> t;
    while (t--) solve();
}