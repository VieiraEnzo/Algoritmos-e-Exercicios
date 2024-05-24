#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pii;
typedef pair<ll,ll> pll;

void solve(){
    ll a,b,c; cin >> a >> b >> c;

    ll height = -1, livres = 1;

    while (livres > 0)
    {
        ll obt = 0;
        if(a > 0) {ll at = (min(livres,a)); obt += 2*at; a -= at; livres -= at;}
        if(b > 0) {ll at = (min(livres,b)); obt += 1*at; b -= at; livres -= at;}
        if(c > 0) {ll at = (min(livres,c)); c -= at; livres -= at;}
        if(obt == 0 && livres > 0) {cout << -1 << "\n"; return;} 
        livres += obt;
        height++;
        // cout << a << " " << b << " " << c << "\n";
    }

    if(a || b || c) {cout << -1 << "\n"; return;}
    
    cout << height << "\n";


}

int main(){
    fastio;
    ll t; cin >> t;
    while (t--)
    {
        solve();
    }
    
}