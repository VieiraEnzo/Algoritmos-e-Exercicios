#include <bits/stdc++.h>
using namespace std;
int main()
{
    double x,y; cin >> x >> y;
    if(abs(y * log2(x) - x * log2(y)) < 1e-2)
    {
        cout << '=' << endl;
    }else if(y * log2(x) < x * log2(y))
    {
        cout <<  '<' << endl;
    }
    else{
        cout << '>' << endl;
    }

}