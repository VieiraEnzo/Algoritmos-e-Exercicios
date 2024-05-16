#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pii;
typedef pair<ll,ll> pll;

struct sensor{
    ll x, y, s;
};

vector<vector<ll>> grafo(1010);
vector<sensor> sensores(1010);
vector<ll> marc(1010);

void dfs(ll v){
    marc[v] = 1;
    // cout << v << "\n";
    for(ll i : grafo[v]){
        if(marc[i]) continue;
        dfs(i);
    }
}

bool toca(sensor a, sensor b){
    return (a.x-b.x) * (a.x-b.x) + (a.y-b.y)*(a.y-b.y) <= (a.s + b.s) * (a.s + b.s);
}

int main(){
    fastio;
    ll m, n, k; cin >> m >> n >> k;


    for(ll i = 0; i < k; i++){
        ll x, y, s; cin >> x >> y >> s;
        sensores[i] = {x,y,s};
        for(ll j = 0; j < i; j ++){
            if(toca(sensores[i], sensores[j])){
                grafo[i].push_back(j);
                grafo[j].push_back(i);
            }
        }
    }   

    ll Baixo = 1001;
    ll Direita = 1002;
    ll Esquerda = 1003;
    ll Cima = 1004;

    for(ll i = 0; i < k; i++){
        if(sensores[i].y - sensores[i].s <= 0){
            grafo[i].push_back(Baixo);
            grafo[Baixo].push_back(i);
        }
        if(sensores[i].y + sensores[i].s >= n){
            grafo[i].push_back(Cima);
            grafo[Cima].push_back(i);
        }
        if(sensores[i].x - sensores[i].s <= 0){
            grafo[i].push_back(Esquerda);
            grafo[Esquerda].push_back(i);
        }
        if(sensores[i].x + sensores[i].s >= m){
            grafo[i].push_back(Direita);
            grafo[Direita].push_back(i);
        }
    }

    
    dfs(Baixo);
    dfs(Direita);

    if(marc[Cima] || marc[Esquerda]){
        cout << "N\n";
    }else{
        cout << "S\n";
    }

}