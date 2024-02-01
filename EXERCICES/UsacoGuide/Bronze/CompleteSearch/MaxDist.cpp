#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;

struct pt{
    int x;
    int y;
};

ll dist(pt x1, pt x2)
{
    return (x1.x - x2.x) * (x1.x - x2.x) + (x1.y - x2.y) * (x1.y - x2.y);
}


int main()
{
    fastio;
    int n; cin >> n;
    vector<pt> v(n);
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        v[i].x = x;
    }
    for(int i = 0; i < n; i++){
        int y; cin >> y;
        v[i].y = y;
    }

    ll ans = 0;
    for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++)
            ans = max(ans , dist(v[i], v[j]));

    cout << ans << endl;

    


}