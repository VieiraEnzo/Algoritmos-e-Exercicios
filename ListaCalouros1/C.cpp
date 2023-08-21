#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)

int main(){
    fastio;
    int n; cin>> n;
    vector<bool> v(n+1,false);
    int a =1;
    int i =1;
    while(a <= n){
        cout << a << endl;
        i+=2;
        a+=i;
    }

}