#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const ull MOD = 1e9 + 7;


template<typename T> T minv(T a, T m) {
a %= m; assert(a);
return a == 1 ? 1 : T(m - i64(minv(m, a)) * m / a);
}

template<unsigned M_> struct modnum {
static constexpr unsigned M = M_; using num = modnum;
using ll = int64_t; using ull = uint64_t; unsigned x;
num& norm(unsigned a){x = a<M ? a : a-M;return *this;}
constexpr modnum(ll a = 0U) : x(unsigned((a %= ll(M)) < 0 ? a
+ ll(M) : a)) {}
explicit operator ull() const { return x; }
num& operator+=(const num& a){ return norm(x+a.x); }
num& operator-=(const num& a){ return norm(x-a.x+M); }
num& operator*=(const num& a){ x = unsigned(ull(x)*a.x%M);
return *this; }
num& operator/=(const num& a){ return (*this *= a.inv());}
num operator+(const num& a) const {return (num(*this) += a);}
num operator-(const num& a) const {return (num(*this) -= a);}
num operator*(const num& a) const {return (num(*this) *= a);}
num operator/(const num& a) const {return (num(*this) /= a);}
template<typename T> friend num operator+(T a, const num& b){
return (num(a) += b); }
template<typename T> friend num operator-(T a, const num& b){
return (num(a) -= b); }
template<typename T> friend num operator*(T a, const num& b){
return (num(a) *= b); }
template<typename T> friend num operator/(T a, const num& b){
return (num(a) /= b); }
num operator+() const { return *this; }
num operator-() const { return num() - *this; }
num pow(ll e) const {
if (e < 0) { return inv().pow(-e); } num b = x, xe = 1U;
for (; e; e >>= 1) { if (e & 1) xe *= b; b *= b; }
return xe;
}
num inv() const { return minv(x, M); }
friend num inv(const num& a) { return a.inv(); }
explicit operator bool() const { return x; }
friend bool operator==(const num& a, const num& b){return a.x
== b.x;}
friend bool operator!=(const num& a, const num& b){return a.x
!= b.x;}
};


using num = modnum<MOD>;

constexpr ull V = 1 << 20;
num invs[V], fact[V], ifact[V];

void prepare() {
invs[1] = 1;
for (ull i = 2; i < V; ++i) invs[i] = -((num::M / i) * invs[
num::M % i]);
fact[0] = ifact[0] = 1;
for (ull i = 1; i < V; ++i) {
fact[i] = fact[i - 1] * i;
ifact[i] = ifact[i - 1] * invs[i];
}
}

template<typename T> struct interpolator_t {
vector<T> S;
interpolator_t(ull N): S(N) {}
T interpolate(const vector<T>& y, T x) {
ull N = ull(y.size()); ull sgn = (N & 1 ? 1 : -1);
T res = 0, P = 1; S[N - 1] = 1;
for (ull i = N-1; i > 0; --i) S[i-1] = S[i] * (x-i);
for (ull i = 0; i < N; ++i, sgn *= -1, P *= (x - i + 1)) {
res += y[i] * sgn * P * S[i] * ifact[i] * ifact[N-1-i];
}
return res;
}
};


ull fastexp(ull b, ull e, ull m = MOD){

    ull res  = 1;
    while (e)
    {
        if(e&1) res = (res*b)%m;
        b=(b*b)%m;
        e>>=1;
    }
    return res;
}




int main(){
    ull n , k; cin >> n >> k;
    
    vector<num> sum(k+2);
    interpolator_t<num> resp(k + 2);

    prepare();

    sum[0] = 0;
    for(ull i = 1; i < k+2; i++){
        sum[i] = sum[i-1] + fastexp(i,k);
    }


    cout << resp.interpolate(sum, n).x << endl;

}