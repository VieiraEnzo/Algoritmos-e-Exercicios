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
    int n, m; cin >> n >> m;
    string a; cin >> a;
    set<int> s;
    for(int i = 0; i < m; i++) {int temp; cin >> temp; s.insert(temp-1);}
    string c; cin >> c;
    sort(c.begin(), c.end());

    int i = 0;
    for(auto ind : s){
        a[ind] = c[i];
        i++;
    }

    cout << a << "\n";
}

signed main(){
    fastio;
    int t; cin >> t;
    while (t--) solve();
}