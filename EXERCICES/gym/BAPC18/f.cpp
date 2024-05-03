#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll maxn = 1e5 + 10;
vector<pair<ll,ll>> inv(maxn); 
ll n, m;

bool check(ll dias);

ll bbsearch(){
    ll l = 0, r = 2e9+100;
    while (l < r)
    {
        ll mid = (l+r)/2;
        if(check(mid)){
            r = mid;
        }else{
            l = mid+1;
        }
    }
    return l;
}

bool check(ll dias){

    ll sum = 0;
    for(int i = 0; i < n; i++){
        ll p = inv[i].first;
        ll c = inv[i].second;
        if(sum >= m + c - p*dias) return true;
        sum += (p*dias - c) > 0? (p*dias -c) : 0;
    }
    if(sum >= m) return true;
    return false;

}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        ll t1,t2; cin >> t1>>t2;
        inv[i] = {t1,t2};
    }

    cout << bbsearch() << endl;

}