#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;
int MAXN = 1007;
int MAXK = 10007;
int k;
vector<vector<int>> dp(MAXN, vector<int> (MAXK));
vector<vector<pair<int,int>>> graph(MAXN);
vector<vector<pair<int,int>>> parent(MAXN, vector<pair<int,int>> (MAXK));

void dfs(int v, int price){
    dp[v][price] = 1;
    for(auto [a,b] : graph[v]){
        if(price + b > k) continue;
        if(dp[a][price + b]) continue;
        else{
            parent[a][price+b] = {v,price};
            dfs(a, price + b);
        }
    }
}


int main(){
    fastio;

    int n, m; cin >> n >> m >> k;
    int s, c; cin >> s >> c;


    for(int i = 0; i< m; i++){
        int a, b, c; cin >> a >> b >> c;
        graph[a].push_back(make_pair(b,c));
        graph[b].push_back(make_pair(a,c));
    }


    dfs(s, 0);

    vector<int> ans;

    if(!dp[c][k]){
        cout << "impossible" << endl;
    }else{
        while (k != 0)
        { 
            ans.push_back(c);
            auto a = parent[c][k];
            c = a.first;
            k = a.second;
        }
        ans.push_back(s);   

        reverse(ans.begin(), ans.end());

        for(auto a : ans){
            cout << a << " ";
        }cout << endl;
    }
    

}