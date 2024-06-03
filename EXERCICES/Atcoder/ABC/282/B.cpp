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

signed main(){
    fastio;
    int n, m; cin >> n >> m;
    vector<string> prob(n);
    for(int i = 0; i < n; i++){
        cin >> prob[i];
    }

    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            bool good = false;
            for(int k = 0; k < m; k++){
                if(prob[i][k] == 'x' && prob[j][k] == 'x') good = true;
            }

            if(!good) ans++;
        }
    }

    cout << ans << "\n";

}