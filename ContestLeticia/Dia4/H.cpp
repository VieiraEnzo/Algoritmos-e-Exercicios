#include <bits/stdc++.h>
using namespace std;

using cd = complex<double>;
const double PI = acos(-1);

void fft(vector<cd> & a, bool invert) {
    int n = a.size();
    if (n == 1)
        return;

    vector<cd> a0(n / 2), a1(n / 2);
    for (int i = 0; 2 * i < n; i++) {
        a0[i] = a[2*i];
        a1[i] = a[2*i+1];
    }
    fft(a0, invert);
    fft(a1, invert);

    double ang = 2 * PI / n * (invert ? -1 : 1);
    cd w(1), wn(cos(ang), sin(ang));
    for (int i = 0; 2 * i < n; i++) {
        a[i] = a0[i] + w * a1[i];
        a[i + n/2] = a0[i] - w * a1[i];
        if (invert) {
            a[i] /= 2;
            a[i + n/2] /= 2;
        }
        w *= wn;
    }
}   

void multiply(vector<int>& a, vector<int> const& b) {
    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < a.size() + b.size()) 
        n <<= 1;
    fa.resize(n);
    fb.resize(n);

    fft(fa, false);
    fft(fb, false);
    for (int i = 0; i < n; i++)
        fa[i] *= fb[i];
    fft(fa, true);

    a.resize(n);
    for (int i = 0; i < n; i++)
        a[i] = round(fa[i].real());
    return;
}


int main(){

    cin.tie(0), ios_base::sync_with_stdio(0);

    int maxAi = 1000;
    int n, k; cin >> n >> k;
    k--;
    vector<int> a(maxAi);
    vector<int> resp(maxAi);
    int maxi = 0;
    for(int i = 0; i< n; i++){
        int temp; cin >> temp;
        a[temp] = 1;
        resp[temp] = 1;
        maxi = max(maxi, temp);
    }
    a.resize(maxi + 1);
    resp.resize(maxi + 1);
    
    while (k--)
    {
        // for(auto a : resp){
        //     cout << a << " ";
        // }cout << endl;
        multiply(resp,a);
        // for(auto a : resp){
        //     cout << a << " ";
        // }cout << endl;
    }
    
    for(int i = 0; i< resp.size(); i++){
        if(resp[i] != 0){
            cout << i << " ";
        }
    }
}