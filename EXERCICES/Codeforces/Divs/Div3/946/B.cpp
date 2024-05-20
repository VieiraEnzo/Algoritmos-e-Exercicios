#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

void solve(){
    int n; cin >> n;
    string s, r; cin >> s;
    vector<int> marc(30);
    for(int i = 0; i < n; i++){ 
        if(!marc[s[i] - 'a']){
            r.push_back(s[i]);
            marc[s[i]- 'a'] = 1;}}   

    sort(all(r));        

    // for(auto a : r){cout << a;}
    // cout << endl;

    map<char,char> mp;
    for(int i = 0; i < r.size(); i++){
        mp[r[i]] = r[r.size()-i-1];
    }

    for(int i =0; i < n; i++){
        cout << mp[s[i]];
    }cout << "\n";

}

int main(){
    fastio;
    int t; cin >> t;
    while (t--) solve();
}