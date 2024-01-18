#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n; cin >> n;
    vector<int> quant(10, 0);
    ll ans = 0;
    for(int i= 0; i < n; i++){
        ll num, copy; cin >> num;
        copy = num;
        bool valid = true;
        while (num > 0)
        {
            quant[num % 10]++;
            if(quant[num % 10] > 2){valid = false; break;}
            num /= 10;
        }
        if(valid) ans += copy;
        else break;
    }
    cout << ans << endl;
}

int main()
{
    cin.tie(nullptr); ios_base::sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
    {
        solve();
    }
    
    
}