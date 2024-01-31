    #include <bits/stdc++.h>
    using namespace std;

    inline int nxt_pow2(int s) { return 1 << (s > 1 ? 32 -
    __builtin_clz(s-1) : 0); }
    template <typename T> struct root_of_unity {};
    template <typename dbl> struct cplx {
    dbl x, y; using P = cplx;
    cplx(dbl x_ = 0, dbl y_ = 0) : x(x_), y(y_) { }
    friend P operator+(P a, P b) { return P(a.x+b.x, a.y+b.y); }
    friend P operator-(P a, P b) { return P(a.x-b.x, a.y-b.y); }
    friend P operator*(P a, P b) { return P(a.x*b.x - a.y*b.y, a.
    x*b.y + a.y*b.x); }
    friend P conj(P a) { return P(a.x, -a.y); }
    friend P inv(P a) { dbl n = (a.x*a.x+a.y*a.y); return P(a.x/n
    ,-a.y/n); }
    };
    template <typename dbl> struct root_of_unity<cplx<dbl>> {
    static cplx<dbl> f(int k) {
    static const dbl PI = acos(-1); dbl a = 2*PI/k;
    return cplx<dbl>(cos(a),sin(a));
    }
    };

    // //(MOD,3) := (M1:897581057) ,(M3:985661441) ,(M5:935329793)
    // using M0 = modnum<998244353U>;
    // constexpr unsigned primitive_root(unsigned M) {
    // if (M == 880803841U) return 26U; // (M2)
    // else if (M == 943718401U) return 7U; // (M4)
    // else if (M == 918552577U) return 5U; // (M6)
    // else return 3U;
    // }
    // template<unsigned MOD> struct root_of_unity<modnum<MOD>> {
    // static constexpr modnum<MOD> g0 = primitive_root(MOD);
    // static modnum<MOD> f(int K) {
    // assert((MOD-1)%K == 0); return g0.pow((MOD-1)/K);
    // }
    // };

    template<typename T> struct FFT {
    vector<T> rt; vector<int> rev;
    FFT() : rt(2, T(1)) {}
    void init(int N) {
    N = nxt_pow2(N);
    if (N > int(rt.size())) {
    rev.resize(N); rt.reserve(N);
    for (int a = 0; a < N; ++a)
    rev[a] = (rev[a/2] | ((a&1)*N)) >> 1;
    for (int k = int(rt.size()); k < N; k *= 2) {
    rt.resize(2*k);
    T z = root_of_unity<T>::f(2*k);
    for (int a = k/2; a < k; ++a)
    rt[2*a] = rt[a], rt[2*a+1] = rt[a] * z;
    }
    }
    }
    void fft(vector<T>& xs, bool inverse) const {
    int N = int(xs.size());
    int s = __builtin_ctz(int(rev.size())/N);
    if (inverse) reverse(xs.begin() + 1, xs.end());
    for (int a = 0; a < N; ++a) {
    if (a < (rev[a] >> s)) swap(xs[a], xs[rev[a] >> s]);
    }
    for (int k = 1; k < N; k *= 2) {
    for (int a = 0; a < N; a += 2*k) {
    int u = a, v = u + k;
    for (int b = 0; b < k; ++b, ++u, ++v) {
    T z = rt[b + k] * xs[v];
    xs[v] = xs[u] - z, xs[u] = xs[u] + z;
    }
    }
    }
    if (inverse)
    for (int a = 0; a < N; ++a) xs[a] = xs[a] * inv(T(N));
    }
    vector<T> convolve(vector<T> as, vector<T> bs) {
    int N = int(as.size()), M = int(bs.size());
    int K = N + M , S = nxt_pow2(K); init(S);
    if (min(N, M) <= 64) {
    vector<T> res(K);
    for (int u = 0; u < N; ++u) for (int v = 0; v < M; ++v)
    res[u + v] = res[u + v] + as[u] * bs[v];
    return res;
    } else {
    as.resize(S), bs.resize(S);
    fft(as, false); fft(bs, false);
    for (int i = 0; i < S; ++i) as[i] = as[i] * bs[i];
    fft(as, true); as.resize(K); return as;
    }
    }
    };

    FFT<cplx<double>> FFT0;


    typedef unsigned long long ull;
    int main(){

        using cp = cplx<double>;

        cin.tie(0), ios_base::sync_with_stdio(0);

        int maxAi = 1010;
        int n, k; cin >> n >> k;
        k--;
        vector<cp> a(maxAi);
        vector<cp> resp(maxAi);
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
            //     cout << a.x << " ";
            // }cout << endl;
            resp = FFT0.convolve(a,resp);
            // for(auto a : resp){
            //     cout << a << " ";
            // }cout << endl;
        }
        
        for(int i = 0; i< resp.size(); i++){
            if( resp[i].x != 0){
                cout << i << " ";
            }
        }
    }
    //ll.round