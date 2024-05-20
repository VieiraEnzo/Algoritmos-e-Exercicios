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
    int x, y; cin >> x >> y;

    int sobra = 0;
    int scren = 0;
    while (y > 0)
    {
        scren++;
        if(y == 1) sobra += 11;
        else sobra += 7;
        y -= 2;
    }

    x -= sobra;

    while (x > 0)
    {
        scren++;
        x -= 15;
    }
    
    
    cout << scren << "\n";

}

int main(){
    fastio;
    int t; cin >> t;
    while (t--) solve();
}