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


#define int long long
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

signed main(){
    fastio;
    int e, v; cin >> e >> v;
    int h = (19 + (e/v))%24;
    int min = ((e * 60)/v)%60;
    if(h < 10){
        cout << 0;
    }
    cout << h << ":";
    if(min < 10){
        cout << 0;
    }
    cout << min << "\n";
    

}