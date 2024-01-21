#include <bits/stdc++.h>
#define fastio cin.tie(nullptr);ios_base::sync_with_stdio(false);
#define endl "\n"
using namespace std;

void solve()
{
    pair<int,int> p1; cin >> p1.first >> p1.second;
    pair<int,int> p2; cin >> p2.first >> p2.second;
    pair<int,int> p3; cin >> p3.first >> p3.second;
    pair<int,int> p4; cin >> p4.first >> p4.second;

    int ans = abs((p1.first - p2.first) * (p1.first - p2.first) + (p1.second - p2.second) * (p1.second - p2.second));
    ans = min(ans, (p1.first - p3.first) * (p1.first - p3.first) + (p1.second - p3.second) * (p1.second - p3.second));

    cout << ans << endl;
}

int main()
{
    
    int t; cin >> t;
    while (t--)
    {
        solve();
    }
    
}