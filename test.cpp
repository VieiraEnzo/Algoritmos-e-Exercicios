#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int MOD = 1e9 + 7;


ull interpolate(vector<pair<ll,ll>> &P, int x){

    ll ans = 0;
    for(int i = 0; i < P.size(); i++){
        ll li = 1;
        for(int j = 0; j < P.size(); j++){
            if(i == j) continue;
            li *= (x - P[j].first);
            li /= (P[i].first - P[j].first);
        }
        ans += P[i].second * li;
        cout << ans << endl;
    }
    return ans;

}



ll fastexp(ull b, ull e, ull m = MOD){

    ull res  = 1;
    while (e)
    {
        if(e&1) res = (res*b)%m;
        b=(b*b)%m;
        e>>=1;
    }
    return res;
}




int main(){

    ull n , k; cin >> n >> k;
    
    vector<pair<ll,ll>> sum(k+2);
    for(int i = 0; i< k+2; i++)sum[i].first = i;

    sum[0].second = 0;
    for(ull i = 1; i < k+2; i++){
        sum[i].second = sum[i-1].second + fastexp(i,k);
    }

    cout << interpolate(sum, n) << endl;

}