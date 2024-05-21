#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int D = 20;
const int MOD = 1000000007;
struct Matriz{
  int mat[D][D];
  int* operator[](int i){
    return mat[i];
  }
  Matriz operator*(Matriz oth){
    Matriz res;
    for(int i=0; i<D; i++){
      for(int j=0; j<D; j++){
        res[i][j] = 0;
        for(int k=0; k<D; k++)
          res[i][j] = (res[i][j]+(mat[i][k]*1LL*oth[k][j])%MOD)%MOD;
      }
    }
    return res;
  }
  Matriz exp(long long e){
    Matriz res;
    for(int i=0; i<D; i++)
      for(int j=0; j<D; j++)
        res[i][j] = (i==j);    
    Matriz base = *this;  
    while(e > 0){
      if(e & 1LL)
        res = res * base;
      base = base*base;
      e = e>>1;
    }
    return res;
  }
};

void solve(){
    int n; cin >> n;

    Matriz base;
    for(int i = 0; i < D; i++){
        for(int j = 0; j < D; j++){
            base[i][j] = 0;
        }
    }
    for(int i = 0; i < D-1; i++) base[i+1][i] = 1;

    base[0][5]  = 3;
    base[0][9] = 3;
    base[0][13] = 3;
    base[0][17] = 3;

    Matriz resp = base.exp(n);

    // for(int i = 0; i < D; i++){
    //     for(int j = 0; j < D; j++){
    //         cout << resp[i][j] << " ";
    //     }cout << endl;
    // }

    int ans = 0;
    for(int i = 0; i < D; i++){
        ans += resp[i][0];
        ans %= MOD;
    }

    cout << ans << "\n";
}

int main(){
    int t; cin >> t;
    while (t--)
    {
        solve();
    }
    
}