#include <bits/stdc++.h>
using namespace std;

long long int elevado(long long int a, long long int b){
    long long int elevado = 1;
    if(b == 0){return 1;}
    for(int i = 0; i < b; i++){
        elevado *= a;
    }
    return elevado;
}

int main(){

    int n;
    string mask;
    cin >> n;
    for(int i=0; i < n ;i++){

        long long int numer_interrogation = 1;
        long long int interrogation_front = 1;
        cin >> mask;

        if (mask[0] == '0'){cout << 0 << endl; continue;}
        else if (mask[0] == '?'){ interrogation_front = 9;}

        for(int i=1; i < mask.size();i++){
            if (mask[i] == '?'){
                numer_interrogation ++;
            }
        }
        if(numer_interrogation > 1){numer_interrogation = elevado(10,(numer_interrogation -1));}
        cout << numer_interrogation * interrogation_front << endl;

    }
}
