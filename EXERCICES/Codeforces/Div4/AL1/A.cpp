#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;

void solve()
{
    int n; cin >> n;
    int n1; cin >> n1;
    int n2; cin >> n2;

    if(n != n1 && n != n2) cout << n << endl;
    if(n1 != n && n1 != n2) cout << n1 << endl;
    if(n2 != n1 && n2 != n) cout << n2 << endl;
}



int main(){
    fastio;
    int t; cin >> t;
    while (t--)
    {
        solve();
    }

}