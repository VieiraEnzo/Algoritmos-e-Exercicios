#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;

int main()
{
    int n; cin >> n;
    vector<int> v(n);
    for(int i =0 ; i < n; i++)cin >> v[i];

    sort(v.begin(), v.end());

    if(v[0] != 1){cout << 1 << endl; return 0;}
    ll sum = 1;
    for(int i = 1 ; i < n; i++)
    {
        if(v[i] - sum > 1)
        {
            cout << sum + 1 << endl;
            return 0;
        }
        sum += v[i];
    }

    cout << sum + 1<< endl;

    
}