#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n; cin >> n; int temp;
    vector<pair<ll,ll>> a(n);for(int i= 0; i < n; i++) {cin >> temp; a[i] = make_pair(temp, i);}
    vector<pair<ll,ll>> b(n);for(int i= 0; i < n; i++) {cin >> temp; b[i] = make_pair(temp, i);}
    vector<pair<ll,ll>> c(n);for(int i= 0; i < n; i++) {cin >> temp; c[i] = make_pair(temp, i);}
    sort(a.rbegin(), a.rend());
    sort(b.rbegin(), b.rend());
    sort(c.rbegin(), c.rend());

    ll ans = 0;
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            for(int k = 0; k < 3; k++){
                if(a[i].second == b[j].second || a[i].second == c[k].second || c[k].second == b[j].second) continue;
                ans = max(ans, a[i].first + b[j].first + c[k].first);
            }

    cout << ans << endl;
}



int main(){
    int t; cin >> t;
    while (t--)
    {
        solve();
    }
    

}