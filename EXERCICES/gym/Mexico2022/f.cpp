#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const ll D = 2;
const ll MOD = 1e9+7;
struct Matriz{
  ll mat[D][D];
  ll* operator[](ll i){
    return mat[i];
  }
  Matriz operator*(Matriz oth){
    Matriz res;
    for(ll i=0; i<D; i++){
      for(ll j=0; j<D; j++){
        res[i][j] = 0;
        for(ll k=0; k<D; k++)
          res[i][j] = (res[i][j]+(mat[i][k]*1LL*oth[k][j])%MOD)%MOD;
      }
    }
    return res;
  }
  Matriz exp(long long e){
    Matriz res;
    for(ll i=0; i<D; i++)
      for(ll j=0; j<D; j++)
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

ll fib(ll n){
    if(n == 1) return 1;
    if(n == 2) return 1;
    Matriz oi;
    oi[0][0] = 1; oi[0][1] = 1;
    oi[1][0] = 1; oi[1][1] = 0;

    Matriz resp = oi.exp(n-2);

    return (resp[0][0] + resp[0][1])%MOD; 
}



int main(){
    cin.tie(0), ios_base::sync_with_stdio(0);

    ll n, m; cin >> n >> m;
    vector<ll> v(m);
    for(ll i = 0; i < m; i++) cin >> v[i];

    vector<ll> fibo(1e6+1);
    fibo[0] = 1;
    fibo[1] = 1;
    fibo[2] = 1;

    for(ll i = 3; i <= 1e6; i++){
        fibo[i] = (fibo[i-1] + fibo[i-2])%MOD;
    }

    v.push_back(-1);
    v.push_back(n + 1);

    sort(v.begin(), v.end());

    int ans = 1;
    for(ll i = 1; i < v.size(); i++){
        ll dist = v[i] - v[i-1] - 1;
        if(dist  == 0){
            ans = 0;
            break;
        }

        if(dist > 1e6) ans = (ans * fib(dist))%MOD;
        else ans = (ans  * fibo[dist])%MOD;
    }
    
    cout << ans << endl;
}