#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k; cin >> n >> k;
    vector<int> a(n);for(int i =0; i < n;i++)cin >> a[i];
    vector<int> b(n);for(int i =0; i < n;i++)cin >> b[i];
    vector<int> maxb(n);maxb[0] = b[0];
    for(int i =1; i < n;i++){maxb[i] = max(b[i], maxb[i-1]);}
    vector<int> sumA(n);sumA[0] = a[0];
    for(int i =1; i < n; i++){sumA[i] = sumA[i-1] + a[i];}

    int ans = 0;
    for(int i = 0; i < min(n,k); i++)
    {
        ans = max(ans, sumA[i] + (k-(i+1))*maxb[i]);
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