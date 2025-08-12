#include <bits/stdc++.h>
using namespace std;

int main(){

    // entrada do problema
    int n;
    vector<int> x;

    cin >> n;

    x.assign(n, 0);
    for(int i=0; i<n; i++) cin >> x[i];

    // descubro o maior elemento da lista
    int maior=0;
    for(int i=0; i<n; i++) maior = max(maior, x[i]);

    // construo o código de barras
    for(int j=maior; j>0; j--){
        for(int i=0; i<n; i++){
            // Se x[i] >= j, então x[i] >= j-1
            cout << (x[i]>=j) << " ";
        }
        cout << "\n";
    }

    return 0;
}