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

    signed main(){
        fastio;
        const ll mod = 1e9+7;
        ll n, K; cin >> n >> K;
        vector<ll> candies(n+1);
        for(ll i = 1; i <= n; i++) cin >> candies[i];
        vector<vector<ll>> dp(n+1, vector<ll>(K+1));
        vector<vector<ll>> psum(n+1, vector<ll>(K+1));

        for(ll i = 0; i <= n; i++) dp[i][0] = psum[i][0] = 1;
        for(ll k = 0; k <= K; k++) psum[0][k] = 1;
        //dp(i,k) = sum dp(i-1, l) (l, indo de 0 até min(k,ai)) 
        //dp(i,k) -> quantas maneiras tem das i primeiras criancas
        //comerem exatamente k balas


        // sort(candies.begin(), candies.end());


        for(ll i = 1; i <= n; i++){
            for(ll k = 1; k <= K; k++){
                if(k-candies[i]-1 < 0) dp[i][k] = psum[i-1][k];
                else dp[i][k] = (psum[i-1][k] - psum[i-1][max(k-candies[i]-1, 0ll)])%mod; 

                psum[i][k] = (psum[i][k-1] + dp[i][k])%mod; 
            }   
        }

        // pr(dp);


        cout << dp[n][K] << "\n";
    }