#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;
vector<ll> v;ll n;

ll solve(ll i, ll sum)
{
    if(i == n){return sum;}
    ll add = solve(i+1, sum+v[i]);
    ll nadd = solve(i+1, sum - v[i]);
    return min(abs(add), abs(nadd));

}

int main(){
    fastio;
    cin >> n;
    v.resize(n);
    for(ll i =0; i < n; i++)cin >> v[i];
    cout << solve(0,0);

}