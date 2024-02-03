#include <bits/stdc++.h>
using namespace std;
int maxn = 2e4 + 5;
vector<vector<pair<int,int>>> graph(maxn);
vector<int> pai(maxn);
vector<int> peso(maxn);
int n;


int ff(int x){
    if(pai[x] == x) return x;
    return pai[x] = ff(pai[x]);
}

void uu(int x, int y){
    x = ff(x), y = ff(y);
    if(x == y) return;
    if(peso[y]>peso[x]) swap(x,y);
    pai[y]=x;
    peso[x]+=peso[y];
}

void init(){
    for(int i=1; i<=n; i++){
        pai[i]=1;
        peso[i]=1;
    }
}

template<typename T> void Kruskal(){
    init();
    sort(total.begin(), total.end());
    for(array<init, 3> i : total){
        if(ff(i[1]) != ff(i[2])){
            uu(i[1], i[2]);
            resp+=i[0];
        }
    }
}

void solve(int n){
    int m,s; 
    cin >> m >> s;

    for(int i = 0; i< m; i++){
        int a,b,w; cin >> a >> b >> w;
        graph[a].push_back({b,w});
        graph[b].push_back({a,w});
    }
}


int main(){
    
    while (cin >> n)
    {
        solve(n);
    }
    
}