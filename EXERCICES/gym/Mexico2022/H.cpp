#include <bits/stdc++.h>
using namespace  std;

int main(){
    int n; cin >> n;

    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(2*i + 2*j > n) continue;
            ans = max(i*j, ans);
        }
    }

    cout << ans << endl;
}