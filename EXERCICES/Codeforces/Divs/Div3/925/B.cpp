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
    int sum = 0;
    for(int i = 0; i < n; i++){cin >> v[i];sum+= v[i];}
    sum /= n;

    int sobrando = 0;
    for(int i = 0; i < n; i++){
        if(v[i] > sum){
            sobrando += v[i] - sum;
        }
        if(v[i] < sum){
            sobrando -= sum - v[i];
        }

        if(sobrando < 0){
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
    
}

int main(){
    fastio;
    int t; cin >> t;
    while (t--) solve();
}