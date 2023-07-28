#include <bits/stdc++.h>
using namespace std;


long long n, t;
vector<long long> v;

long long make_prod(long long u){
	long long ret = 0;
	for(int i = 0; i<n; i++){
		ret += u/v[i];
		if(ret >= t) return ret;
	}
	return ret;
}

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n >> t;
	v.resize(n);
	for(int i = 0; i<n; i++) cin >> v[i];

	long long lo = 0, hi = 1e18;
	long long ans = (lo+hi)/2;
	

	while(lo<hi){
		if(make_prod(ans) < t) lo = ans+1;
		else hi = ans;
		ans = (lo+hi)/2;
	}
	cout << ans << '\n';
	return 0;
}