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
typedef pair<ll,ll> pii;
typedef pair<ll,ll> pll;

void solve(){
    ll n, k; cin >> n >> k;
    vector<ll> v(n);
    for(ll i = 0; i < n; i++) cin >> v[i];
    if(n == 1) {cout << 0 << "\n"; return;}
    
    sort(all(v));
    ll sobrando = n%2;
    map<ll,vector<ll>> cnt;
    for(ll i = 0; i < n; i++){
        cnt[v[i]%k].push_back(v[i]);
    }
    for(auto &a : cnt){
        if(a.second.size() % 2 == 1){
            if(sobrando) sobrando--;
            else {cout << -1 << "\n";return;}
        }
    }

    pr(cnt);

    ll ans = 0;
    for(auto &a : cnt){
        if(a.second.size() == 1) continue;

        ll t = a.second.size();
        if(t %2 == 0){
            ll resp = 0;
            for(ll i = 0; i+1 < a.second.size(); i+= 2){
                resp += (a.second[i+1] - a.second[i])/k;   
            }
            ans+= resp;
        }else{
            ll n = a.second.size();
            vector<ll> pref(t + 4);
            vector<ll> prefinv(t + 4);
            pref[1] = (a.second[1] - a.second[0])/k;
            for(ll i = 3; i < t; i+= 2){
                pref[i] = (a.second[i] - a.second[i-1])/k + pref[i-2];
            }

            prefinv[n-2] = (a.second[n-1] - a.second[n-2])/k;
            for(ll i = n-4; i >= 0; i-= 2){
                prefinv[i] = (a.second[i+1] - a.second[i])/k + prefinv[i+2];   
            }

            pr(pref, prefinv);

            ll resp = 1e9;
            for(ll i = 0; i < a.second.size(); i++){
                if(i == 0){
                    resp = min(resp, prefinv[1]);
                }else if(i == n-1){
                    resp = min(resp, pref[n-2]); 
                }
                else if(i%2 == 1){
                    if(i - 2 < 0) resp = min(resp, (a.second[i+1] - a.second[i-1])/k + prefinv[i+2]);
                    else{
                        ll cal = (a.second[i+1] - a.second[i-1])/k + prefinv[i+2] + pref[i-2];
                        resp = min(resp, cal);
                    }
                }else{
                    if(i-1 < 0) resp = min(resp, prefinv[i+1]);
                    else resp = min(resp, pref[i-1] + prefinv[i+1]);
                }
            }
            
            ans += resp;
        }
    }
    
    cout << ans << "\n";
    
}

signed main(){
    fastio;
    ll t; cin >> t;
    while (t--) solve();
}