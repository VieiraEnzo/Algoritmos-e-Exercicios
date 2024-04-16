#include <bits/stdc++.h>
#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
using namespace std;
typedef pair<int,int> pii;

void tests(){
    int n; cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    set<int> s;
    
    int last = 0;
    for(int i = 0; i < n; i++){
        if(v[i] != last){
            last = v[i];
            s.insert(i+1);
        }
    }

    int t; cin >> t;

    while (t--)
    {
        int a, b; cin >> a >> b;
        auto c = s.upper_bound(a);
        if(c != s.end() && *c <= b){
            cout << a << " " << *c << "\n";
        }else{
            cout << -1  << " " << - 1 << "\n";
        }
    }
    
    cout << "\n";
}


int main(){
    fastio;
    int t; cin >> t;
    while (t--)
    {
        tests();
    }
    
}