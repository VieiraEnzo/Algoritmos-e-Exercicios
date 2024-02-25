#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;

void solve(){
    string s; cin >> s;
    int fa = 0, fb = 0;

    for(int i =0; i < s.size(); i++){
        if(s[i] == 'A')fa++;
        if(s[i] == 'B')fb++;
    }

    if(fa>fb){
        cout << 'A' << endl;
    }else{
        cout << 'B' << endl;
    }
    
}


int main(){
    
    fastio;

    int t; cin >> t;
    while (t--)
    {
        solve();
    }

}