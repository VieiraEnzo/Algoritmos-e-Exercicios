#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
typedef long long ll;
typedef pair<int,int> pii;

//Algoritmo de caminho todos para todos, funciona bem em grafos esparços
// ~NAO ESTÁ FUNCIONANDO 

struct Edge{
    int v, p;
};

struct Jhon{

    int n;
    vector<int> dist;
    vector<vector<int>> ans;
    vector<vector<Edge>> graph;

    Jhon(int n) : n(n), graph(n+2), dist(n+2, 1e9){}

    void add_edge(int a, int b, int c){
        graph[a].push_back({b, c});
    }

    void createQ(){
        int q = n+1;
        for(int i = 1; i <= n; i++){
            graph[q].push_back({i,0});
        }
    }

    void Bellman(int q){

        dist[q] = 0;

        for(int i = 0; i < n-1; i++){

            for(int i = 1; i <= n; i++){
                for(auto a : graph[i]){
                    dist[a.v] = min(dist[a.v], dist[i] + a.p);
                }
            }
        }
    }


    void Dykstra(int i){

        set<pair<int,int>> fila;
        fila.insert({0,i});

        while (!fila.empty())
        {
            int v = (*fila.begin()).second;
            ans[i][v] = (*fila.begin()).first;
            fila.erase(fila.begin());

            for(auto viz: graph[v]){
                if(ans[i][v] + viz.p < ans[i][viz.v]){
                    if(fila.count({ans[i][viz.v], viz.v}) > 0) fila.erase({ans[i][viz.v], viz.v});
                    fila.insert({ans[i][v] + viz.p, viz.v});
                }
            }
        }
        
        
    }


    void solve(){
        int q = n+1;
        createQ();
        Bellman(q);
        graph.pop_back();
        
        for(int i = 1; i <= n; i++){
            for(auto &a : graph[i]){
                a.p = a.p + (dist[i] - dist[a.v]);
            }
        }


        for(int i = 1; i<=n; i++){
            Dykstra(i);
        }

        for(int i = 1; i <=n ; i++){
            for(int j = 1; j <= n; j++){
                cout << ans[i][j] <<  " ";
            }cout << endl;
        }


    }



};

