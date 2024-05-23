#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int check(string &s,int sz){
    string c = s.substr(0,sz);

    string k;
    for(int j = 0; j < s.size()/sz; j++){
        k.append(c);
    }
    
    int dif = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] != k[i]) dif++;
    }
    
    return dif;
}

int check2(string &s,int sz){
    string c;
    for(int i = 0; i < sz; i++) c.push_back(s[s.size()-1-i]);
    reverse(all(c));

    string k;
    for(int j = 0; j < s.size()/sz; j++){
        k.append(c);
    }
    
    int dif = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] != k[i]) dif++;
    }
    
    return dif;
}

void solve(){
    int n; cin >> n;
    string s; cin >> s;

    for(int i = 1; i <= n; i++){
        if(n%i == 0){
            if(check(s, i) <= 1 || check2(s, i) <= 1){
                cout << i << "\n";
                break;
            }
        }
    }
}

int main(){
    fastio;
    int t; cin >> t;
    while (t--) solve();
}