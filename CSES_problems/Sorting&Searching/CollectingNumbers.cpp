#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;



int main(){
    fastio;
    map<int,int> m;
    int n; cin >> n;
    for(int i = 0 ; i < n ; i++)
    {
        int temp; cin >> temp;
        m[temp] = i;
    }

    ll ans = 1;
    for(int i = 2 ; i <= n ; i++)
    {
        if(m[i-1] > m[i]){ans++;}
    }
    
    cout << ans << endl;

}