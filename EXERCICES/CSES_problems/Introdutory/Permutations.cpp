#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;

int main(){
    fastio;
    int n; cin >> n;
    int cop = n-1;
    if(n ==2 || n == 3){
        cout << "NO SOLUTION";
        return 0;
    }
    if(n == 4){
        cout << 2 << ' ' << 4 << ' ' << 1 << ' ' << 3 << ' ';
        return 0;
    }

    while (n>0)
    {
        cout << n << ' ';
        n-=2;
    }
    while (cop>0)
    {
        cout << cop << ' ';
        cop-=2;
    }

}