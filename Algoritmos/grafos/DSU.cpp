template<typename T> struct DSU
{
    ll n;
    vector<ll> pai, rank;

    DSU(ll n) : n(n), pai(n+1), rank(n+1,1){
        for(ll i = 1; i <=n; i++){
            pai[i] = i;
        }
    }

    ll find(ll a){
        if(pai[a] == a) return a;
        return pai[a] = find(pai[a]);
    }

    void uu(ll a, ll b){
        a = find(a), b = find(b);
        if(a == b) return;
        if(rank[a] > rank[b]) swap(a,b);
        rank[b] += rank[a];
        pai[a] = b;
    }

};