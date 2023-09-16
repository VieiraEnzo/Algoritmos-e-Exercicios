#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;

int main(){
    fastio;
    int n, q; cin >> n >> q;
    vector<int> v(n);
    for(int i =0; i <n; i ++) cin >> v[i];
    vector<vector<int>> m(n);

    // STATIC RANGE MINIMUM QUERRY
    for(int i =0; i <n-1;i++)
    {
        m[i].push_back(min(v[i],v[i+1]));
    }
    for(int j =2; j < n-1; j*=2)
        for(int i =0; i < n-1; i++){
            if(i + j > n-1) continue;
            m[i].push_back(min(m[i].back(), m[i+j-1].back()));
        }
    
    for(vector<int> a : m)
    {
        for(int b : a){
            cout << b << " ";
        }
        cout << endl;
    }
    
    //QUERIES
    while (q--)
    {
        int i,j;
    }
    
    

}