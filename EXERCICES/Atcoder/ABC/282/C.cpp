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
    string s; cin >> s;

    bool closed = false;
    for(int i = 0; i < n; i++){
        if(closed){
            if(s[i] == '"'){
                closed = false;
            }
        }else{
            if(s[i] == ','){
                s[i] = '.';
            }
            if(s[i] == '"'){
                closed = true;
            }
        }
    }
    
    cout << s << "\n";

}