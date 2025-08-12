#include <bits/stdc++.h>
using namespace std;

int main(){

    // entrada do problema
    int n;
    vector<int> a;

    cin >> n;

    a.assign(n, 0);
    for(int i=0; i<n; i++) cin >> a[i];

    // solução n²
    vector<bool> escondido(n);
    for(int i=n-1; i>=0; i--){
        for(int j=i-1; j>=0; j--){
            if(a[j] <= a[i]) escondido[j] = true;
        }
    }

    int resp=0;
    for(int i=0; i<n; i++) if(escondido[i]) resp++;

    cout << resp << "\n";

    return 0;
}