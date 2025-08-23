#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(0), ios_base::sync_with_stdio(false);

    int n,t; cin >> n >> t;

    vector<pair<int,int>> obj(n);

    vector<multiset<pair<int,int>>> estoque(t+1);
    multiset<pair<int,int>> total;

    for(int i = 0; i < n; i++){
        cin >> obj[i].second;
    }

    for(int i = 0; i < n; i++){
        cin >> obj[i].first;
        total.insert(obj[i]);
        estoque[obj[i].second].insert(obj[i]);
    }

    ll ans = 0;

    int c; cin >> c;

    while(c--){
        int u; cin >> u;

        if(u == 0){
            if(total.empty()) continue;
            pair<int,int> o = *total.begin();
            ans += o.first;
            estoque[o.second].erase(estoque[o.second].find(o));
            total.erase(total.find(o));
        }else{
            if(estoque[u].empty()) continue;
            pair<int,int> o = *estoque[u].begin(); 
            ans += o.first;
            estoque[u].erase(estoque[u].find(o));
            total.erase(total.find(o));
        }

    }

    cout << ans << "\n";




}   
