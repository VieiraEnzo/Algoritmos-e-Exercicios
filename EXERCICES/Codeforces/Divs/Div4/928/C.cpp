#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;
int maxn = 2*1e5 + 5;
vector<ll> s(maxn);


ll f(int i){
    ll sum = 0;
    while (i != 0)
    {
        sum += i%10;
        i/= 10;
    }
    return sum;
}

void solve(){
    int n; cin >> n;

    cout << s[n] << endl;
    
}


int main(){
    
    fastio;



    ll sum = 0;
    ll desl = 0;
    for(int i = 1; i <= maxn; i++){
        if(i%10 == 0){desl = f(i);}
        sum += (i % 10) + desl;
        s[i] = sum;
    }



    int t; cin >> t;
    while (t--)
    {
        solve();
    }

}