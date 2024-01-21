#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;

void solve()
{
    int n; cin >> n;
    vector<int> v(n);
    ll sum = 0; 
    for(int i = 0; i < n; i++)
    {
        int temp; cin >> temp;
        sum += temp;
    }
    ll i = sqrt(sum);
    if(i * i != sum) cout << "NO" << endl;
    else cout << "YES" << endl;
}

int main(){
    fastio;
    int t; cin >> t;

    while (t--)
    {
        solve();        
    }
    
    

}