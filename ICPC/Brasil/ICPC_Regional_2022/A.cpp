#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;

int main(){
    fastio;
    int n,h; cin >> n >> h;
    int resp =0;
    for(int i =0; i < n; i ++){
        int temp; cin >> temp;
        if(h >= temp){resp++;}
    }
    cout << resp;

}