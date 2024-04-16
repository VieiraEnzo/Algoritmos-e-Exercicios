#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n, q; cin >> n >> q;
    vector<ll> sum(q+1);
    vector<ll> enter(n+1);
    vector<ll> resp(n+1);
    vector<vector<pair<ll,ll>>> EnSai(n+1, vector<pair<ll,ll>> {{-1,-1}});
    set<ll> s;
    for(ll i = 1; i <= q; i++){
        ll a; cin >> a;
        if(s.count(a) > 0){s.erase(a); resp[a] += (sum[i-1] - sum[enter[a]-1]); }
        else {s.insert(a); enter[a] = i;}
        sum[i] = sum[i-1] +  s.size();
    }

    for(auto a : s){
        resp[a] += sum[q] - sum[enter[a]-1];
    }

    for(ll i = 1; i <= n; i++){
        cout << resp[i] << " ";
    }
}