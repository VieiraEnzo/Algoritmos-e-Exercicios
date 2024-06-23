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
    int x1, x2, x3; cin >> x1 >> x2 >> x3;
    
    int ans = 0, value = 1e9;
    for(int i = 0; i < 100; i++){
        if((abs(x1-i)) + abs(x2-i) + abs(x3-i) < value){
            ans = i;
            value = (abs(x1-i)) + abs(x2-i) + abs(x3-i);
        }
    }

    cout << value << "\n";

}

signed main(){
    fastio;
    int t; cin >> t;
    while (t--) solve();
}