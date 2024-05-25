#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

void solve(){
    int n; cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) {cin >> v[i];}   

    int num = v[0], count = 0;
    for(int i = 0; i < n; i++){
        if(v[i] == num) count++;
        else break;
    }

    int num2 = v[n-1], count2 = 0;
    for(int i = n-1; i >= 0; i--){
        if(v[i] == num2) count2++;
        else break;
    }

    if(num == num2) {count += count2; count = min(count, n);}
    else count = max(count, count2);

    cout << n - count << "\n";
}

int main(){
    fastio;
    int t; cin >> t;
    while (t--) solve();
}