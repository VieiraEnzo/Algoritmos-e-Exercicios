#include<bits/stdc++.h>
using namespace std;
typedef vector<long long> vll;
typedef long long ll;
ll MOD = 1e9 + 7;

ll mod(ll a, ll MOD){
    return a % MOD;
}

// [P1(n)] = [2 1] ^ n-1 * [P1(0)]
// [P2(n)]   [3 3]         [P2(0)]

vector<vll> mult_matriz(vector<vll> a, vector<vll> b){
    vector<vll> z(a.size());

    for(int i = 0; i < a.size(); i++){
        for(int j = 0; j < b[0].size(); j++){
            ll sum = 0;
            for(int k = 0; k < a[0].size(); k++){
                sum += mod(a[i][k] * b[k][j], MOD);
                sum=mod(sum,MOD);
            }
            z[i].push_back(mod(sum,MOD));
        }
    }
    return z;
}

vector<vll> recorrencia_matriz(int expo, vector<vll> base, vector<vll> A){

    vll digits(0);

    while (expo > 1){
        digits.push_back(expo%2); expo/=2;
    }
    digits.push_back(expo);

    vector<vll> id = {{1,0}, {0,1}};

    for(auto x : digits){
        if(x == 1){
            id = mult_matriz(A,A);
        }
    }
    id = mult_matriz(id, base);

    return id;

}

int main(){
    int n; cin >> n;

    vector<vll> m(2, vll (2));
    m[0][0] = 2;
    m[0][1] = 1;
    m[1][0] = m[1][0] = 3;

    vector<vll> base(2, vll (1, 6));

    vector<vll> ans = recorrencia_matriz(n-1, base, m);

    cout << ans[0][0] + ans[1][0];

}