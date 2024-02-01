#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;

int main(){
    //fastio;
    int t; cin >> t;

    while (t--)
    {
        double l,r; cin >> l >> r;
        // l = 2*n + g   , r = 2*g + n
        // l = 2*r - 4*g + g
        // l - 2*r = -3*g
        double g = (l - 2*r)/(-3);
        double n = (l - g)/(2);
        if(g == (int)g && g>=0 && n >=0)
        {
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    
    

}