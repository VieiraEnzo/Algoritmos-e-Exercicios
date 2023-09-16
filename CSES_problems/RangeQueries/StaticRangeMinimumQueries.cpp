#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;

ll mlog2(ll n)
{   
    if(n<=0) return -1000;
    int res = -1;
    while (n > 0)
    {
        n/=2;
        res++;
    }
    return res;
    
}


ll fastexp(ll b, ll e)
{
    ll res =1;
    while (e)
    {
        if(e&1) res = (res*b);
        b=(b*b);
        e>>=1;
    }
    return res;
}



int main(){
    fastio;
    ll n, q; cin >> n >> q;
    vector<ll> v(n);
    for(ll i =0; i <n; i ++) cin >> v[i];
    vector<vector<ll>> m(n);

    // STATIC RANGE MINIMUM QUERRY
    for(ll i =0; i <n-1;i++)
    {
        m[i].push_back(min(v[i],v[i+1]));
    }
    for(ll j =2; j < n-1; j*=2)
        for(ll i =0; i < n-1; i++){
            if(i + j > n-1) continue;
            m[i].push_back(min(m[i].back(), m[i+j-1].back()));
        }
    
    //QUERIES
    while (q--)
    {
        ll i,j; cin >> i >> j;
        i--;j--;
        ll range = (j - i);
        ll res = 1e18;
        while (range >= 0)
        {
            if(range == 0) {res = min(res, v[i]);break;}
            ll a = mlog2(range);
            res = min(res, m[i][a]);
            i = (i+fastexp(2,a));
            range = j-i;

        }
        cout << res << endl;
        
        
    }
    

}