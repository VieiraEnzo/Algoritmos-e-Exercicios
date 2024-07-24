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
        string num; cin >> num;
        vector<int> prefsum(n+1);
        prefsum[0] = num[0] - '0';
        for(int i = 1; i < n; i++){
            prefsum[i] += prefsum[i-1] + (num[i] -'0');
        }

        vector<int> ans(2*n);

        for( int i = 0 ; i < 2*n-1; i++){
            if(n-i-1 >= 0) ans[i] += prefsum[n-i-1];
            ans[i+1] += ans[i]/10;
            ans[i] %= 10;
        }

        reverse(ans.begin(), ans.end());

        pr(ans);

        bool first = true;
        for(auto a : ans){
            if(a == 0 && first) continue;
            if(a != 0) first = false;
            cout << a;
        }
        cout << "\n";

    }

    signed main(){
        fastio;
        int t; cin >> t;
        while (t--) solve();
    }