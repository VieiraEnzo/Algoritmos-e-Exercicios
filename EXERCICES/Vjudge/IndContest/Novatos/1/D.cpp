#include <bits/stdc++.h>

using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pii;
typedef pair<ll,ll> pll;

ll uncript(vector<ll> &now){
    ll ans = 0;
    for(ll i = 0; i < 10; i++){
        ans += (now[i] << i);
    }
    return ans;
}


int main(){
    fastio;
    string s; cin >> s;
    vector<ll> sv(2<<11);

    ll ans = 0;
    vector<ll> now(10);
    for(ll i = 0; i < s.size(); i++){
        ll num = s[i] - '0';
        now[num] ^= 1;
        ans += sv[uncript(now)];
        sv[uncript(now)]++;
    }

    ans += sv[0];

    cout << ans << endl;

    

}