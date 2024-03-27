#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;

void solve(){
    int n; cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++)cin>>v[i];
    sort(v.begin(), v.end());

    ll ans = 0;
    for(int i = 1; i < n; i++){
        ans+= v[i] - v[i-1];  
    }

    cout << ans << endl;
}   



int main(){
    
    fastio;

    int t; cin >> t;
    while (t--)
    {
        solve();
    }

}