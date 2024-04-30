#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0), ios_base::sync_with_stdio(0);

    int n; cin >> n;
    string f,s,t;
    cin >> f >> s >> t;
    f.append(f.append(f));
    s.append(s.append(s));
    t.append(t.append(t));


    int ans = 1e9;
    for(int i = 0; i < 3*n; i++){
        for(int j = 0; j < 3*n; j++){
            if(i == j) continue;
            for(int k = 0; k < 3*n; k++){
                if( i == k || j == k) continue;
                if(f[i] == s[j] && s[j] == t[k]){
                    ans = min(ans, max({i,j,k}));
                }
            }
        }
    }
    // cout << f[0] << s[1] << t[7];

    if(ans == 1e9) ans = -1;
    cout << ans << "\n";
}