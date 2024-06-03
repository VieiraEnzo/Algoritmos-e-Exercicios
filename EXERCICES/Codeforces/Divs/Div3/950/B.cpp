#include <bits/stdc++.h>

using namespace std;

#ifdef local
    #include "/home/enzo/Documents/Prog/OBItraining/debug.h"
    #define pr(...) debug(#__VA_ARGS__, __VA_ARGS__)
    #define prs(...) debug_nameless(__VA_ARGS__)
#else
    #define pr(...) 69
    #define prs(...) 69
#endif


#define endl "\n"
#define int long long
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

void solve(){
    int n, f, k; cin >> n >> f >> k;
    vector<int> v(n);
    k--;f--;

    for(int i = 0; i < n; i++) cin >> v[i];
    f = v[f];
    sort(v.rbegin(), v.rend());
    int numT = 0, numS = 0;
    for(int i = 0; i < n; i++){
        if(v[i] == f){
            if(i > k) numS++;  
            numT++;   
        }
    }

    if(numT == numS){
        cout << "No\n";
    }
    else if(numS == 0){
        cout << "Yes\n";
    }
    else if(numT > numS){
        cout << "Maybe\n";
    }
    
}

signed main(){
    fastio;
    int t; cin >> t;
    while (t--) solve();
}