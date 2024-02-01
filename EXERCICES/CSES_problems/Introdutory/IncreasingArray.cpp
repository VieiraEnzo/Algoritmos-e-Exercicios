#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;

int main(){
    fastio;
    int n; cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++)cin >> v[i];
    
    ll quantas = 0;
    for(int i =0; i<n-1;i++){
        if(v[i] > v[i+1]){
            quantas += v[i]- v[i+1];
            v[i+1] = v[i];
        }
    }
    // if(v[n] < v[n-1]){
    //     quantas += v[n-1]- v[n];
    // }

    cout << quantas << endl;

}