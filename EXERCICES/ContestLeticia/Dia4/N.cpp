#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;


struct Point{
    ll x;
    ll y;
};

long long area(vector<Point> &a){
    ll res = 0;
    for(int i = 0; i < a.size(); i++){
        Point p = i? a[i-1] : a.back();
        Point q = a[i];
        res += (p.x * q.y) - (q.x * p.y); 
    }
    return abs(res) / 2;
}

int main(){

    cin.tie(nullptr); ios_base::sync_with_stdio(false);

    ll n; cin >> n;
    vector<Point> points(n);
    for(ll i =0 ; i<n;i++)
        cin >> points[i].x >> points[i].y;

    ll b = 0;
    for(int i = 0; i < n; i++){
        Point p = i? points[i-1] : points.back();
        Point q = points[i];

        ll dx = abs(p.x - q.x);
        ll dy = abs(p.y - q.y);

        b += __gcd(dx,dy);

    }

    ll i = area(points) - (b/2) + 1;

    cout << i << " " << b << endl;
}               