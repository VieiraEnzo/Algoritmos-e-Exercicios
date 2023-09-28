#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;


double hip(double x, double y)
{
    return sqrt((x * x) + (y * y));
}


int main(){
    fastio;
    double t; cin >> t;
    while (t--)
    {
        double a, b, c, x;
        cin >> a >> b >> c >> x;
        x = x /100;
        double dist1 = hip(b + 2*c, a);
        double dist2 =  x * hip(a, b);
        double dist3 = hip((1-x) * a, (((1-x)*b) + 2*c));
        double res = dist1 + dist2 + dist3;
        // printf("%.9lf\n", res);
        cout << fixed << setprecision(15);
        cout << res << endl;
    }
    
    

}