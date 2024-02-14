#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;

pair<int,int> decomp(int a){

    bool leading = true;
    int z = 0;
    int t = 0;

    while (a != 0)
    {
        if(leading && a%10 == 0) z++;
        else{leading = false;}
        t++;
        a /= 10;
    }
    
    return {z,t};
}

void solve(){

    int n, m; cin >> n >> m; 

    priority_queue<pair<int,int>> fila;

    //ordenar por ending zeros, dps por tamanho da 

    for(int i = 0; i < n; i++){
        int temp; cin >> temp;
        auto p = decomp(temp);
        fila.push(p);
    }

    int i = 0;
    while(fila.size() != 1){
        if(i%2 == 0){
            // Anna
            auto p = fila.top();
            //cout << p.first << endl;
            fila.pop();
            fila.push({0, p.second - p.first});

        }else{
            auto p = fila.top();
            fila.pop();
            auto e = fila.top();
            //cout<< p.first <<  " " << e.first << endl;
            fila.pop();
            fila.push({e.first, p.second + e.second});
        }
        i++;
    }

    //Annas last move
    auto p = fila.top();
    fila.pop();
    fila.push({0, p.second - p.first});


    if(fila.top().second >= m + 1){
        cout << "Sasha" << endl; 
    }else{
        cout << "Anna" << endl;
    }
}


int main(){
    fastio;
    int t; cin >> t;
    while (t--)
    {
        solve();
    }
    
    

}