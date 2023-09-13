#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;

int main(){
    fastio;
    int n; cin >> n;

    for(int i =0; i <=n; i++){
        bool found = false;
        for(int j =1; j < 10; j++){
            if(n%j == 0 && i%(n/j) == 0){
                cout << j;
                found = true;
                break;
            }       
        }
        if(!found) cout << "-";
    }

}