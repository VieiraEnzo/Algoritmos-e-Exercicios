#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;

void solve(){
    int n, x , y; cin >> n >> x >> y;
    vector<int> Mx(n);
    vector<int> My(n);
    for(int i = 0; i < n; i++){
        int temp; cin >> temp;
        Mx[i] = temp % x;
        My[i] = temp % y;
    }

    

}

int main(){
    fastio;
    int t; cin >> t;
    while(t--){
        solve();
    }
    

}