#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;


int main(){
    fastio;
    int n; cin >> n;
    int mod = 1e9+7;
    vector<int> v(n+1);
    v[1] = 1;
    v[2] = 2;
    v[3] = 4;
    v[4] = 8;
    v[5] = 16;
    v[6] = 32;
    for(int i = 7; i <= n; i++){
        v[i] = (v[i-1] + v[i])%mod;
        v[i] = (v[i-2] + v[i])%mod;
        v[i] = (v[i-3] + v[i])%mod;
        v[i] = (v[i-4] + v[i])%mod;
        v[i] = (v[i-5] + v[i])%mod;
        v[i] = (v[i-6] + v[i])%mod;
    }

    cout << v[n] << endl;
}