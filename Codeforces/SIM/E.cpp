#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool comp(pair<int,int> x, pair<int,int> y)
{
    return abs(x.first) < abs(y.first);
}


void solve()
{   
    int n; cin >> n;
    vector<int> a(n); for(int i =0; i < n; i++) cin >> a[i];
    vector<int> b(n); for(int i =0; i < n; i++) cin >> b[i];

    vector<pair<ll,ll>>opt(n);
    for(int i =0; i < n; i++)
    {
        opt[i].first = a[i] + b[i];
        opt[i].second = i;
    }

    sort(opt.rbegin(), opt.rend(), comp);

    ll ans = 0;    
    for(int i = 0; i < n; i++)
    {
        if(i%2 == 0){ans += (a[opt[i].second] - 1);}
        else ans -= (b[opt[i].second] - 1);
    }

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