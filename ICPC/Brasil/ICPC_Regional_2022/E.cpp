#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fastio cin.tie(nullptr);ios_base::sync_with_stdio(false)

ll sumDig(int n)
{      
    int sum = 0;
    while (n != 0)
    {
        sum += n%10;
        n = n/10;
    }
    return sum;
}   


int main()
{
    fastio;
    ll n, k, temp; cin >> n >> k;
    vector<ll> v(1e6);
    for(int i = 0; i < n; i++){cin >> temp; v[temp]++;}
    for(int i = 1e6; i >=0; i--)
    {
        if(!v[i])continue;
        k -= v[i];
        v[i - sumDig(i)] += v[i];
        if(k <= 0){cout << sumDig(i) << endl; return 0;}
    }
    cout << 0 << endl;

}