#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define endl "\n"
typedef long long ll;

struct Point
{
    int x;
    int y;
};



void solve()
{
    int h, w;
    Point Alice, Bob; cin >> h >> w >> Alice.y >> Alice.x >> Bob.y >> Bob.x;
    if(Alice.y >= Bob.y){cout << "Draw" << endl; return;}
    if(abs(Alice.y - Bob.y) %2)//Alice can win
    {
        if(abs(Bob.x - Alice.x) > 1 && (Bob.x - Alice.x) > 0 && w - Bob.x > abs(Bob.x - Alice.x)/2) //Bob runs
        {cout << "Draw" << endl; return;}

        if(abs(Bob.x - Alice.x) > 1 && (Bob.x - Alice.x) < 0 && Bob.x - 1 > abs(Bob.x - Alice.x)/2) //Bob runs
        {cout << "Draw" << endl; return;}

        cout << "Alice" << endl;
    }

    else
    {
        if(Alice.x == Bob.x) //Alice runs
        {cout << "Bob" << endl; return;}

        cout << "Draw" << endl;
    }   

}

int main()
{
    fastio 

    ll t; cin >> t;
    while (t--)
    {
        solve();
    }
    
}