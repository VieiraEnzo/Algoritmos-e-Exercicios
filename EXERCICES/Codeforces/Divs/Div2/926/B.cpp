#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;



void solve(){
    int n, k; cin >> n >> k;

    int dq = 2*(n-1);
    int cc = 2*dq;

    if(k <= cc){
        cout << (k+1)/2 << endl;
    }else{
        k -= cc;
        cout << dq + k << endl;
    }
    
}


int main(){
    
    fastio;

    int t; cin >> t;
    while (t--)
    {
        solve();
    }

}