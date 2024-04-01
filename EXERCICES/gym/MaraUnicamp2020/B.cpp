#include <bits/stdc++.h>

using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

//DeltaX = (t* bola.vx + bola.x) - (t*Jogador.vx + Jogador.x)
//DeltaY = (t* bola.vy + bola.y) - (t*Jogador.vy + Jogador.y)
// dvx = (b.vx - J.vx)
// dvy = (b.vy - J.vy)
// dx = (b.x - J.x)
// dy =  (b.y - J.y)
// (t*dvx + dx) * (t*dvx + dx) 
// t^2(dvx*dvx) + 2t*dvx*tx + dx*dx 
// t^2(dvy*dvy) + 2t*dvy*ty + dy*dy
// t^2(dvx*dvx + dvy*dvy) + 2t(dvx*dx + dvy*dy) + (dx*dx+dy*dy) = r
//if(delta >= 0 ) existe t
 


struct Ponto{
    int x,y,vx,vy,r;
};

Ponto bola;
Ponto J;

bool Exist_T(){
    int dvx = (bola.vx - J.vx);
    int dvy = (bola.vy - J.vy);
    int dx = (bola.x - J.x);
    int dy =  (bola.y - J.y);
    int a = dvx*dvx + dvy*dvy;
    int b = 2*(dvx*dx + dvy*dy);
    int c = dx*dx + dy*dy - bola.r;
    int delta = b*b - 4*a*c;
    if(delta < 0) return false;
  
}


int main(){
    //fastio;
    cin >> bola.x >> bola.y >> bola.vx >> bola.vy >> bola.r;
    int n; cin >> n;
    int ans = 0;
    for(int i = 0; i < n; i++){
        cin >> J.x >> J.y >> J.vx >> J.vy;
        if(Exist_T()){ans++;}
    }
    cout << ans << endl;

}