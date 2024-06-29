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
int n, x; cin >> n >> x;
    vector<int> arr(n+1);
    vector<int> marc(n+1);
    for(int i = 1; i <= n; i++) cin >> arr[i];

    auto bb = [&](){
        int l = 1, r = n+1;
        while (r-l > 1)
        {
            int m = (l+r)/2;
            if(arr[m] <= x){
                l = m;
            }else{
                r = m;
            }
            marc[m] = 1;
        }
        return l;
    };

    int l = bb();

    if(arr[l] == x) {cout << 0 << "\n"; return;} 

    int posx = -1;
    for(int i = 1; i <= n; i++) if(arr[i] == x) posx = i;
    
    if(marc[posx]){
        int troca = -1, reserva = -1;
        for(int i = 1; i <= n; i++) {if(!marc[i] && arr[i] < x) troca = i; if(!marc[i]) reserva = i;}
        if(troca == -1){
            // cout << "oie\n";
            // for(int i = 1; i <= l; i++) if(!marc[i]) reserva = i;
            cout << 2 << "\n";
            cout << posx << " " << reserva << "\n";
            swap(arr[reserva], arr[posx]);

            fill(marc.begin(), marc.end(), 0);
            int l = bb();
            cout << reserva << " " << l << "\n";

        }else{
            cout << 2 << "\n";
            cout << posx << " " << troca << "\n";
            cout << troca << " " << l << "\n";
        }

    }else{
        cout << 1 << "\n";     
        cout << min(posx,l) << " " << max(posx,l) << "\n"; 
    }


    
}

signed main(){
    fastio;
    int t; cin >> t;
    while(t--) solve();
}