#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;
ll MOD = 1e9 + 7;


int main(){
    int h, w; cin >> h >> w;
    char m[h][w];
    ll ans[h][w];
    memset(ans, 0, sizeof(ll) * (h * w));
    ans[0][0] = 1;

    for(int i =0 ; i < h; i++)
        for(int j = 0; j < w;j ++)
            cin >> m[i][j];


    for(int i =0; i < h; i++)
        for(int j = 0; j < w; j++){
            if(m[i][j] == '#') continue;
            if(i+1 < h && m[i+1][j] == '.'){
                ans[i+1][j] = (ans[i+1][j]%MOD + ans[i][j]%MOD)%MOD;
            }
            if(j+1 < w && m[i][j+1] == '.'){
                ans[i][j+1] = (ans[i][j+1]%MOD + ans[i][j]%MOD)%MOD;
            }
        }

    cout << (ans[h-1][w-1])%MOD << endl;

    
}