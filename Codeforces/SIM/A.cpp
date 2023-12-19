#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    vector<int> v(26); 
    string a; cin >> a;

    for(int i =0; i < n; i++)
    {
        v[a[i] - 'A'] ++;
    }

    int ans = 0;
    for(int i = 0 ; i < 26; i++)
    {
        if(v[i] >= (i+1)) ans++;
    }

    cout << ans << endl;

}



int main(){
    int t; cin >> t;

    while (t--)
    {
        solve();
    }
    

}