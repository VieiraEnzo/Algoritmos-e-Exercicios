#include <bits/stdc++.h>
using namespace std;


class Parking{
    public:

        struct bm_t
        {
            int N, M, T;
            vector<vector<int>> grafo;
            vector<int> match, seen;
            bm_t(int a, int b) : N(a), M(a+b), T(0), grafo(M),
                                match(M, -1), seen(M, -1) {}
            
            void add_edge(int a, int b){
                grafo[a].push_back(b + N);
            }

            bool dfs(int cur){
                if(seen[cur] == T) return false;
                seen[cur] = T;
                for(int nxt : grafo[cur]) if(match[nxt] == -1){
                    match[nxt] = cur;
                    match[cur] = nxt;
                    return true;
                }
                for(int nxt : grafo[cur]) if(dfs(match[nxt])){
                    match[nxt] = cur;
                    match[cur] = nxt;
                    return true;
                }
                return false;
            }

            int solve(){
                int res = 0;
                for(int cur = 1; cur;){
                    cur = 0; ++T;
                    for(int i = 0; i < N; ++i) if(match[i] == -1)
                        cur += dfs(i);
                    res += cur;
                }
                return res;
            }

        };
    public:
        int minTime(vector<string> park){
            cin.tie(0), ios_base::sync_with_stdio(0);
            int n = park.size(), m = park[0].size();
            vector<vector<int>> mat(n, vector<int> (m));

            int parking = 1, cars = 0;
            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                    char temp = park[i][j];
                    if(temp == '.') mat[i][j] = 0;
                    else if(temp == 'X') mat[i][j] = -1;
                    else if(temp == 'C') {mat[i][j] = 1; cars++;}
                    else mat[i][j] = ++parking;             
                }
            }


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


            int carro = 0;
            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                    if(mat[i][j] == 1){
                        bfs(i,j, carro++);
                    }
                }
            }


            auto matching = [&](int mid){
                bm_t bm(cars, parking-1);
                for(int i = 0; i < cars; i++){
                    for(int j = 0; j < parking-1; j++){
                        if(cost[i][j] <= mid){
                            bm.add_edge(i, j);
                        } 
                    }
                }
                return bm.solve() == cars;
            };

            int l = 0, r = 1e5;
            while (r-l > 1)
            {
                int mid = (l+r)/2;
                if(matching(mid)){
                    r = mid;
                }else{
                    l = mid;
                }
            }
            

            if(r == 1e5){
                return -1;
            }else{
                return r;
            }
        }

};
