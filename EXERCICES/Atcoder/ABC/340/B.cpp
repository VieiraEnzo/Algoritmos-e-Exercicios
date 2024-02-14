#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;

int main(){
    fastio;
    int q; cin >> q;

    vector<int> v;

    while (q--)
    {
        int a; cin >> a;

        if(a == 1){
            
            int x; cin >> x;
            v.push_back(x);

        }else{
            int k; cin >> k;
            cout << v[v.size() - k] << endl;
        }
    }
    
    

}