#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    string mask;
    cin >> n;
    for(int i=0; i < n ;i++){

        int numer_interrogation = 1;
        int interrogation_front = 1;
        cin >> mask;

        if (mask[0] == '0'){cout << 0; continue;}
        else if (mask[0] == '?'){ interrogation_front = 9;}
        else{}

        for(int i=1; i < mask.size();i++){
            if (mask[i] == '?'){
                numer_interrogation ++;
            }
        }
        if(numer_interrogation > 1){numer_interrogation = pow(10,(numer_interrogation -1));}
        cout << numer_interrogation * interrogation_front;

    }
}
