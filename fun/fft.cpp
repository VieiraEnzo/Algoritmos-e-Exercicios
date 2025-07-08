#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifdef local
    #include "/home/enzo/Documents/Prog/OBItraining/debug.h"
    #define pr(...) debug(#__VA_ARGS__, __VA_ARGS__)
    #define prs(...) debug_nameless(__VA_ARGS__)
#else
    #define pr(...) 69
    #define prs(...) 69
#endif

const double pi = acos(-1);



//(2*pi*j)/n -> j = {0,1,2, ... , n-1}
//cost((2*pi*j)/n) + i*sin((2*pi*j)/n);
typedef complex<double> cmpl;
vector<cmpl> fft(vector<cmpl> a){
    int n = a.size();

    if(n == 1){
        return a;
    }

    vector<cmpl> peven(n/2), podd(n/2);
    for(int i = 0; i < n/2; i++){
        peven[i] = a[2*i];
        podd[i] = a[2*i + 1];
    }
    
    vector<cmpl> vals_even = fft(peven);
    vector<cmpl> vals_odd = fft(podd);
    vector<cmpl> vals(n);
    for(int i = 0; i < n/2; i++){
        double angle = (2.0*pi*i) / (double)n;
        cmpl x = cos(angle) + 1i * sin(angle);
        vals[i] = vals_even[i] + x * vals_odd[i];
        vals[i + n/2] = vals_even[i] - x  * vals_odd[i];
    }
    return vals;
};

vector<cmpl> invFFT(vector<cmpl> vals){

    int n = vals.size();

    if(n == 1) return vals;

    vector<cmpl> vals_even(n/2), vals_odd(n/2);
    for(int i = 0; i < n/2; i++){
        double angle = (2.0*pi*i) / (double)n;
        cmpl x = cos(angle) + 1i * sin(angle);
        vals_even[i] = (vals[i] + vals[i+n/2]) / 2.0;
        vals_odd[i] = (vals[i] - vals[i+n/2]) / (2.0*x);
    }

    vector<cmpl> peven = invFFT(vals_even);
    vector<cmpl> podd = invFFT(vals_odd);

    vector<cmpl> P(n);
    for(int i = 0; i < n/2; i++){
        P[2*i] = peven[i];
        P[2*i + 1] = podd[i];
    }

    return P;
};

vector<ll> convolute(vector<ll> a, vector<ll> b){

    int n = 1;
    while(n < a.size() + b.size()) n*= 2;

    vector<cmpl> a_cmpl(n), b_cmpl(n);
    copy(a.begin(), a.end(), a_cmpl.begin());
    copy(b.begin(), b.end(), b_cmpl.begin());

    vector<cmpl> a_val = fft(a_cmpl);
    vector<cmpl> b_val = fft(b_cmpl);

    vector<cmpl> r_val(n);

    assert(a_val.size() == n);
    for(int i = 0; i < n; i++){
        r_val[i] = a_val[i] * b_val[i];
    }

    vector<cmpl> R_cmpl = invFFT(r_val);
    vector<ll> R(n);
    for(int i = 0; i < n; i++){
        R[i] = round(R_cmpl[i].real());
    }
    return R;
}


int main(){



}