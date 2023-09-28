#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;
vector<vector<int>> graph;
vector<int> vis;
vector<int> father;


int bfs(int x, int y)
{
    queue<pair<int,int>> fila;
    fila.push(make_pair(x,1));
    father[x] = x;
    vis[x] = 1;

    while (!fila.empty())
    {
        int v = fila.front().first;
        int h = fila.front().second;
        fila.pop();

        for(int a : graph[v]){
            if(a == y) {father[y] = v ;return h+1;}
            if (vis[a]) continue;
            vis[a] = 1;
            father[a] = v;
            fila.push(make_pair(a,h+1));
        }
    }
    return -1;
}

int main(){
    //fastio;
    int n, m; cin >> n >> m;
    n++;
    graph.resize(n);
    vis.resize(n);
    fill(vis.begin(), vis.end(),0);
    father.resize(n);
    fill(father.begin(), father.end(),-1);

    for(int i =0; i < m; i++)
    {
        int temp1, temp2; cin >> temp1 >> temp2;
        graph[temp1].push_back(temp2);
        graph[temp2].push_back(temp1);
    }

    int ans = bfs(1,n-1);
    if(ans == -1) {cout << "IMPOSSIBLE";return 0;}
    vector<int> res;
    int i = n-1;

    // for(auto a : father)
    // {
    //     cout << a << " ";
    // }

    while (father[i] != 1)
    {
        res.push_back(i);
        i = father[i];
    }
    res.push_back(1);
    reverse(res.begin(), res.end());
    
    for(auto a : res)
    {
        cout << a << " ";
    }


    

}