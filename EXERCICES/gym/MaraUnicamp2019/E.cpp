#include <bits/stdc++.h>

using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

double sq(double a){
    double l = 0, r = 1e9;
    int cont = 300;
    while (cont--)
    {
        double mid = (r+l)/2.0;
        if(mid*mid < a){
            l = mid;
        }else{
            r = mid;
        }
    }
    return l;
}

struct Ponto
{
    long double x,y,z;

    Ponto operator+(Ponto a) const{
        return {x + a.x, y + a.y, z + a.z};
    }

    Ponto operator-(Ponto a) const{
        return {x - a.x, y - a.y, z - a.z};
    }
    Ponto operator*(long double a) const{
        return {x * a, y *a , z * a};
    }

    bool operator<(Ponto a) const{
        if(x == a.x){
            if(y == a.y){
                return z < a.z;
            }
            return y < a.y;
        }
        return x < a.x;
    }
};

long double dist(Ponto a, Ponto b){
    long double dx = a.x - b.x;
    long double dy = a.y - b.y;
    long double dz = a.z - b.z;
    return sqrt((dx*dx) + (dy*dy) + (dz*dz));
}


int main(){
    //fastio;
    int vel; cin >> vel;
    vector<Ponto> esfera(7);
    for(int i = 0; i < 7; i++){
        cin >> esfera[i].x >> esfera[i].y >> esfera[i].z;
    }

    sort(esfera.begin(), esfera.end());
    vector<long double > vt;

    long double resposta = 1e9;
    do{
        for(int i = 0; i < 7; i++){ //Vegeta pega as i primeiras
        vt.clear();
            long double ans = 0;
            Ponto posVegeta = {0,0,0}, posGoku = {0,0,0};
            vector<int> vegeta, goku;
            vegeta.push_back(7), goku.push_back(7);
            for(int j = 0; j < i; j++)vegeta.push_back(j);
            for(int j = i; j < 7; j++)goku.push_back(j);
            esfera.push_back({0,0,0});
            // vegeta = {7, 6, 5, 4, 2 , 1, 0};
            // goku = {7, 3};
            // vector<int> veg2 = vegeta;
            // vector<int> gk2 = goku;

            while (!vegeta.empty() && !goku.empty())
            {
                int vind = vegeta.back();
                int gind = goku.back();
                long double gdist = dist(posGoku, esfera[gind]); 
                long double vdist = dist(posVegeta, esfera[vind]);
                long double tdist = dist(posVegeta, esfera[gind]);

                //printf("%d %d %ld % ld % ld \n", vind, gind, gdist, vdist, tdist);
                //printf("%ld %ld \n", posGoku.x, posVegeta.x);
                
                
                if(tdist < gdist){
                    gdist = tdist;
                    posGoku = {posVegeta.x, posVegeta.y, posVegeta.z};
                }
                if(gdist < vdist){
                    posGoku = esfera[gind];
                    goku.pop_back();
                    long double rel = gdist/vdist;
                    Ponto vec = esfera[vind] - posVegeta;
                    posVegeta = posVegeta + (vec*rel); //errado?
                    ans += gdist;

                }else if(vdist < gdist){
                    posVegeta = esfera[vind];
                    vegeta.pop_back();
                    long double rel = vdist/gdist;
                    Ponto vec = esfera[gind] - posGoku;
                    posGoku = posGoku + (vec*rel);
                    ans += vdist;
                }else{
                    posVegeta = esfera[vind];
                    posGoku = esfera[gind];
                    vegeta.pop_back();
                    goku.pop_back();
                    ans += vdist;
                }
                // vt.push_back(ans);
                // vt.push_back(posGoku.x);
                // vt.push_back(posVegeta.x);
                // vt.push_back(gdist);
                // vt.push_back(vdist);
            }

            while(!vegeta.empty()){
                int vind = vegeta.back();
                long double vdist = dist(posVegeta, esfera[vind]); 
                posVegeta = esfera[vind];
                vegeta.pop_back();
                ans += vdist;
            }

            // cout << posGoku.x << " " << posVegeta.x <<endl;
            while(!goku.empty()){
                int gind = goku.back();
                long double gdist = dist(posGoku, esfera[gind]);
                long double tdist = dist(posVegeta, esfera[gind]);
                posGoku = esfera[gind];
                goku.pop_back();
                ans += min(gdist, tdist);
                // cout << tdist << " "<<  gdist << " " << posGoku.x << " " << posVegeta.x << " " << gind  << " " << ans << endl;
            }
            // if(ans == min(ans, resposta)){
            //     cout << "__________________" << endl;
            //     cout << posGoku.x << " " << posVegeta.x << " " << ans << endl;
            //     for(auto a :gk2) cout << "(" << a << ", "<<esfera[a].x  << ")"<< " ";
            //     cout << endl;
            //     for(auto a :veg2) cout << "(" << a << ", "<<esfera[a].x  << ")"<< " ";
            //     cout << endl;
            //     int i = 0;
            //     while (i < vt.size())
            //     {
            //         cout << vt[i] << " " << vt[i+1] << " " << vt[i+2] << " " << vt[i+3] << " " <<  vt[i+4];
            //         cout <<endl;
            //         i+=5;
            //     }
                
            // }

            resposta = min(resposta, ans);
            esfera.pop_back();
        }

    }while(next_permutation(esfera.begin(), esfera.end()));

    // cout << resposta << endl;
    cout << fixed << setprecision(7) <<resposta/(long double)vel << endl;

}