#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;
int MAXN = 1007;
int MAXK = 10001;
vector<vector<int>> dp(MAXN, vector<int> (MAXK));
vector<vector<pair<int,int>>> graph(MAXN);
vector<vector<pair<int,int>>> parent(MAXN);

void dfs(int v, int price){
    dp[v][price] = 1;
    for(auto [a,b] : graph[v]){
        if(dp[a][price + b]) continue;
        else{
            parent[a][price+b] = {v,price};
            dfs(a, price + b);
        }
    }
}


int main(){
    fastio;

    cout << "terminei" << endl;

    int n, m, k; cin >> n >> m >> k;
    int s, c; cin >> s >> c;


    for(int i = 0; i< m; i++){
        int a, b, c; cin >> a >> b >> c;
        graph[a].push_back(make_pair(b,c));
        graph[b].push_back(make_pair(a,c));
    }



    dfs(s, 0);


    if(!dp[c][k]){
        cout << "impossible" << endl;
    }else{
        while (parent[c][k].first != s)
        {
            cout << c << " ";
            auto a = parent[c][k];
            c = a.first;
            k = a.second;
        }
        cout << s << endl;
        
    }
    

}