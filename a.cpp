#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifdef local
    #include "/home/enzo/Documents/Prog/OBItraining/debug.h"
    #define pr(...) debug(#__VA_ARGS__, __VA_ARGS__)
    #define prs(...) debug_nameless(__VA_ARGS__)
#else
    #define pr(...) 69
    #define prs(...) 69
#endif

const int M = 1e9+7;
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
const ll B = uniform_int_distribution<ll>(0, M - 1)(rng);
const ll B2 = uniform_int_distribution<ll>(0, M - 1)(rng);


template<int MOD> struct Hashing{
    ll base, base2 ,n;
    vector<ll> pow, ha, pow2, hb; 

    Hashing(string & s, int a, int b) : n(s.size()), base(a), base2(b) ,pow(n+1), ha(n+1), pow2(n+1), hb(n+1){

        pow[0] = pow2[0] = 1;
        for(int i = 0; i < n; i++){
            ha[i+1] = (ha[i] * base + s[i])%MOD;
            pow[i+1] = (pow[i] * base)%MOD;
            hb[i+1] = (hb[i] * base2 + s[i])%MOD;
            pow2[i+1] = (pow2[i] * base2)%MOD;
        }
    }
    
    ll getRange(int a, int b){
        assert(a <= b);
        ll hash =  (ha[b] - (ha[a] * pow[b-a])%MOD)%MOD;
        ll hash2 =  (hb[b] - (hb[a] * pow2[b-a])%MOD)%MOD;
        hash = hash < 0 ? hash + MOD : hash;
        hash2 = hash2 < 0 ? hash2 + MOD : hash2;
        return (hash<<32)|(hash2);
    }

    int size(){
        return n;
    }
    
};

int main(){

    cin.tie(0), ios_base::sync_with_stdio(false);
    
    int n, m; cin >> n >> m;
    string s; cin >> s;
    s += s;
    Hashing<M> h(s, B, B2);

    vector<Hashing<M>> arr;
    for(int i = 0; i < m; i++){
        string a; cin >> a;
        arr.emplace_back(a,B, B2);
    }

    auto f = [&](const int x){

        set<ll> st;
        for(int k = 0; k < m; k++){
            for(int j = 0; j+x <= arr[k].size(); j++){
                st.insert(arr[k].getRange(j, j+x));
            }
        }

        vector<int> ans(s.size());
        for(int i = 0; i+x <= s.size(); i++){
            if(st.find(h.getRange(i, i+x)) != st.end()){
                ans[i] = 1;
            }
        }

        for(int i = 1; i < s.size(); i++){
            ans[i] += ans[i-1];
        }

        ans.insert(ans.begin(), 0);
        for(int i = 1; i <= n; i++){
            if(ans[i+n-x] - ans[i-1] <= 0){
                return false;
            }
        }

        return true;
    };  

    int l = 0, r = n+1;
    while(r-l > 1){
        int mid = (r+l)/2;
        if(f(mid)){ //Todos os cs tem esse uma substring com esse tamanho
            l = mid;
        }else{
            r = mid;
        }
    }

    cout << l << "\n";

}
