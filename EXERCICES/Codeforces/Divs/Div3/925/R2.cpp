#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    vector<int> Ramigos(101), Samigos(101);
    set<int> MensagemAmigos;

    int tempo = 0;
    while (n--)
    {   
        char evento; cin >> evento;
        int x; cin >> x;
        
        if(evento == 'T'){
            tempo += (x-1);
            continue;
        }
        tempo++;

        if(evento == 'R'){
            Ramigos[x] = tempo;
            MensagemAmigos.insert(x);
        }

        if(evento == 'E'){
            Samigos[x] += tempo - Ramigos[x];
            Ramigos[x] = 0;
        }
    }

    for(int i = 0; i < 101; i++){
        if(Ramigos[i] != 0){
            Samigos[i] = -1;
        }
    } 

    for(auto a : MensagemAmigos){
        cout << a << " " << Samigos[a] << "\n";
    }
    
}