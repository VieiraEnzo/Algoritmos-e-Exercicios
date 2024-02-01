#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)

int main(){
    fastio;
    int n; cin >> n;
    vector<int> v(n);
    for(int i=0; i<n; i++){cin >> v[i];}
    sort(v.begin(),v.end());
    for(int i=0; i < n; i++){
        if((v[i]+1) != v[i+1]){
            cout << v[i]+1 << endl;
            return 0;
        }
    }
    cout << v[n-1]+1;
}