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


template<class T> int sgn(T x) { return (x>0) - (x<0); }
template<class T> struct Point{
typedef Point P;
T x, y;
explicit Point(T x=0, T y=0) : x(x), y(y) {}
bool operator<(P p) const { return tie(x,y) < tie(p.x,p.y); }
bool operator==(P p) const { return tie(x,y)==tie(p.x,p.y); }
P operator+(P p) const { return P(x+p.x, y+p.y); }
P operator-(P p) const { return P(x-p.x, y-p.y); }
P operator*(T d) const { return P(x*d, y*d); }
P operator/(T d) const { return P(x/d, y/d); }
T dot(P p) const { return x*p.x + y*p.y; }
T cross(P p) const { return x*p.y - y*p.x; }
T cross(P a, P b) const { return (a-*this).cross(b-*this); }
T dist2() const { return x*x + y*y; }
double dist() const { return sqrt((double)dist2()); }
// angle to x-axis in interval [-pi, pi]
double angle() const { return atan2(y, x); }
P unit() const { return *this/dist(); } // makes dist()=1
P perp() const { return P(-y, x); } // rotates +90 degrees
P normal() const { return perp().unit(); }
// returns point rotated 'a' radians ccw around the origin
P rotate(double a) const { return P(x*cos(a)-y*sin(a),
x*sin(a)+y*cos(a)); }
};
using P = Point<double>;

bool inter(int a, int b, int c, int d){
if(a>b) swap(a, b);
if(c>d) swap(c, d);
return max(a, c)<=min(b, d);
}

bool intersect(P a, P b, P c, P d){
// segment AB and segment CD
int o1=sgn(a.cross(b, c));
int o2=sgn(a.cross(b, d));
int o3=sgn(c.cross(d, a));
int o4=sgn(c.cross(d, b));
if(sgn(c.cross(a, d))==0 && sgn(c.cross(b, d))==0){
return inter(a.x, b.x, c.x, d.x)
&& inter(a.y, b.y, c.y, d.y);
}
return o1!=o2 && o3!=o4;
}

int main(){
    fastio;

    vector<P> v(4);
    for(int i = 0; i < 4; i++){
        cin >> v[i].x >> v[i].y;
    }

    sort(v.begin(), v.end());

    cout << fixed << setprecision(8); 

    do{
        bool morte1 = false;
        bool morte2 = false;

        if(!intersect(v[0], v[1], v[2], v[3])) continue;

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
            cout << v[2].x << " " << a1 * v[2].x + b1;
            return 0;
        }

        if(morte2){
            long double ans1 = v[0].x;
            long double ans2 = a2 * v[0].x + b2;
            cout << v[0].x << " " << a2 * v[0].x + b2;
            return 0;
        }

        long double ans1 = (b2-b1)/(a1-a2);
        long double ans2 = a1* ans1 + b1;


        cout << ans1 << " " << ans2 << endl;
 
        return 0;


    }while(next_permutation(v.begin(), v.end()));

    
       
    assert(0);

}