#include <bits/stdc++.h>
using namespace std;
 
typedef pair<int,int> pii;
 
vector<int> eulerWalk(vector<vector<pii>>& gr, int nedges, int src=1) {
	int n = gr.size();
	vector<int> D(n), its(n), eu(nedges), ret, s = {src};
	D[src]++; // to allow Euler paths, not just cycles
	while (!s.empty()) { ///start-hash
		int x = s.back(), y, e, &it = its[x], end = int(gr[x].size());
		if (it == end){ ret.push_back(x); s.pop_back(); continue; }
		tie(y, e) = gr[x][it++];
		if (!eu[e])
			D[x]--, D[y]++, eu[e] = 1, s.push_back(y);
	} ///end-hash
	for(auto &x : D) if (x < 0 || int(ret.size()) != nedges+1) return {};
	return {ret.rbegin(), ret.rend()};
}
 
int main(){
    cin.tie(0), ios_base::sync_with_stdio(0);
    int n, m; cin >> n >> m;
    vector<vector<pair<int,int>>> grafo(n+1);
 
    for(int i = 0; i < m; i++){
        int a,b; cin >> a >> b;
        grafo[a].push_back({b,i});
        grafo[b].push_back({a,i});
    }
 
    auto ans = eulerWalk(grafo, m, 1);
    
    if(ans.empty() || ans.back() != 1){
        cout << "IMPOSSIBLE" << "\n";
        return 0;
    }
    
    for(auto a : ans){
        cout << a << " ";
    }
}