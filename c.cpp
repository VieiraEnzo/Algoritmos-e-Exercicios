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
        int n, m; cin >> n >> m;
        vector<int> dp(n+1);
        
        vector<vector<int>> abre(n+1);
        for(int i = 0; i < m; i++){
            int a,b; cin >> a >> b;
            abre[a-1].push_back(b-1);  
        }

        multiset<int> abertos;
        vector<int> next(n+1);
        vector<int> quantidadeGatos(n+1);

        for(int i = 0; i < n; i++){
            for(auto a : abre[i]) abertos.insert(a);

            if(abertos.size() == 0) {next[i] = i+1; continue;}

            int maior = *(--abertos.end());

            next[i] = maior + 1;

            quantidadeGatos[i] = abertos.size();

            abertos.erase(i);

        }


        for(int i = n-1; i>= 0; i--){
            dp[i] = max(quantidadeGatos[i] + dp[next[i]], dp[i+1]);
        }

        cout << dp[0] << "\n";

    }

    signed main(){
        fastio;
        int t; cin >> t;
        while (t--) solve();
    }