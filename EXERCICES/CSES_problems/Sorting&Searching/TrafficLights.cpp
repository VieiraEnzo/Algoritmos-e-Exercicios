#include <bits/stdc++.h>
using namespace std;


int main(){

    int x, n; cin >> x >> n;
    multiset<int> ans;
    map<int,int> pt;
    pt[x] = x;
    ans.insert(x);

    for(int i = 0;  i < n ;i++){
        int pi; cin >> pi;
        pt[pi] = pi;
        auto pre = prev(pt.find(pi)) , nxt = next(pt.find(pi));

        if(pre != pt.end())pt[pi] = pi - (*pre).second;
        ans.insert(pt[pi]);
        ans.erase((*nxt).second);
        (*nxt).second = (*nxt).first - pi;
        ans.insert((*nxt).second);

        // cout << (*ans.end()) << " ";
        for(auto a : ans){
            cout << a << " ";
        }cout << endl;
    }

    cout << endl;


}