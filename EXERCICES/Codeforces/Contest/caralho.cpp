#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#pragma GCC optimize("pragv")

using namespace std;
using namespace std;
using namespace __gnu_pbds;

#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pii;
typedef pair<ll,ll> pll;
using ordered_set = tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>;
using ordered_multiset = tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update>;

#define x first
#define y second

int main(){
    fastio;

    long double minx = 1e9;
    long double maxx = 0;
    long double miny = 1e9;
    long double maxy = 0;

    vector<pair<long double,long double>> v(4);
    for(int i = 0; i < 4; i++){
        cin >> v[i].x >> v[i].y;
        minx = min(minx, v[i].x);
        maxx = max(maxx, v[i].x);
        miny = min(miny, v[i].y);
        maxy = max(maxy, v[i].y);

    }

    cout << fixed << setprecision(7);

    sort(v.begin(), v.end());


        //ax + b = y
        bool morte1 = false;
        bool morte2 = false;

        if((v[0].x == v[1].x) && (v[2].x == v[3].x))continue;
        else if((v[2].x == v[3].x)) morte1 = true;
        else if((v[0].x == v[1].x)) morte2 = true;

        //if((v[0].x - v[1].x) == 0) a1 = 0;
        long double a1,b1,a2,b2;

        if(!morte2){
            a1 = (v[0].y - v[1].y)/(v[0].x - v[1].x);
            b1 = -a1 * v[0].x + v[0].y;
        }

        if(!morte1){
            a2 = (v[2].y - v[3].y)/(v[2].x - v[3].x);
            b2 = -a2 * v[2].x + v[2].y;
        }

        if(morte1){
            long double ans1 = v[2].x;
            long double ans2 = a1 * v[2].x + b1;
            if(ans1 <= minx || ans1 >= maxx) continue;
            if(ans2 <= miny || ans2 >= maxy) continue;
            cout << v[2].x << " " << a1 * v[2].x + b1;
            return 0;
        }

        if(morte2){
            long double ans1 = v[0].x;
            long double ans2 = a2 * v[0].x + b2;
            if(ans1 <= minx || ans1 >= maxx) continue;
            if(ans2 <= miny || ans2 >= maxy) continue;
            cout << v[0].x << " " << a2 * v[0].x + b2;
            return 0;
        }

        if(abs(a1 - a2) <= 0.000001) continue;

        long double ans1 = (b2-b1)/(a1-a2);
        long double ans2 = a1* ans1 + b1;
        if(ans1 == v[0].x || ans1 == v[1].x || ans1 == v[2].x || ans1 == v[3].x) continue;

        if(ans1 <= minx || ans1 >= maxx) continue;
        if(ans2 <= miny || ans2 >= maxy) continue;

        cout << ans1 << " " << ans2 << endl;
 
        return 0;
        //a1x + b1 = a2x + b2
        //x = (b2-b1)/(a1-a2)
    
    assert(0);

}