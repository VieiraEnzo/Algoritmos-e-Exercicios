#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int m = 1e7;

//Buses:
//Aproach 1: dividir em função de 2 variaveis
//f(5) = F(0,1) = K ^ 1
//f(10) = F(1,0) = l ^ 1 * K ^ 0 + F(0,2)
//F(0,2) = l ^ 0 * K ^ 2
//f(15) = F(2,0) = l ^ 2 * K ^ 0 + F(1,2)

//Aproach 2: dividir em função de 1 variavel
//f(5) = k^1
//f(10) = 2 * f(5) 

//
//cachecol da vovo vitoria
//dp[B][b] = l^B * k^b * (B+b)!/(B!*b!) + dp[B-1][b+2]
//
// [B] = [ 1 | 0 ] * [B-1]
// [b]   [ 2 | 0 ]   [b+2]

// F(n) = K ^ (n/2)


int main(){
    ll n , k , l; cin >> n >> k >> l;







}