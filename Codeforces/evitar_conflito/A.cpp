#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;

ll fast_exp(ll b, ll  e)
{
    ll res = 1;
    while (e)
    {
        if(e&1) res = (res*b);
        b= b*b;
        e>>=1;
    }
    return res;
    
}



int main(){
    fastio;
    ll n, m; cin >> n >> m;
    cout << fast_exp(2,m) + 2 ; endl;

}