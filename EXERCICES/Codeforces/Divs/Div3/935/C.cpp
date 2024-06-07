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
    int n; cin >> n;
    string s; cin >> s;
    vector<int> left(n+1), right(n+1);
    left[0] = 0, right[n] = 0;
    for(int i = 1; i <= n; i++){left[i] = left[i-1] + (s[i-1] == '0');}
    for(int i = n-1; i >= 0; i--){right[i] = right[i+1] + (s[i] == '1');}

    pr(left, right);

    int minimize = 1e9, ans = 0;
    for(int i = 0; i < n; i++){
        if(right[i] >= (n-i+1)/2 && left[i] >= (i+1)/2){
            if(abs(n/2 - i) < minimize) {minimize = (n/2-i); ans = i;}
        }   
    }


    cout << n << "\n";

}   

signed main(){
    fastio;
    int t; cin >> t;
    while (t--) solve();
}