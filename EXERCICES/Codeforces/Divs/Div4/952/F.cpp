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

int f(int mid, vector<int> &atk, vector<int> &cld){
    int sum = 0;
    for(int i = 0; i < atk.size(); i++){
        sum += ((mid-1)/cld[i] + 1) * atk[i];
    }
    return sum;
}

void solve(){
    int h, n; cin >> h >> n;
    vector<int> atk(n), cld(n);
    for(int i = 0; i < n; i++) cin >> atk[i];
    for(int i = 0; i < n; i++) cin >> cld[i];

    int l = 0, r = 1e12;
    while (r - l > 1)
    {   
        int mid = (l+r)/2;
        if(f(mid, atk, cld) < h){
            l = mid;
        }else{
            r = mid;
        }
    }
    cout << r << "\n";
    

}

signed main(){
    fastio;
    int t; cin >> t;
    while (t--) solve();
}