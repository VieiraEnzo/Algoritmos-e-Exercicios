#include <bits/stdc++.h>
#pragma GCC optimize("pragv")
using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;

void solve(){
    int n, x, p; cin >> n >> x >> p;

    int jump = 1;
    int pos = x;
    while (p--)
    {   
        pos = (pos + jump)%n;
        if(pos == 0) {cout << "Yes" << endl; return;}
        jump++;    
    }
    
    cout << "No" << endl;
}


int main(){
    
    fastio;

    int t; cin >> t;
    while (t--)
    {
        solve();
    }

}