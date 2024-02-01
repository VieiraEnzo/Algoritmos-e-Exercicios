#include <bits/stdc++.h>
using namespace std;


int main(){
    long long int t;
    cin >> t;
    pair<long long int,long long int> Marry;

    for(int init = 0;init < t; init++){
        // int resto;
        cin >> Marry.first >> Marry.second;

        // if(Marry.first > Marry.second){resto = Marry.first % Marry.second;}
        // else{resto = Marry.second % Marry.first;}

        // if(resto == 0){cout << 1 << endl << Marry.first << ' ' << Marry.second << endl;}

        // else{
        //     cout << 2 << endl << Marry.first - 1 << ' ' << 1 << endl << Marry.first << ' ' << Marry.second << endl;
        // }
        cout << 2 << endl << Marry.first + 1 << ' ' << 1 << endl << Marry.first << ' ' << Marry.second << endl;
    }
}
