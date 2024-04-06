#include <bits/stdc++.h>

using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

double fastexp(double b, ll e){
    double res = 1;
    while (e)
    {
        if(e&1) res=(res*b);
        b=(b*b);
        e>>=1;
    }
    return res;
}

int main(){
    fastio;
    double n,k; cin >> n >> k;
    //valor esperado de ganhar no pacote i
    //p = [(n-1)/n]^k  ->Probabilidade de n sair no pacote
    // 1-p = probabilidade de sair no pacote
    // p^(i-1) * 1-p  -> probabilidade de sair só no pacote i
    
    double p = 1;
    for(int i = 0; i < k; i++){p = p *(n-1)/n;}
    double cp = 1-p;

    double expv = 0;
    double pe = 1;
    for(int i = 1; i <= 1000; i++){
        expv +=  i*pe*cp;
        cout << i * pe * cp << endl;
        pe *= p;
    }
    
    cout << fixed << setprecision (10) << 1/p << endl;

}