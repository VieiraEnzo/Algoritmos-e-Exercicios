#include <bits/stdc++.h>
#define int long long
using namespace std;

int area(int i, int j, int k){
    return 2*i*j + 2*i*k + 2*j*k;
}


signed main(){
    int v; cin >> v;

    int ans = 1e9;
    for(int i = 1; i* i <= v; i++){
        for(int j = 1; j*j <= v;j++){
            int k = v/(i*j);
            if(i*k*j != v) continue;
            ans = min(ans, area(i,j,k));
        }
    }
    
    cout << ans << endl;
}