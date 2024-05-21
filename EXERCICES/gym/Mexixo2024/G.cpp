#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int main(){
    fastio;
    int n; cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    v.push_back(0);

    sort(all(v));

    int ans = 0;
    for(int i = 0; i < n; i++){
        if(v[i]+1 == v[i+1]) ans++;
        else if(v[i] == v[i+1]) continue;
        else break;
    }

    // cout << ans << "\n";

    if(ans %2 == 0){
        cout << "Alicius\n";
    }else cout << "Bobius\n";

}