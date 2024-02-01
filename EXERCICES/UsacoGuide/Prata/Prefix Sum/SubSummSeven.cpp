#include <bits/stdc++.h>
#include <fstream>
using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;
#define MOD 7


int main()
{
    fastio;
    ifstream fin("div7.in");
    int n;
    fin >> n;
    // cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    vector<int> mp(7,1e9);
    mp[0] = -1;

    //prefix summ
    ll sum = 0;
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        v[i] = (v[i] + sum)%7;
        sum = v[i];
        mp[sum] = min(mp[sum], i);      
        if(mp[v[i]] != 1e9)
            ans = max(ans, (i - mp[sum]));
    }



    ofstream fout("div7.out");
    fout << ans << endl;
    // cout << ans << endl;
    fin.close();
    fout.close();

}