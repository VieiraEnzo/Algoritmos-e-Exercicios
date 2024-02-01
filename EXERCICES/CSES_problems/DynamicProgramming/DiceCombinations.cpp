#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;

int exp(int b, int e, int m){ // O(logE)
    int res=1;
        while(e){
            if(e&1) res=(res*b)%m;
            b=(b*b)%m;
            e>>=1;
        }
    return res;
}



int main(){
    fastio;
    int n; cin >> n;
    cout << exp(2,n-1,1000000007);

}