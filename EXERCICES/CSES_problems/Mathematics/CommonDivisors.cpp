#include<bits/stdc++.h>
using namespace std;


int main(){

    cin.tie(0), ios_base::sync_with_stdio(0);

    int n; cin >> n;
    vector<int> v(n);
    vector<int> freq(1e6+ 5);

    for(int i = 0; i < n; i++) cin >> v[i];

    for(int i = 0; i < n; i++){

        for(int j = 1; j*j <= v[i]; j++){
            if(v[i] % j == 0){
                if(j*j == v[i]) freq[j]++;
                else{
                freq[j]++;
                freq[v[i]/j]++;}
            }
        }

    }

    for(int i = 1e6 + 4; i >= 1; i--){
        if(freq[i] > 1){
            cout << i << endl;
            return 0;
        }
    }
    

}