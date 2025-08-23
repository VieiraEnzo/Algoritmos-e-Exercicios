#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(0), ios_base::sync_with_stdio(false);

    int p; cin >> p;
    while(p--){
        ll l, a, b; cin >> l >> a >> b;

        ll Ea = 1, Eb = -(1 - 2*a), Ec = -2*l;
        ll ans = (-Eb + sqrt(Eb*Eb - 4 * Ea * Ec))/ 2;

        if(a * ans + ans*(ans-1)/2 < l) ans++;

        ans = min(ans, b-a+1);

        cout << ans << "\n";
    }
}   
