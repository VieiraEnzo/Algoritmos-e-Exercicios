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
    // N + S % 2 == 0
    // E + W % 2 == 0
    string  s; cin >> s;
    map<char,int> c;
    int N = 0, S= 0, E = 0, W = 0;
    for(int i = 0 ; i < n; i++){
        if(s[i] == 'N')c['N']++;
        if(s[i] == 'S')c['S']++;
        if(s[i] == 'W')c['W']++;
        if(s[i] == 'E')c['E']++;
    }

    map<char,int> H;
    map<char,int> R;

    int movH = 0, movR = 0;
    for(auto &a : c){
        H[a.first]+= a.second/2;
        movH += a.second/2;
        R[a.first]+= a.second/2;
        movR += a.second/2;
        c[a.first] %= 2;        
    }

    if(c['N'] && c['S'] && c['W'] && c['E']){
        H['N'] += c['N'];
        H['S'] += c['S'];
        R['W'] += c['W'];
        R['E'] += c['E'];
        c.clear();
        movH+=2; movR+=2;
    }

    if(movH == 0 || movR == 0){cout << "NO\n"; return;}
    if((c['N'] + c['S'])%2 == 1 || (c['W'] + c['E'])%2 == 1){cout << "NO\n"; return;}

    H['N'] += c['N'];
    H['S'] += c['S'];
    H['W'] += c['W'];
    H['E'] += c['E'];

    for(int i = 0; i < n; i++){
        if(H[s[i]] > 0){
            cout << "H";
            H[s[i]]--;
        }else{
            cout << "R";
        }
    }

    cout << "\n";

}

int main(){
    fastio;
    int t; cin >> t;
    while (t--) solve();
}