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

    char mat[n][m];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> mat[i][j];
        }
    }

    int maxsum = 0;
    vector<pair<int,int>> primeiro(n);
    int loc = -1;
    for(int i = 0; i < n; i++){
        int sum = 0; bool first = true;
        for(int j = 0; j < m; j++){
            sum += (mat[i][j] == '#');
            if(sum == 1 && first) {primeiro[i] = {i,j}; first = false;}
        }
        if(sum > maxsum) {maxsum = sum; loc = i;}
    }


    cout << primeiro[loc].first + 1 << " " << (primeiro[loc].second + (maxsum/2))  + 1<< "\n";
}

signed main(){
    fastio;
    int t; cin >> t;
    while (t--) solve();
}