#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int t; cin >> t;
    while (t--)
    {
        ll n; cin >> n;
        ll a = log2(n);

        cout << (1<<a) - 1 << endl;

    }
    
}