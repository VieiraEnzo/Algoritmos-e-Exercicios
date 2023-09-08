#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;

int main(){
    fastio;
    int n; cin >> n;
    while (n--)
    {
        int a,b,c; cin >> a >> b >> c;
        int dif =  abs(a - b);
        if(2*c > dif && dif != 0){cout << 1 << endl; continue;}
        if(dif % (2*c)){
            cout << (dif/(2*c))+1 << endl;
        }
        else{
            cout << dif/(2*c) << endl;
        }
        

    }

}