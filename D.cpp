#include <bits/stdc++.h>
using namespace std;

int d;

struct Objeto{

    double velocidade;
    double posição;

    Objeto(double v, double p) : velocidade(v), posição(p) {}

    double timeToHit(Objeto outro){
        if(velocidade > 0){ //Indo direção da Rapha
            double vel = velocidade - outro.velocidade;
            double ds = outro.posição - posição;
            return abs(ds/vel);
        }else{ //Indo direção do Eli
            double vel = outro.velocidade + (-velocidade);
            double ds = posição - outro.posição;
            return abs(ds/vel);
        }
    }

    double timeToHit(){
        return  (d-posição)/velocidade;
    }

    void atualiza(double t){
        posição += t*velocidade;
    }
};




int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    double tfinal, v0, v1, vMosca;
    cin >> d >> v0 >> v1 >> vMosca >> tfinal;    

    Objeto Eli = {v0, 0};
    Objeto Rafa = {v1, 1};
    Objeto Mosca = {vMosca, 0};

    auto feasible = [&](){
        // assert(Eli.posição <= Mosca.posição && Mosca.posição <= Rafa.posição);
        // assert(tfinal >= 0);
    };

    double tempoColisao = (double)d/(double)v0;

    // cout << tempoColisao << "\n";

    if(tfinal >= tempoColisao) {cout << fixed << setprecision(10) << d << "\n"; return 0;}


    while(tfinal > 0){

        // cout << "I: " << Eli.velocidade << " " << Eli.posição << "\n";

        // feasible();

        if(Mosca.velocidade > 0){

            //Direção da Rafa
            double t = Mosca.timeToHit(Rafa);
            t = min(tfinal, t);
            if(Rafa.velocidade*t+Rafa.posição > d){
                double k = Rafa.timeToHit();
                // cout << "kRafa " << k << "\n";
                // assert(k <= tfinal);
                Mosca.atualiza(k);
                Rafa.atualiza(k);
                Eli.atualiza(k);
                Rafa.velocidade = 0;
                tfinal -= k;
                // feasible();
                continue;
            }
            // cout << "Trafa " << t << "\n";
            Mosca.atualiza(t);
            Rafa.atualiza(t);
            Eli.atualiza(t);
            Mosca.velocidade *= -1;
            tfinal -= t;

        }else{  

            //Direção do Elis
            double t = Mosca.timeToHit(Eli);
            t = min(tfinal, t);
            if(Rafa.velocidade*t+Rafa.posição > d){
                double k = Rafa.timeToHit();
                // cout << "kRafa " << k << "\n";
                // assert(k <= tfinal);
                Mosca.atualiza(k);
                Rafa.atualiza(k);
                Eli.atualiza(k);
                Rafa.velocidade = 0;
                tfinal -= k;
                feasible();
                continue;
            }
            // cout << "tElist " << t << "\n";
            Mosca.atualiza(t);
            Eli.atualiza(t);
            Rafa.atualiza(t);
            Mosca.velocidade *= -1;
            tfinal -= t;

        }
        
        feasible();

        // cout << "S: " << Eli.velocidade << " " << Eli.posição << "\n";

    }

    cout << fixed << setprecision(10) << Mosca.posição << "\n";

}