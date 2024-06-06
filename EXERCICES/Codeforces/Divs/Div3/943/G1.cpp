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

const int md = 1e9+7;
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
const ll B = uniform_int_distribution<ll>(0, md - 1)(rng);

template<int MOD> struct Hashing{
    ll base, n;
    vector<ll> pow, ha; 

    
    //for random base:
    

    Hashing(string &s, int base) : n(s.size()), base(base) ,pow(n+1), ha(n+1){

        pow[0] = 1;
        for(int i = 0; i < n; i++){
            ha[i + 1] = (ha[i] * base + s[i])%MOD;
            pow[i+1] = (pow[i] * base)%MOD;
        }

    }
    
    int getRange(int a, int b){
        assert(a <= b);
        ll hash =  (ha[b] - (ha[a] * pow[b-a])%MOD)%MOD;
        return hash < 0 ? hash + MOD : hash;
    }
    
};
string s;

int test(int mid, Hashing<md> &hash){
    int pref = hash.getRange(0,mid);
    int n = s.size();
    int ans = 1;
    for(int i  = mid; i + mid<= n; i++){
        if(hash.getRange(i, i+mid) == pref){
            i = i + mid - 1;
            ans++;
            continue;
        }
    }
    return ans;
}

void solve(){
    int n, b; cin >> n >> b >> b;
    cin >> s;
    Hashing<md> hash(s, B);

    int l = 0, r = n+1;
    while (r - l > 1)
    {   
        int mid = (l + r)/2;
        if(test(mid, hash) >= b){
            l = mid;
        }else{
            r = mid;
        }
    }
    cout << l << "\n";
}

signed main(){
    fastio;
    int t; cin >> t;
    while (t--) solve();
    
    

}