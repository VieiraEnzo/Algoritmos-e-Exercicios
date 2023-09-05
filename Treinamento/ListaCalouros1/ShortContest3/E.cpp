#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    for(int init =0; init < t; init ++){
        string a;
        cin >> a;
        auto inicio = a.begin();
        auto fim = a.end();
        fim--;
        bool palindromo = true;
        bool same_letter = true;
        while (inicio < fim)
        {   
            if(*inicio != *fim){
                palindromo = false;
            }
            inicio++;
            fim--;
        }
        for(int i =0; i < a.size() -1; i ++){
            if(a[i] != a[i+1]){same_letter =false;}
        }

        if(palindromo && same_letter){cout << -1 << endl;}
        else if(palindromo && !same_letter){cout << a.size()-1<< endl;}
        else{cout << a.size()<< endl;}


    }
}