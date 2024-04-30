#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    multiset<int> s;
    for(int i = 0; i < n; i++){
        int temp; cin >> temp;
        if(s.count(temp) < 2){
            s.insert(temp);
        }
    }

    cout << (s.size()+1)/2 << endl;
}

int main(){
    cin.tie(0), ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--)
    {
        solve();
    }
    
}