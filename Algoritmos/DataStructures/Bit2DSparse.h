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
