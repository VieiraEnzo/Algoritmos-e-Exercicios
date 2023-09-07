#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;

int main(){
    fastio;
    int n; cin >> n;
    vector<int> v(n,0);
    set<vector<int>> s;

    for(int i = 0; i < n ;i++){
        bool first = true;
        for(int j =1000; j >=0  ;j--){
            if(v[j] == 1){
                if(first) first = false;
                else{
                    v[j] = 0;
                    break;
                }
            }
        }
        for(int a : v){cout << a;}
        cout << endl;
    }   

}