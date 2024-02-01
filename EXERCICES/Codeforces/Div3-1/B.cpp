#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr)
using namespace std;

void solve()
{
    int n; cin >> n;
    string s; cin >> s;
    string f; cin >> f;
    
    int ns = 0, nf = 0;
    int change = 0;

    for(int i = 0; i < n; i++)
    {
        if(s[i] == f[i]) continue;
        change ++;
        if(s[i] == '1')ns++;
        if(f[i] == '1')nf++;
    }
    
    cout << change - min(ns, nf) << endl;

}


int main()
{
    fastio;
    int t; cin >> t;
    
    while (t--)
    {
        solve();
    }
    

}