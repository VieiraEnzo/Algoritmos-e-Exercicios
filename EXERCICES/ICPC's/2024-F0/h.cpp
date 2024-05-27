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

bool prime(int n){
    if(n == 1) return false;
    for(int i = 2; i*i <= n; i++){
        if(n % i == 0) return false;
    }
    return true;   
}

void solve(){
    int n; cin >> n;

    int l = n/2;
    int r = n/2 + 1;
    while (1)
    {
        if(prime(l) || prime(r)){
            l--; r++;
        }else{
            cout << l << " " << r << "\n";
            break;
        }
        if(l < 0 || r > n) {cout << -1 << "\n"; break;}
    }
}

signed main(){
    fastio;
    int t; cin >> t;
    while (t--)
    {
        solve();
    }
}