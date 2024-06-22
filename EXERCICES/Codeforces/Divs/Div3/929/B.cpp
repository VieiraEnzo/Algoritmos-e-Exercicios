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
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

void solve(){
    int n; cin >> n;
    vector<int> M(3);
    int sum = 0;
    for(int i = 0; i < n; i++){
        int temp; cin >> temp;
        M[temp % 3]++;
        sum += temp;
    }
    if(sum % 3 == 0) {cout << 0 << "\n"; return;}
    int resto = sum%3;

    if(M[resto] >= 1) {cout << 1 << "\n"; return;}
    
    else{
        if(resto == 1) cout << 2 << "\n"; 
        else  cout << 1 << "\n";
    }

}

signed main(){
    fastio;
    int t; cin >> t;
    while (t--) solve();
}