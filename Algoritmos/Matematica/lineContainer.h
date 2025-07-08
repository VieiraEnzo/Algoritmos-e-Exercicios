/**
 * Author: Simon Lindholm
 * Date: 2017-04-20
 * License: CC0
 * Source: own work
 * Description: Container where you can add lines of the form kx+m, and query maximum values at points x.
 *  Useful for dynamic programming (``convex hull trick'').
 * Time: O(\log N)
 * Status: stress-tested
 */
struct Line { ///start-hash
	mutable ll k, m, p;
	bool operator<(const Line& o) const { return k < o.k; }
	bool operator<(ll x) const { return p < x; }
}; ///end-hash
struct LineContainer : multiset<Line, less<>> {
	static const ll inf = LLONG_MAX; //for doubles 1/.0
	ll div(ll a, ll b) { //for doubles a/b
		return a / b - ((a ^ b) < 0 && a % b); }
	bool isect(iterator x, iterator y) { ///start-hash
		if (y == end()) { x->p = inf; return false; }
		if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
		else x->p = div(y->m - x->m, x->k - y->k);
		return x->p >= y->p;
	} ///end-hash
	void add(ll k, ll m) { ///start-hash
		auto z = insert({k, m, 0}), y = z++, x = y;
		while (isect(y, z)) z = erase(z);
		if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
		while ((y = x) != begin() && (--x)->p >= y->p) 
			isect(x, erase(y));
	}///end-hash
	ll query(ll x) { ///start-hash
		assert(!empty()); auto l = *lower_bound(x);
		return l.k * x + l.m;
	}///end-hash
};