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

void solve(){
    
    int n; cin >> n;

    vector<array<int,2>> pts(n+2);
    for(int i = 0; i < n; i++){
        int x, y; cin >> x >> y;
        pts[x][y]++;
    }

    vector<ll> pref0(n+1), pref1(n+1);
    vector<ll> suf0(n+2), suf1(n+2);

    pref0[0] = pts[0][0];
    pref1[0] = pts[0][1];
    for(int i = 1; i <= n; i++){
        pref0[i] = pref0[i-1] + pts[i][0];
        pref1[i] = pref1[i-1] + pts[i][1];
    }

    for(int i = n; i >= 0; i--){
        suf0[i] = suf0[i+1] + pts[i][0];
        suf1[i] = suf1[i+1] + pts[i][1];
    }

    ll ans = 0;
    for(int i = 0; i <= n; i++){
        if(pts[i][0] && pts[i][1]){
            if(i-1 >= 0){  
                ans += pref0[i-1];
                ans += pref1[i-1];
            }
            if(i+1 <= n){
                ans += suf0[i+1];
                ans += suf1[i+1];
            }
        }
    }

    for(int i = 1; i < n; i++){
        if(pts[i][0] && pts[i-1][1] && pts[i+1][1]){
            ans++;
        }
        if(pts[i][1] && pts[i-1][0] && pts[i+1][0]){
            ans++;
        }

    }

    cout << ans << "\n";
}   

signed main(){
    fastio;
    int t; cin >> t;
    while (t--) solve();
}