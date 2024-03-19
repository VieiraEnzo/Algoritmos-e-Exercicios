#include <bits/stdc++.h>
#pragma GCC optimize("pragv")
using namespace std;
#define endl "\n"
#define fastio cin.tie(nullptr), ios_base::sync_with_stdio(false)
typedef long long ll;
int maxn = 1e5 + 5;

int main(){
    fastio;
    int n, q; cin >> n >> q;
    vector<set<int>> beg(maxn);
    vector<int> CanArrive(maxn);

    while (q--)
    {
        int l , r; cin >> l >> r;
        beg[l].insert(r);
        if(l == 1) CanArrive[1] = 1;
    }


    for(int i = 1; i <=n; i++){
        if(CanArrive[i]){
            for(auto a : beg[i]){
                CanArrive[a+1] = 1;
            }
        }
    }

    if(CanArrive[n+1]){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    

}