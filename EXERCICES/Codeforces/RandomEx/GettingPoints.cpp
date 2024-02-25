#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;
ll n, P, le, t;

bool f(int k){
    if(k*le + min(2*t*k, t*((n+6)/7)) >= P){
        return true;
    }else{
        return false;
    }
}

void solve(){
    cin >> n >> P >> le >> t;

    int l = 0, r = 1e9 + 7;
    while (l < r)
    {
        int mid = (l+r)/2;
        if(f(mid)){
            r = mid;
        }else{
            l = mid + 1;
        }
    }
    
    cout << n-l << endl;
    
}


int main(){
    
    fastio;

    int t; cin >> t;
    while (t--)
    {
        solve();
    }

}