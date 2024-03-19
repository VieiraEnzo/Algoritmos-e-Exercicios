#include <bits/stdc++.h>
using namespace std;

struct Point{
    long double x;
    long double y;
    long double r;
};


int main(){
    Point A;
    Point B;
    cin >> A.x >> A.y >> A.r;
    cin >> B.x >> B.y >> B.r;

    long double dist = sqrt((A.x - B.x)*(A.x - B.x) + (A.y - B.y)*(A.y - B.y));

    long double sobrando = dist - A.r;
    long double diametro = B.r - sobrando;
    long double raio = diametro/2;

    long double dist_C = sobrando + raio;

    long double dx = A.x - B.x;
    long double dy = A.y - B.y;

    long double x = (dx *dist_C)/dist;
    long double y = (dy * dist_C)/dist;

    cout << fixed << setprecision(10) << B.x + x << " " << B.y + y << " " << raio << endl;

}