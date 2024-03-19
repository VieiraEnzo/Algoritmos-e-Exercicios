#include <bits/stdc++.h>
#pragma GCC optimize("pragv")
using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;

int mod(int a, int m){
    a = a%m;
    if(a >= 0) return a;
    else return a + m;
}


void solve(){
    int n, m, x; cin >> n >> m >> x;
    vector<int> v(n);
    v[x-1] = 1;

    while (m--)
    {
        int a; char k; cin >> a >> k;
        vector<int> novo(n);
        if(k == '0'){
            for(int i = 0; i < n; i++){
                if(v[i] == 1){
                    v[i] = 0;
                    novo[mod(i+a, n)] = 1;
                }
            }

        }if(k == '1'){
            for(int i = 0; i < n; i++){
                if(v[i] == 1){
                    v[i] = 0;
                    novo[mod(i-a, n)] = 1;
                }
            }

        }if(k == '?'){
            for(int i = 0; i < n; i++){
                if(v[i] == 1){
                    v[i] = 0;
                    novo[mod(i-a, n)] = 1;
                    novo[mod(i+a, n)] = 1;
                }
            }
        }

        for(int i = 0; i < n; i++){
            if(novo[i]) v[i] = 1;   
        }
    } 

    int ans = 0;
    for(int i = 0; i < n; i++){
        if(v[i]) ans++;
    }
    cout << ans << endl;
    for(int i = 0; i < n; i++){
        if(v[i]) cout << i+1 << " ";  
    }cout << endl;
    
}


int main(){
    
    fastio;

    int t; cin >> t;
    while (t--)
    {
        solve();
    }

}