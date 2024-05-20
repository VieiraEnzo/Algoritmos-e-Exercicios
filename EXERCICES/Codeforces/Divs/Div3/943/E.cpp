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
   int i = 0;
   vector<pair<int,int>> dir = {{1,0}, {0,1}, {-1,0}, {0,-1}};
   pair<int,int> init = {1,1};

   do
   {
        init = init + dir[i]*(n);
        i++;i%=4;
        n/=2;
        cout << init.first << " " << init.second << "\n";
   }while (n > 0);
   

    cout << "\n";
}

int main(){
    fastio;
    int t; cin >> t;
    while (t--) solve();
}