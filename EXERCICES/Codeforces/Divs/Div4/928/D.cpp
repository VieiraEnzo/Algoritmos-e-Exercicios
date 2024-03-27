#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;

void solve(){
    unsigned int n; cin >> n;
    multiset<unsigned int> s;

    unsigned int ans = 0;
    for(unsigned int i = 0; i < n; i++){
        int a; cin >> a;
        int b = a;
        for(int j = 0; j < 31; j++) b = (b^ 1<<j);
        // b/=2;
        if(s.find(b) != s.end()){
            s.erase(s.find(b));
            ans++;
        }else{
            s.insert(a);
        }
        //cout << a << " " << b << endl;
    }

    cout << ans + s.size() << endl;
    // cout << "zero " << 0 << (unsigned int)

}


int main(){
    
    fastio;

    unsigned int t; cin >> t;
    while (t--)
    {
        solve();
    }

}