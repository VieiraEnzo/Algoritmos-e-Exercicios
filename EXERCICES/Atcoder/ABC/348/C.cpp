#include <bits/stdc++.h>

using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

map<int,int> p;

int main(){
    fastio;
    int n; cin >> n;

    for(int i = 0; i < n; i++){
        int a, c; cin >> a >> c;
        if(p.count(c) > 0){
            p[c] = min(p[c], a);
        }else{
            p[c] = a;
        }
    }

    int minN = 0;
    for(auto a : p){
        minN = max(minN, a.second);
    }   

    cout << minN << endl;

}