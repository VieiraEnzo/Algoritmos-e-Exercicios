#include <bits/stdc++.h>
using namespace std;

#ifdef local
    #include "/home/enzo/Documents/Prog/OBItraining/debug.h"
    #define pr(...) debug(#__VA_ARGS__, __VA_ARGS__)
    #define prs(...) debug_nameless(__VA_ARGS__)
#else
    #define pr(...) 69
    #define prs(...) 69
#endif

template<class cost_t> pair<cost_t, vector<int>> hungarian(const vector<vector<cost_t>> &a){
    int n = a.size() + 1, m = a[0].size() + 1;
    
    vector<int> p(m), ans(n - 1);
    vector<cost_t> u(n), v(m); 
	for(int i = 1; i < n; ++i) { 
		p[0] = i; int j0 = 0;
		vector<cost_t> dist(m, 2e9);  
        vector<int> pre(m, -1); 
		vector<bool> done(m + 1);
		do {
			done[j0] = true;
			int i0 = p[j0], j1; 
            cost_t delta = 2e9;
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
    int n, m; cin >> n >> m;
    vector<vector<int>> mat(n, vector<int> (m));

    int parking = 1, cars = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            char temp; cin >> temp;
            if(temp == '.') mat[i][j] = 0;
            else if(temp == 'X') mat[i][j] = -1;
            else if(temp == 'C') {mat[i][j] = 1; cars++;}
            else mat[i][j] = ++parking;             
        }
    }

    pr(mat);

    vector<vector<int>> cost(cars, vector<int> (parking-1, 1e9));

    auto canGo = [&](int i, int j){
        if(i < 0 || i >= n) return false;
        if(j < 0 || j >= m) return false;
        return true;
    };

    auto bfs = [&](int i, int j, int carro){   
        vector<pair<int,int>> dir = {{1,0}, {0,1}, {-1,0}, {0,-1}};
        vector<vector<int>> marc(n, vector<int> (m));
        vector<vector<int>> dist(n, vector<int> (m));
        queue<pair<int,int>> fila;
        marc[i][j] = 1;
        fila.push({i,j});

        while (!fila.empty())
        {
            pair<int,int> cur = fila.front();
            fila.pop();
            for(auto d : dir){
                if(!canGo(cur.first + d.first, cur.second + d.second) || marc[cur.first + d.first][cur.second + d.second]) continue;
                int viz = mat[cur.first + d.first ][cur.second + d.second];
                if(viz == -1) continue;                    
                if(viz != 0 && viz != 1)
                    cost[carro][mat[cur.first + d.first ][cur.second + d.second] - 2] = dist[cur.first][cur.second] + 1;
                
                marc[cur.first + d.first][cur.second + d.second] = 1;
                fila.push({cur.first + d.first, cur.second + d.second});
                dist[cur.first + d.first][cur.second + d.second] = dist[cur.first][cur.second] + 1;
            }
        }
        
    };

    pr(cost);

    int carro = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(mat[i][j] == 1){
                bfs(i,j, carro++);
            }
        }
    }

    pr(cost);

    auto ans = hungarian(cost);

    if(ans.first >= 1e9){
        cout << -1 << "\n";
    }else{
        int resp = 1e9;
        for(int i = 0; i < ans.second.size(); i++){
            resp = min(resp, cost[i][ans.second[i]]);
        }
        cout << resp << "\n";
    }


}