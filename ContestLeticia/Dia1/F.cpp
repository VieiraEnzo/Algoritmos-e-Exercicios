#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(ll n){
    multiset<pair<ll,ll>> retas;
    for(ll i = 0; i < n; i++){
        ll x, y; cin >> x >> y;
        retas.insert({1,y-x});
        retas.insert({-1,y+x});
    }

    long long pontos = 0;
    long long ans = 0;

    for(auto i = retas.begin(); i != prev(retas.end()); i++){
        if((*i).first == (*next(i)).first && (*i).second == (*next(i)).second){
            pontos++;
        }else{
            ans += (ll)(pontos+1)*(ll)(pontos);
            pontos = 0;
        }
    }
    ans += (ll)(pontos+1)*(ll)(pontos);
    pontos = 0;

    ll total = (ll) n * (ll) n;
    cout << fixed  << setprecision(7) << (long double)(ans)/(long double) (total) << endl;

}


int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll t; 
    while(cin >> t){
        solve(t);
    }
}