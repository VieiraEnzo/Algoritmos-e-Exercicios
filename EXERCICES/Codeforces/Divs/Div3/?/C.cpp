#include <bits/stdc++.h>
#pragma GCC optimize("pragv")
using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;

void solve(){
    int n; cin >> n;
    string  s; cin >> s;

    int ans = 0;
    for(int i = 0; i < n-2; i++){
        if(s[i] == 'm' && s[i+1] == 'a' && s[i+2] == 'p'){
            ans++;
        }
        if(s[i] == 'p' && s[i+1] == 'i' && s[i+2] == 'e'){
            ans++;
        }
    }

    int ant = 0;
    for(int i = 2; i < n-2; i++){
        if(s[i] != 'p') continue;
        if(s[i-2] == 'm' && s[i-1] == 'a' && s[i+1] == 'i' && s[i+2] == 'e'){
            ant++;
        }
    }


    cout << ans - ant << endl;
}


int main(){
    
    fastio;

    int t; cin >> t;
    while (t--)
    {
        solve();
    }

}