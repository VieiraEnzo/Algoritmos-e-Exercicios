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

void solve(){
    //se tem 2 ou mais 1's , da merda

    int n; cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n ; i++) cin >> v[i];

    sort(v.begin(), v.end());
    if(v[0] == v[1]){
        for(int i = 0; i < n; i++){
            if(v[i] % v[0] != 0){
                cout << "YES\n";
                return;
            }
        }
        cout << "NO\n";
    }else{
        cout << "YES\n";
    }
}

signed main(){
    fastio;
    int t; cin >> t;
    while (t--) solve();
}