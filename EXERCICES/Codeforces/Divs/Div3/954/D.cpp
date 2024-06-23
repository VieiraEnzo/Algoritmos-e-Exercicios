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
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

void solve(){
    int n; cin >> n;
    string s; cin >> s;

    // if(n == 2) {cout << s << "\n";return;}

    int resp = 1e9;
    for(int i = 0; i < n-1; i++){
        vector<int> v;
        for(int k = 0; k < s.size(); k++){
            string c; c += s[k]; 
            if(k == i){
                c+= s[k+1];
                v.push_back(stoi(c));
                k++;
            }else
                v.push_back(stoi(c));
        }

        pr(v);

        int ans = v[0];
        for(int j = 0; j < v.size()-1; j++){
            if(ans == 0) break;
            if(v[j+1] == 1 || v[j+1] == 0 || ans == 0 || ans == 1){
                ans *= v[j+1];
            }else{
                ans += v[j+1];
            }
        }
        resp = min(resp, ans);
    }

    cout << resp << "\n";
}

signed main(){
    fastio;
    int t; cin >> t;
    while (t--) solve();
}