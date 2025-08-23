#include <bits/stdc++.h>
using namespace std;

int main(){

    // entrada do problema
    int n;
    vector<int> a;

    cin >> n;

    a.assign(n, 0);
    for(int i=0; i<n; i++) cin >> a[i];

    // Solução linear
    int resp=0;
    for(int l=n-2, r=n-1; l>=0; l--){
        if(a[l] <= a[r]) resp++;
        else r = l;
    }

    cout << resp << "\n";

    return 0;
}