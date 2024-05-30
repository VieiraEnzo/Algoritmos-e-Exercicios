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

signed main(){
    fastio;
    int n; cin >> n;
    vector<pair<int,int>> t(n);
    for(int i = 0; i < n; i++){
        int a, d; cin >> a >> d;
        t[i] = {a,d}; 
    }

    sort(all(t));

    int time = 0, reward = 0;
    for(int i = 0; i < n; i++){
        time += t[i].first;
        reward += t[i].second - time;
    } 
    
    cout << reward << "\n";

}