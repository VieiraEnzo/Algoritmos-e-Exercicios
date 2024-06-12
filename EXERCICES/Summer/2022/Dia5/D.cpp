#include <bits/stdc++.h>
using namespace std;

void unravel(int n, int o, vector<int> &resp){

    for(int i = 1; i <= n; i++){
        

    }

}

void solve(int n){
    vector<int> v(n);
    for(int i = 0; i< n; i++)cin >> v[i];

    int o; cin >> o;
    vector<int> resp(o);
    for(int i = 0; i < n; i++)cin>>v[o];

    unravel(n, o, resp);
}

int main(){
    int n;
    while (cin >> n)
    {
        solve(n);
    }
    
}