#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0); ios_base::sync_with_stdio(0);

    int n; cin >> n; 

    multiset<int> ans;
    while (n--)
    {
        int x; cin >> x;
        auto it = ans.upper_bound(x) ;
        if(it != ans.end()){
            ans.erase(it); ans.insert(x);
        }else{
            ans.insert(x);
        }
    }

    cout << ans.size() << endl;
    
}