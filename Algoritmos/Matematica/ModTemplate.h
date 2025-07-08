const int mod = 1e9+7;

const int maxn = 1e6;
vector<ll> fact(maxn+1), ifact(maxn+1);

ll fastexp(ll x, ll e){
    ll ans = 1;
    while(e){
        if(e&1) ans = (ans * x)%mod;
        x = (x * x)%mod;
        e/=2;
    }
    return ans;
};

ll inv(ll x){
    return fastexp(x, mod-2);
};

void build(){

    fact[0] = 1;
    for(int i = 1; i <= maxn; i++) fact[i] = (fact[i-1] * i)%mod;
    ifact[maxn] = inv(fact[maxn]);
    for(int i = maxn-1; i >= 0; i--) ifact[i] = (ifact[i+1] * (i+1))%mod;

}