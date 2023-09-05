#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main(){
    long long int t;
    cin >> t;
    long long int n, num;
    vector<int> participante;

    for(int init = 0;init < t; init++){
        participante.clear();
        cin >> n;

        for(int i=0; i < n; i ++){
            cin >> num;
            participante.push_back(num);
        }
        int maior = 0, Smaior = 1;
        for(int i = 0; i < participante.size() ; i++){
            if (participante[i] > participante[maior]){
                Smaior = maior;
                maior = i;
                continue;
                }
            if(participante[i] > participante[Smaior] && i != maior){
                Smaior = i;   
            }
        

        }
        

        for(int i = 0; i < participante.size() ; i++){
            if(i == maior){
                cout << participante[maior] - participante[Smaior] << ' ';
            }
            else{
                cout << participante[i] - participante[maior] << ' ';
            }
        }
        cout << endl;


    }


}
