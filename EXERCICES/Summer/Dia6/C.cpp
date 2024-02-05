#include <bits/stdc++.h>
using namespace std;
double pi = 3.14159265359;

int main(){
    int n; cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    sort(v.begin(), v.end());

    double area = 0;
    area += v[n-1] * v[n-2];
    area += v[n-1] * v[n-3];
    for(int i = n-2; i-2 >= 0; i--){
        area += v[i] * v[i-2];
    }
    area += v[0] * v[1];

    cout << fixed << setprecision(3) << sin((double)2 * pi/(double)n)*area / (double)2 << endl;
}