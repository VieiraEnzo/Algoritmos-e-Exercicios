#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;

int main(){
    fastio;
    int d,r,c; cin >> d >> c >> r;
    int resp = r;
    vector<int> tiring(c);
    vector<int> dispos(r);
    for(int i = 0; i < c; i++) cin >> tiring[i];
    for(int i = 0; i < r; i++) cin >> dispos[i];

    for(int i =0; i < r; i++){
        d+= dispos[i];
    }

    for(int i =0; i < c; i ++){
        d -= tiring[i];
        if(d < 0){break;}
        resp++;
    }   
    cout << resp;
    

}