#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

pair<int,int> operator*(pair<int,int> a, int b){
    return {a.first * b, a.second * b};
}
pair<int,int> operator+(pair<int,int> a,pair<int,int> b){
    return {a.first + b.first, a.second + b.second};
}


void solve(){
    int n; cin >> n;
   // 1 ... n
   // . . . .
   // . . . .
   // . . . .
   // n ... i

    if(n == 2){
        cout << 1 << " " << 1 << "\n";
        cout << 1 << " " << 2 << "\n";
        return;
    }

    if(n == 3){
        cout << 2 << " " << 1 << "\n";
        cout << 2 << " " << 3 << "\n";
        cout << 3 << " " << 1 << "\n";
        return;
    }

    pii pa = {1,1};

   for(int i = 0; i < n-2; i++){
        cout << pa.first << " " << pa.second << "\n";
        pa.first++; pa.second++;
   }


   cout << n-1 << " " << n << "\n";
   cout << n << " " << n << "\n";
   

    // cout << "\n";
}

int main(){
    fastio;
    int t; cin >> t;
    while (t--) solve();
}