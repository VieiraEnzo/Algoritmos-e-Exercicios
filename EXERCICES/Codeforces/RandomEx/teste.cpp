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
    int n, m; cin >> n >> m;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    int ans = 1;
    for(int i = 0; i < n-1; i++){
        if(v[i] == v[i+1]) continue;
        ans++;
    }

    while (m--)
    {
        int i, x; cin >> i >> x;
        if(v[i] == x) {cout << ans << "\n"; continue;}

        int dif1 = 1;
        for(int k = i-1; k <= i+1; k++) if(v[k] != v[k+1]) dif1++;

        v[i] = x;

        int dif2 = 1;
        for(int k = i-1; k <= i+1; k++) if(v[k] != v[k+1]) dif2++;

        if(dif1 < dif2){
            ans++;
        }else if(dif1 > dif2){
            ans--;
        }

        cout << ans << "\n";
     
    }
    

}