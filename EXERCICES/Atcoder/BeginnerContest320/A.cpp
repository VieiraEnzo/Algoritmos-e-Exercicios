#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;

ll fastexp(ll b, ll e)
{
    ll res =1;
    while (e)
    {
        if(e&1) res = (res*b);
        b=(b*b);
        e>>=1;
    }
    return res;
    
}


int main(){
    fastio;
    ll a,b; cin >> a >> b;
    cout << fastexp(a,b) + fastexp(b,a) << endl;
    
    

}