#include <bits/stdc++.h>
using namespace std;


int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--){
		int n, m;
		cin >> n >> m;
		vector<int> b(n*m);
		for(int i = 0; i<n*m; i++) cin >> b[i];
		sort(b.begin(), b.end());
		int max_diff = b[b.size()-1] - b[0];
		int max_diff_2 = max(b[b.size()-1] - b[1], b[b.size()-2] - b[0]);
		if(n > m) swap(n, m);
		int ans = (n-1)*(max_diff_2);
		ans += n*(m-1)*max_diff;
		cout << ans << '\n';
	}
	return 0;
}