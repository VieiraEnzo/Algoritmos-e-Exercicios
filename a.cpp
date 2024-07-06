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

bool explore(int k, int m){
    if(k == m) return true;
    if(k%3 != 0) return false;
    return explore(k/3, m) || explore(2*(k/3), m);
}

void solve(){
    int n, m; cin >> n >> m;
    
    if(explore(n,m)){
        cout << "YES\n";
    }else{
        cout << "NO\n";
    }
}

signed main(){
    fastio;
    int t; cin >> t;
    while (t--) solve();
}