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

struct item
{
    int bitSig;
    int maxForm;
};


void solve(){
    int n; cin >> n;
    vector<item> r(n);
    int base = 0;
    for(int i = 0; i < n;i++){
        int maxI = 0;
        int temp; cin >> temp;
        for(int j = 31; j >= 0; j--){
            if(temp & (1<<j)){
                maxI = j; break;
            }
        }
        base = max(base, maxI);
        r[i] = {maxI, temp};
    }

    for(int i = 0; i < n; i++){
        int dif = base - r[i].bitSig;
        r[i].maxForm <<= dif;
    }

    int ans = 0;

    for(int i = 1; i < n; i++){
        if(r[i].bitSig < r[i-1].bitSig){
            int dif = r[i-1].bitSig - r[i].bitSig;
            r[i].bitSig += dif; ans += dif;
        }
        if(r[i].maxForm < r[i-1].maxForm){r[i].bitSig++; ans++;}
    }

    // for(int i = 0; i < n; i++){
    //     cout << r[i].bitSig << " " << r[i].maxForm << "\n";
    // }

    cout << ans << "\n";

}

signed main(){
    fastio;
    int t; cin >> t;
    while (t--)solve();
    
}