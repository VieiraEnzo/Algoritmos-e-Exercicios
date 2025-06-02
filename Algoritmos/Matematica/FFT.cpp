struct FFT{
    typedef complex<double> C;
    typedef vector<double> vd;
    typedef vector<long long int> vl;
    typedef vector<int> vi;
 
    /*
        * Author: Ludo Pulles, chilli, Simon Lindholm
        * Date: 2019-01-09
        * License: CC0
        * Source: http://neerc.ifmo.ru/trains/toulouse/2017/fft2.pdf (do read, it's excellent)
        Accuracy bound from http://www.daemonology.net/papers/fft.pdf
        * Description: fft(a) computes $\hat f(k) = \sum_x a[x] \exp(2\pi i \cdot k x / N)$ for all $k$. N must be a power of 2.
        Useful for convolution:
        \texttt{conv(a, b) = c}, where $c[x] = \sum a[i]b[x-i]$.
        For convolution of complex numbers or more than two vectors: FFT, multiply
        pointwise, divide by n, reverse(start+1, end), FFT back.
        Rounding is safe if $(\sum a_i^2 + \sum b_i^2)\log_2{N} < 9\cdot10^{14}$
        (in practice $10^{16}$; higher for random inputs).
        Otherwise, use NTT/FFTMod.
        * Time: O(N \log N) with $N = |A|+|B|$ ($\tilde 1s$ for $N=2^{22}$)
        * Status: somewhat tested
        * Details: An in-depth examination of precision for both FFT and FFTMod can be found
        * here (https://github.com/simonlindholm/fft-precision/blob/master/fft-precision.md)
    */
    void fft(vector<C>& a) {
        int n = a.size(), L = 31 - __builtin_clz(n);
        static vector<complex<long double>> R(2, 1);
        static vector<C> rt(2, 1);  // (^ 10% faster if double)
        for (static int k = 2; k < n; k *= 2) {
            R.resize(n); rt.resize(n);
            auto x = polar(1.0L, acos(-1.0L) / k);
            for(int i=k; i<2*k; i++) rt[i] = R[i] = i&1 ? R[i/2] * x : R[i/2];
        }
        vi rev(n);
        for(int i = 0; i < n; i++) rev[i] = (rev[i / 2] | (i & 1) << L) / 2;
        for(int i = 0; i < n; i++)  if (i < rev[i]) swap(a[i], a[rev[i]]);
        for (int k = 1; k < n; k *= 2)
            for (int i = 0; i < n; i += 2 * k) for(int j = 0; j < k; j++) {
                // C z = rt[j+k] * a[i+j+k]; // (25% faster if hand-rolled)  /// include-line
                auto x = (double *)&rt[j+k], y = (double *)&a[i+j+k];        /// exclude-line
                C z(x[0]*y[0] - x[1]*y[1], x[0]*y[1] + x[1]*y[0]);           /// exclude-line
                a[i + j + k] = a[i + j] - z;
                a[i + j] += z;
            }
    }
    // multiplica dois polinomios
    vd conv(const vd& a, const vd& b) {
        if (a.empty() || b.empty()) return {};
        vd res(a.size() + b.size() - 1);
        int L = 32 - __builtin_clz(res.size()), n = 1 << L;
        vector<C> in(n), out(n);
        copy(a.begin(), a.end(), begin(in));
        for(int i = 0; i < b.size(); i++) in[i].imag(b[i]);
        fft(in);
        for (C& x : in) x *= x;
        for(int i = 0; i < n; i++) out[i] = in[-i & (n - 1)] - conj(in[i]);
        fft(out);
        for(int i = 0; i < res.size(); i++) res[i] = imag(out[i]) / (4 * n);
        return res;
    }

    vl conv(const vl& a, const vl& b) {
        if (a.empty() || b.empty()) return {};
        vd res(a.size() + b.size() - 1);
        int L = 32 - __builtin_clz(res.size()), n = 1 << L;
        vector<C> in(n), out(n);
        copy(a.begin(), a.end(), begin(in));
        for(int i = 0; i < b.size(); i++) in[i].imag(b[i]);
        fft(in);
        for (C& x : in) x *= x;
        for(int i = 0; i < n; i++) out[i] = in[-i & (n - 1)] - conj(in[i]);
        fft(out);
        for(int i = 0; i < res.size(); i++) res[i] = imag(out[i]) / (4 * n);
        vl r(a.size() + b.size() - 1);
        for(int i = 0; i < res.size(); i++) r[i] = (ll)(res[i]+.5);
        return r;
    }
 
    /*
        * Author: chilli
        * Date: 2019-04-25
        * License: CC0
        * Source: http://neerc.ifmo.ru/trains/toulouse/2017/fft2.pdf
        * Description: Higher precision FFT, can be used for convolutions modulo arbitrary integers
        * as long as $N\log_2N\cdot \text{mod} < 8.6 \cdot 10^{14}$ (in practice $10^{16}$ or higher).
        * Inputs must be in $[0, \text{mod})$.
        * Time: O(N \log N), where $N = |A|+|B|$ (twice as slow as NTT or FFT)
        * Status: stress-tested
        * Details: An in-depth examination of precision for both FFT and FFTMod can be found
        * here (https://github.com/simonlindholm/fft-precision/blob/master/fft-precision.md)
    */
    // multiplica dois polinomios modulo algum inteiro
    template<int M> vl convMod(const vl &a, const vl &b) {
        if (a.empty() || b.empty()) return {};
        vl res(a.size() + b.size() - 1);
        int B=32-__builtin_clz(res.size()), n=1<<B, cut=int(sqrt(M));
        vector<C> L(n), R(n), outs(n), outl(n);
        for(int i = 0; i < a.size(); i++) L[i] = C((int)a[i] / cut, (int)a[i] % cut);
        for(int i = 0; i < b.size(); i++) R[i] = C((int)b[i] / cut, (int)b[i] % cut);
        fft(L), fft(R);
        for(int i = 0; i < n; i++) {
            int j = -i & (n - 1);
            outl[j] = (L[i] + conj(L[j])) * R[i] / (2.0 * n);
            outs[j] = (L[i] - conj(L[j])) * R[i] / (2.0 * n) / 1i;
        }
        fft(outl), fft(outs);
        for(int i = 0; i < res.size(); i++) {
            ll av = ll(real(outl[i])+.5), cv = ll(imag(outs[i])+.5);
            ll bv = ll(imag(outl[i])+.5) + ll(real(outs[i])+.5);
            res[i] = ((av % M * cut + bv) % M * cut + cv) % M;
        }
        return res;
    }
 
    /*
        * Author: chilli
        * Date: 2019-04-16
        * License: CC0
        * Source: based on KACTL's FFT
        * Description: ntt(a) computes $\hat f(k) = \sum_x a[x] g^{xk}$ for all $k$, where $g=\text{root}^{(mod-1)/N}$.
        * N must be a power of 2.
        * Useful for convolution modulo specific nice primes of the form $2^a b+1$,
        * where the convolution result has size at most $2^a$. For arbitrary modulo, see FFTMod.
        \texttt{conv(a, b) = c}, where $c[x] = \sum a[i]b[x-i]$.
        For manual convolution: NTT the inputs, multiply
        pointwise, divide by n, reverse(start+1, end), NTT back.
        * Inputs must be in [0, mod).
        * Time: O(N \log N)
        * Status: stress-tested
    */
    const ll mod = (119 << 23) + 1, root = 62; // = 998244353
    // For p < 2^30 there is also e.g. 5 << 25, 7 << 26, 479 << 21
    // and 483 << 21 (same root). The last two are > 10^9.
    void ntt(vl &a) {
        int n = a.size(), L = 31 - __builtin_clz(n);
        static vl rt(2, 1);
        for (static int k = 2, s = 2; k < n; k *= 2, s++) {
            rt.resize(n);
            ll z[] = {1, modpow(root, mod >> s)};
            for(int i = k; i < 2*k; i++) rt[i] = rt[i / 2] * z[i & 1] % mod;
        }
        vi rev(n);
        for(int i = 0; i < n; i++) rev[i] = (rev[i / 2] | (i & 1) << L) / 2;
        for(int i = 0; i < n; i++) if (i < rev[i]) swap(a[i], a[rev[i]]);
        for (int k = 1; k < n; k *= 2)
            for (int i = 0; i < n; i += 2 * k) for(int j = 0; j < k; j++) {
                ll z = rt[j + k] * a[i + j + k] % mod, &ai = a[i + j];
                a[i + j + k] = ai - z + (z > ai ? mod : 0);
                ai += (ai + z >= mod ? z - mod : z);
            }
    }
    vl conv_ntt(const vl &a, const vl &b) {
        if (a.empty() || b.empty()) return {};
        int s = a.size() + b.size() - 1, B = 32 - __builtin_clz(s),
            n = 1 << B;
        int inv = modpow(n, mod - 2);
        vl L(a), R(b), out(n);
        L.resize(n), R.resize(n);
        ntt(L), ntt(R);
        for(int i = 0; i < n; i++)
            out[-i & (n - 1)] = (ll)L[i] * R[i] % mod * inv % mod;
        ntt(out);
        return {out.begin(), out.begin() + s};
    }
    ll modpow(ll b, ll e) {
        ll ans = 1;
        for (; e; b = b * b % mod, e /= 2)
            if (e & 1) ans = ans * b % mod;
        return ans;
    }
};
