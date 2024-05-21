#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int main(){
    fastio;
    string s; cin >> s;
    int n = s.size();
    vector<int> sp(n);
    int r = -1;
    vector<int> save(3, -1e9);
    save[0] = 0;

    int ans = 0;
    save[s[0]%3] = 0; 
    if(s[0]%3 == 0) ans++;
    sp[0] = s[0]%3;

    for(int i = 1; i < n; i++){
        sp[i] += (sp[i-1] + (s[i]-'0'))%3;
        if(save[sp[i]] >= r) {r = i; ans++;}
        save[sp[i]] = i;
    }
    
    cout << ans << "\n";
}