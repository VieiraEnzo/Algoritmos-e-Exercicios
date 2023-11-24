#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;

int main(){
    fastio;
    int t; cin >> t;
    while (t--)
    {
        int n,x; cin >> n >> x;
        vector<int> p(n);
        for(int i = 0; i < n ; i++)cin >> p[i];
        int ans = p[0];
        for(int i = 1; i < n; i++){
            ans = max(p[i]- p[i-1], ans);
        }
        ans = max(ans, 2*(x-p[n-1]));
        cout << ans << endl;
    }
    

}