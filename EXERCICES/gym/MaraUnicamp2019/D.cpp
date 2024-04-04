#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int main(){
    fastio;
    int n,m; cin >> n >> m;
    vector v(n, vector<int> (m));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> v[i][j];
        }
    }

    cout << n << " " << n << " " << n << " " << m << endl;


    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j){
                cout << 1 << " ";
            }else{
                cout << 0 << " ";
            }
        }
        cout << endl;
    }

    cout << endl;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << v[i][j] << " ";
        }
        cout << endl;   
    }

}