#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;
int n; int m;


void bfs(int a, vector<vector<int>> &g, vector<int>& con)
{   
    queue<int> fila;
    fila.push(a);
    con[a] = 1;

    while (!fila.empty())
    { 
        int v = fila.front();
        fila.pop();

        for(auto a : g[v])
        {
            if(con[a]) continue;
            con[a] = 1;
            fila.push(a);
        }
        
    }
    
}



int main(){
    fastio;
    int n,m; cin >> n >> m;
    n++;
    vector<vector<int>> g(n);
    vector<int> con(n,0);

    for(int i =0; i <m; i++)
    {
        int temp1,temp2;
        cin >> temp1 >> temp2;
        g[temp1].push_back(temp2);
        g[temp2].push_back(temp1);
    }

    int num = 1;
    bfs(1,g,con);
    vector<pair<int,int>> resp;
    for(int i =1; i< n; i++)
    {
        if(con[i]) continue;
        bfs(i,g,con);
        num++;
        resp.push_back(make_pair(i-1,i));

    }

    cout << num-1 << endl;
    for(auto a : resp)
    {
        cout << a.first << " " << a.second << endl;
    }

}