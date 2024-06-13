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


ll fastexp(ll b, ll e, ll mod){
        ll res = 1;
        while (e)
        {
            if(e&1) res=(res*b)%mod;
            b=(b*b)%mod;
            e>>=1;
        }
        return res;
}

void solve(){
    int l, r, k; cin >> l >> r >> k;

    int qts = 0;
    for(int i = 1; i < 10; i++) if(k * i < 10) qts++;

    // a0 + a0*2 + a0*2*2 + ...
    //a0 * (1 + 2 + 2*2 + ...)
    //a0 * Pg(rz^n - 1)

    // 2 + 2*3 + 2*3*3
    // 1 + 1*2

    // 8 + 8*9
    //a0 * (1+9)  

    int mod = 1e9+7;
    int a0 = qts;
    int razao = qts+1;
    int Pg =  (a0 * (fastexp(razao, r, 1e9+7)-1))/(razao-1);
    int Pg2 = (a0 * (fastexp(razao, l, 1e9+7)-1))/(razao-1);

    cout << (Pg-Pg2+mod)%mod << "\n";

}

signed main(){
    fastio;
    int t; cin >> t;
    while (t--) solve();
}