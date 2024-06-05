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

void solve(){
    int n, q; cin >> n >> q;
    vector<int> pref(n+1);
    set<pair<int,int>> s;
    pref[0] = 0;
    s.insert({pref[0], 0});
    for(int i = 1; i <= n; i++){
        cin >> pref[i];
        pref[i] ^= pref[i-1];
        s.insert({pref[i], i});
    }
    
    while (q--)
    {
        int l, r; cin >> l >> r;
        if((pref[r] ^ pref[l-1]) == 0){
            cout << "Yes\n";
        }else{
            pr(l, r);
            int x = pref[r] ^ pref[l-1];
            auto it = s.lower_bound({x ^ pref[l-1], l});
            pr(*it);
            if(it == s.end() || (*it).second >= r || (*it).first != (x ^ pref[l-1])) { cout << "No\n"; continue;}
            l = (*it).second + 1;
            it = s.lower_bound({x ^ pref[l-1], l});
            pr(*it);
            if(it == s.end() || (*it).second >= r  || (*it).first != (x ^ pref[l-1])){ cout << "No\n"; continue;}
            cout << "Yes\n";
        }

    }
    

}

signed main(){
    fastio;
    int t; cin >> t;
    while (t--) solve();
}