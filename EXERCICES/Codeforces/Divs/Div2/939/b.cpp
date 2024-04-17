#include <bits/stdc++.h>

using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

void solve(){
    int n; cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end());
    int ans = 0;
    for(int i = 0; i < n-1; i++){
        if(v[i] == v[i+1]) ans++;
    }
    cout << ans << "\n";
}


int main(){
    fastio;
    int t; cin >> t;
    while (t--)
    {
        solve();
    }
    
    

}