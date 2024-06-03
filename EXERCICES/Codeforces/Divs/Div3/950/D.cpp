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

int test(vector<int> &v, int remove = -1){
    int n = v.size();
    int last = 0, i;
    for(i = 0; i < n-1; i++){
        if(i == remove) continue;
        if(i == remove-1){
            if(__gcd(v[i], v[i+2]) < last) break;
            last = __gcd(v[i], v[i+2]); continue;
        }
        else if(__gcd(v[i], v[i+1]) < last) break;
        last = __gcd(v[i], v[i+1]);
    }
    return i;
}

void solve(){
    int n; cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    int p = test(v);
    if(p == n-2) {cout << "Yes\n"; return;}
    if(test(v, p) == n-1) {cout << "Yes\n"; return;}
    if(test(v, p-1) == n-1) {cout << "Yes\n"; return;}
    if(test(v, p+1) == n-1) {cout << "Yes\n"; return;}

    cout << "No\n";
    // p-1, p , p+1 podem ser tiradas

    
}

signed main(){
    fastio;
    int t; cin >> t;
    while (t--) solve();
}