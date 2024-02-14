#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;

int main(){
    fastio;
    int a,b, d; cin >> a >> b >> d;
    
    for(int i = a; i <= b; i+= d){
        cout << i << " ";
    }cout << endl;

}