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
typedef pair<int,int> pii;
const int mod = 1e9 + 7;

int add(int a, int b) { a += b; if (a >= mod) a -= mod; return a; }
int sub(int a, int b) { a -= b; if (a < 0) a += mod; return a; }
int mul(int a, int b) { return 1ll * a * b % mod; }
int Pow(int a, int b) { int ans = 1; for (; b; b >>= 1, a = mul(a, a)) if (b & 1) ans = mul(ans, a); return ans; }

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){

}

signed main(){
    fastio;
    int t; cin >> t;
    while (t--) solve();
}