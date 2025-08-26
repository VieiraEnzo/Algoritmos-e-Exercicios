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

#define pii pair<ll,ll>
#define upper(v, x) (upper_bound(begin(v), end(v), x) - begin(v))

struct BIT2D{
    vector<ll> ord;
    vector<vector<ll>> bit,coord;
    BIT2D(vector<pii> pts){
        sort(begin(pts),end(pts));
 
        for(auto [x,y] : pts)
            if(ord.empty() || x != ord.back())
                ord.push_back(x);
        
        bit.resize(ord.size() + 1);
        coord.resize(ord.size() + 1);
        
        sort(begin(pts),end(pts), [&](pii &a , pii& b){
            return a.second < b.second;
        });
 
        for(auto [x,y] : pts)
            for(int i = upper(ord,x); i < bit.size(); i += i & -i)
                if(coord[i].empty() || coord[i].back() != y)
                    coord[i].push_back(y);
        
        for(int i = 0; i < bit.size(); i++) bit[i].assign(coord[i].size() + 1,0);
    }
 
    void update(ll X, ll Y, ll v){
        for(int i = upper(ord, X); i < bit.size(); i += i & -i)
            for(int j = upper(coord[i], Y); j < bit[i].size(); j += j & -j)
                bit[i][j] += v;
    }
 
    ll query(ll X, ll Y){
        ll sum = 0;
        for(int i = upper(ord,X); i > 0; i -= i & -i)
            for(int j = upper(coord[i], Y); j > 0; j -= j & -j)
                sum += bit[i][j];
        return sum;
    }
 
    ll queryArea(ll xi , ll yi, ll xf, ll yf){
        return query(xf,yf) - query(xf, yi-1) - query(xi-1, yf) + query(xi-1, yi-1);
    }
};

int main(){
    cin.tie(0), ios_base::sync_with_stdio(false);

    int n; cin >> n;
    vector<pair<ll,ll>> Esq, Dir;
    int iteratord = n/2;
    for(int i = 0; i < iteratord; i++) {ll a,b; cin >> a >> b; Esq.push_back({a,b});}
    for(int j = iteratord; j < n; j++) {ll a,b; cin >> a >> b; Dir.push_back({a,b});}

    ll A1,D1,A2,D2; cin >> A1 >> D1 >> A2 >> D2;

    vector<pair<ll,ll>> resE, resD;

    auto search = [](vector<pair<ll,ll>> &a, vector<pair<ll,ll>> &res){
        int n = a.size();
        for(int i = 0; i < (1<<n); i++){
            ll f = 0, s = 0;
            for(int j = 0; j < n; j++){
                if(i & (1<<j)){
                    f += a[j].first;
                    s += a[j].second;
                }
            }
            res.push_back({f,s});
        }
    };

    search(Esq ,resE);
    search(Dir, resD);

    vector<pii> ptsQ;
    for(auto [a,b] : resE){
        ptsQ.push_back({a,b});
        ptsQ.push_back({A1-a, D1-b});
        ptsQ.push_back({A2-a, D2-b});
    }

    for(auto [a,b] : resD){
        ptsQ.push_back({a,b});
    }

    BIT2D bt(resD);

    for(auto [a,b] : resD){
        bt.update(a,b,1);
    }

    ll ans = 0;
    for(auto [a,b] : resE){
        ll lf = A1-a;
        ll ls = D1-b;
        ll rf = A2-a;
        ll rs = D2-b;
        ans = ans + bt.queryArea(lf,ls, rf,rs);
    }   
    cout << ans << "\n";

    return 0;
}