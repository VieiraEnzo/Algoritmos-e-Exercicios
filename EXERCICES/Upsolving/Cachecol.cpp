#include<bits/stdc++.h>
using namespace std;
typedef vector<long long> vll;
typedef long long ll;

// [P1(n)] = [2 1] ^ n-1 * [P1(0)]
// [P2(n)]   [3 3]         [P2(0)]

//

const int D = 2;
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

int main(){
    int n; cin >> n;

    Matriz c;
    c[0][0] = 1, c[0][1] = 2;
    c[1][0] = c[1][1] = 3;

    c = c.exp(n-1);
    
    cout << 6 * (c[0][0] + c[0][1]) + 6 * (c[1][0] + c[1][1]) << endl;

}