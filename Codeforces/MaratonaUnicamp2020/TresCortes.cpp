#include <bits/stdc++.h>
using namespace std;
double xb, yb, vxb, vyb;
double xp, yp, vxp, vyp;

double escalar(double xb, double yb, double xp, double yp)
{
    return xb * xp + yb * yp;
}

double f(double t){
    return ((vxb * t + xb)-(vxp * t + xp)) * ((vxb * t + xb)-(vxp * t + xp)) + 
    ((vyb * t + yb) - (vyp * t + yp)) * ((vyb * t + yb) - (vyp * t + yp)); 
}

double ternary_search(double l, double r) {
    int a = 300;              //set the error limit here
    while (a--) {
        double m1 = l + (r - l) / 3;
        double m2 = r - (r - l) / 3;
        double f1 = f(m1);      //evaluates the function at m1
        double f2 = f(m2);      //evaluates the function at m2
        if (f1 < f2)
            l = m1;
        else
            r = m2;
    }
    return l;                    //return the maximum of f(x) in [l, r]
}

int main(){
    cin>> xb >> yb >> vxb >> vyb;
    double raio; cin >> raio;
    double t; cin >> t;
    double ans = 0;

    while (t--)
    {
        cin >> xp >> yp >> vxp >> vyp;
        //restas paralelas

        if(vyb/vxb == vyp/vxp){continue;}
        
        double resp = ternary_search(-1e9, 1e9);
        if(resp >= 0 && f(resp) >= raio){
            ans++; 
        }
    }
    cout << ans << endl;
    

}