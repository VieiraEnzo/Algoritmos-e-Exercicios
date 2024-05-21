#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int main(){
    fastio;
    int h; cin >> h;
    int plant = 0;
    int day = 0;
    while (plant <= h)
    {
        plant += 1<<day;
        day++;
    }
    cout << day << "\n";
    
    

}