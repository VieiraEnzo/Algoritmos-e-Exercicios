#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)

int main(){
    fastio;
    int n; cin >> n;
    vector<int> v(n,0);
    for(int i=0; i<n-1; i++){
        int temp; cin >> temp;
        v[--temp] = 1;
    }
    for(int i=0; i < n; i++){
        if(!v[i]){
            cout << i+1 << endl;
            break;
        }
    }
}