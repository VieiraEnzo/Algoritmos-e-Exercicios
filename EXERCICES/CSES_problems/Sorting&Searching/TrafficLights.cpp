#include <bits/stdc++.h>
using namespace std;


int main(){

    cin.tie(nullptr); ios_base::sync_with_stdio(0);

    int x, n; cin >> x >> n;
    multiset<int> ans;
    ans.insert(x);
    set<int> pt;
    pt.insert(x);
    pt.insert(0);

    for(int i = 0;  i < n ;i++){
        int pi; cin >> pi;
        pt.insert(pi);
        auto pos = pt.find(pi);
        auto nxt = next(pos);
        auto pre = prev(pos);

        ans.erase(ans.find(*nxt - *pre));

        ans.insert(*pos - *pre);
        ans.insert(*nxt - *pos);

        // for(auto a : ans){
        //     cout << a << " "; 
        // }cout << endl;
        cout << (* (--ans.end())) << " ";
    }   

    cout << endl;


}