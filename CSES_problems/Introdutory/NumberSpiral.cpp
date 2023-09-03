#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;

int main(){
    fastio;
    int t; cin >> t;
    while (t--)
    {
        ll x,y; cin >> y >> x;
        ll level = max(x,y);
        if(level%2){
            if(x == level){
                cout << (level*level) - (y-1) << endl;
            }
            else{
                cout << ((level*level) - pow(2,level-1)) + (x-1) << endl;
            }
        }
        else{
            if(x == level){
                cout << ((level*level) - pow(2,level-1)) + (y-1) << endl;
            }
            else{
                cout << (level*level) - (x-1) << endl;
            }

        }

    }
    

}