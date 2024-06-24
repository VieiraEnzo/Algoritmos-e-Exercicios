#include <bits/stdc++.h>
using namespace std;

template<class cost_t> pair<cost_t, vector<int>> hungarian(const vector<vector<cost_t>> &a){
    int n = a.size() + 1, m = a[0].size() + 1;
    
    vector<int> p(m), ans(n - 1);
    vector<cost_t> u(n), v(m); 
	for(int i = 1; i < n; ++i) { 
		p[0] = i; int j0 = 0;
		vector<cost_t> dist(m, 1e9);  
        vector<int> pre(m, -1); 
		vector<bool> done(m + 1);
		do {
			done[j0] = true;
			int i0 = p[j0], j1; 
            cost_t delta = 1e9;
			for(int j = 1; j < m; ++j) if (!done[j]) {
				auto cur = a[i0-1][j-1] - u[i0] - v[j];
				if (cur < dist[j]) dist[j] = cur, pre[j] = j0;
				if (dist[j] < delta) delta = dist[j], j1 = j;
			}
			for(int j = 0; j < m; ++j)
				if (done[j]) u[p[j]] += delta, v[j] -= delta;
				else dist[j] -= delta;
			j0 = j1;
		} while (p[j0]);
		while (j0) { 
			int j1 = pre[j0]; p[j0] = p[j1], j0 = j1;
		}
	}
	for(int j = 1; j < m; ++j) if (p[j]) ans[p[j]-1] = j-1;
	return {-v[0], ans}; 
}

int main(){
    cin.tie(0), ios_base::sync_with_stdio(0);
    int n; cin >> n;
    vector<vector<double>> mat(n, vector<double> (n));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            double temp; cin >> temp;
            mat[i][j] = -log2(temp);
        }
    }

    auto ans = hungarian<double> (mat);

    vector<int> order(n);
    vector<int> v = ans.second;
    for(int i = 0; i < n; i++){
        order[v[i]] = i;
    }
    for(int i = 0; i < n; i++) cout << order[i] + 1 << " ";

}