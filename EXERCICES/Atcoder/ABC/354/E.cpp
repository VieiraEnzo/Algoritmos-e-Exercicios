#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

vector<int> marc;
vector<pair<int,int>> cards;
map<vector<int>, int> Salva;

int game(int jogador){

    if(Salva[marc] != 0) {
        return Salva[marc] == 1? jogador : -jogador;
    }

    int pts = -jogador;
    for(int i = 0; i < cards.size(); i++){
        if(marc[i]) continue;
        for(int j = i+1; j < cards.size(); j++){
            if(marc[j]) continue;
            if(cards[i].first == cards[j].first || cards[i].second == cards[j].second){
                marc[i] = marc[j] = 1;

                if(jogador == 1){
                    pts = max(pts, game(-jogador));
                }else{
                    pts = min(pts, game(-jogador));
                }

                marc[i] = marc[j] = 0;
            }
        }
    }
    Salva[marc] = (pts == jogador);
    return pts;
}

int main(){
    fastio;
    int n; cin >> n;
    cards.resize(n);
    marc.resize(n);
    for(int i = 0; i < n; i++){
        cin >> cards[i].first >> cards[i].second; 
    }
    
    int ganhador = game(1);
    // cout << ganhador << '\n';

    if(ganhador == 1){
        cout << "Takahashi\n";
    }else{
        cout << "Aoki\n";
    }
    

}