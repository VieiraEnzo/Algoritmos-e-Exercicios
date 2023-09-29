#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;

void bfs(int x)
{

}



int main(){
    fastio;
    int n, m; cin >> n >> m;
    vector<vector<int>> g(n+1);
    for(int i =0; i <m; i++)
    {
        int t1, t2; cin >> t1 >> t2;
        g[t1].push_back(t2);
        g[t2].push_back(t1);
    }



    

}