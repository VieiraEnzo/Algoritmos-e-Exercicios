#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;

void solve(){
    int n; cin >> n;
    vector<vector<int>> g(n, vector<int> (n));

    for(int i = 0; i < n; i++){
        string a; cin >> a;
        for(int j = 0; j < n; j++)
            g[i][j] = a[j] - '0';
    }

    int lastquan = -1;
    for(int i = 0; i < n; i++){
        int qut1 = 0;
        for(int j = 0; j < n; j++)
            if(g[i][j]) qut1++;

        if(lastquan == qut1) {cout << "SQUARE" << endl;return;}
        if(lastquan == -1 && qut1 != 0) lastquan = qut1;
    }

    cout << "TRIANGLE" << endl;
    
}


int main(){
    
    fastio;

    int t; cin >> t;
    while (t--)
    {
        solve();
    }

}