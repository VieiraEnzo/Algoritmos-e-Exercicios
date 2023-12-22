#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;

int main(){
    fastio;
    int n; cin >> n;
    int dist[n][n];
    for(int i = 0 ; i < n ; i++)
        for(int j = 0; j < n; j++)
            cin >> dist[i][j];

    bool coh = true;
    int ans = 0;
    vector<vector<int>> mark(n, vector<int>(n,0));

    for(int k = 0; k < n; k++)
        for(int i = 0; i < n; i++)
            for(int j = 0; j< n; j++){
                if(dist[i][k] + dist[k][j] < dist[i][j]){coh = false;}
                if(dist[i][k] + dist[k][j] == dist[i][j] && i != j && k != i && k != j && !mark[i][j]){ans++;mark[i][j]=1;}
                dist[i][j] = min(dist[i][j],
                dist[i][k] + dist[k][j]);
            }


    if(coh)cout<< ans/2 << endl;
    else cout << -1 << endl;

}