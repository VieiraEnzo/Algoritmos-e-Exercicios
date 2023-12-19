#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<vector<int>> graph;
int n;
void bfs();


void solve()
{
    cin >> n;
    graph.resize(n);
    for(int i = 1 ; i < n; i++)
    {
        int temp; cin >> temp; temp--;
        graph[temp].push_back(i);
    }
    bfs();

}

void bfs()
{
    queue<int> fila;
    vector<bool> vis(n);
    vector<int> height(n);
    height[0] = 1; 
    fila.push(0);

    while (!fila.empty())
    {
        int v = fila.front();
        fila.pop();

        for(auto a : graph[v])
        {
            if(vis[a]) continue;
            fila.push(a);
            vis[a] = true;
            height[a] = height[v] + 1;
        }
    }
    
    vector<int> sumA(n);
    for(int i = 0 ; i < n; i++){
        sumA[height[i]]++;
    }

    ll ans = 0;
    for(int i = 0 ; i < n; i++){
        ans += (sumA[i]/2);
    }

    cout << ans << endl;
    
}




int main(){
    int t; cin >> t;

    while (t--)
    {
        solve();
    }
    

}