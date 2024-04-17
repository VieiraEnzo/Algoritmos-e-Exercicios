#include <bits/stdc++.h>

using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

void solve(){
    int k, q; cin >> k >> q;
    vector<int> a(k);
    for(int i = 0; i < k; i++) cin >> a[i];
    while (q--)
    {
        int num; cin >> num;
        int ind = k-1;
        while(ind >= 0){
            while (ind >= 0 &&num < a[ind])
            {
                ind--;
            }
            num -= ind+1;
        }
        cout << num << " ";
    }
    cout << endl;
        
}


int main(){
    fastio;
    int t; cin >> t;
    while (t--)
    {
        solve();
    }
    
    

}