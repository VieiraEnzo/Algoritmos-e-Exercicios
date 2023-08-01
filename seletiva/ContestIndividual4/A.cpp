#include <bits/stdc++.h>
using namespace std;

int main(){
    pair<int,int> player;
    player.first = 0;
    player.second = 0;
    set<pair<int,int>> itens;
    string  S;
    int N,M,H,K;
    cin >> N >> M >> H >> K;
    cin >> S;
    int tempx,tempy;
    for(int i =0; i < M; i ++){
        cin >> tempx >> tempy;
        itens.insert(make_pair(tempx,tempy));
    }
    bool did = false;
    for(auto s : S){
        if(H == 0){cout << "No"; did = true;break;}
        if(s == 'R'){
            player.first += 1;
        }
        else if(s == 'U'){
            player.second += 1;
        }
        else if(s == 'D'){
            player.second -= 1;
        }
        else if(s == 'L'){
            player.first -= 1;
        }
        H -= 1;
        auto it = itens.find(make_pair(player.first, player.second));
        if(it != itens.end()){
            if(H < K){
                    H = K;
                    itens.erase(make_pair(player.first, player.second));
                    
                }
        }
    }
    if(!did){
        cout << "Yes";
    }
    
}
    

